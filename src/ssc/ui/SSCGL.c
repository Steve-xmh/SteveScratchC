#include "SSCGL.h"

static struct{
	GMutex mutex; // 如果要交换位图数据的话
	GPtrArray *stage;
	GPtrArray *sprites;
} sscRenderList;

static gchar *ssc_gl_render;
static gchar *ssc_gl_vendor;
static gchar *ssc_gl_version;

typedef struct
{
	GLuint m; 	/**< 链接到一起的着色器引用 */
	GLuint v;	/**< 顶点着色器引用 */
	GLuint f;	/**< 片段着色器引用 */
	GLuint g;	/**< 几何着色器引用 */
}sscGLShader; /**< 着色器结构，存储所有的着色器引用 */
static sscGLShader ssc_stage_shader;

static GLuint VBO;
static GLuint VAO;
static gfloat verts[]={
	-1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,

      1.0f, 1.0f, 0.0f,
     -1.0f, 1.0f, 0.0f,
     -1.0f,-1.0f, 0.0f
};

static gboolean ssc_ui_gl_load_shader(GLuint *shader, gchar *fileName); /**< 加载着色器到句柄，否则输出错误到标准输出 */

static gboolean ssc_ui_gl_load_shader(GLuint *shader, gchar *fileName)
{
	if(!shader || !fileName)
	{
		error("[GL]Error in loading shader: Invalid shader pointer or file name.\n");
		return FALSE;
	}
	GLenum shaderType = 0;
	size_t len = strlen(fileName);

	// 检测着色器类型
	if(g_strcmp0(fileName+len-4,".vsh") == 0) // 顶点
	{
		shaderType = GL_VERTEX_SHADER;
	}else if(g_strcmp0(fileName+len-4,".fsh") == 0) // 片段
	{
		shaderType = GL_FRAGMENT_SHADER;
	}else if(g_strcmp0(fileName+len-4,".gsh") == 0) // 几何
	{
		shaderType = GL_GEOMETRY_SHADER;
	}else
	{
		error("[GL]Unknown shader file type: %s\n",fileName);
		return FALSE;
	}

	FILE *f = fopen(fileName,"rb");

	if(!f)					{error("[GL]Can't open shader file %s\n",fileName);return FALSE;}
	if(fseek(f,0,SEEK_END))	{error("[GL]Can't read shader file %s\n",fileName);fclose(f);return FALSE;}

	long size = ftell(f);
	GLchar *data = (gchar*)calloc(size,sizeof(gchar));

	if(!data)				{error("[GL]No enough memory to load file %s\n",fileName);fclose(f);return FALSE;}
	if(fseek(f,0,SEEK_SET))	{error("[GL]Can't read shader file %s\n",fileName);fclose(f);return FALSE;}
	fread(data,size,1,f);
    fclose(f);
    // 读取完文件了

	*shader = glCreateShader(shaderType);

	glShaderSource(*shader,1,(const GLchar**)&data,NULL);
	glCompileShader(*shader);

	// free(data); // ?

	int suc;char infoLog[512];
	glGetShaderiv(*shader,GL_COMPILE_STATUS,&suc);
	if(!suc)
	{
		glGetShaderInfoLog(*shader,512,NULL,infoLog);
		error("[GL]Can't compile shader %s :\n%s\n",fileName,infoLog);

		glDeleteShader(*shader);
		*shader = 0;
        return FALSE;
	}

	// glDeleteShader(*shader);
	info("[GL]Loaded %d shader file: %s\n",shaderType,fileName);

	return TRUE;
}

// "realize"
void ssc_ui_gl_init(GtkWidget *area)
{
	info("[GL]Initialing GLArea!\n");
	gtk_gl_area_make_current(GTK_GL_AREA(area));

	if (gtk_gl_area_get_error (GTK_GL_AREA(area)) != NULL)
	{
		error("There is something wrong on initialing OpenGL.\n");
		return;
	}

	ssc_gl_render  = (gchar*)glGetString(GL_RENDERER);
	ssc_gl_vendor  = (gchar*)glGetString(GL_VENDOR);
	ssc_gl_version = (gchar*)glGetString(GL_VERSION);

	info("[GL]OpenGL Log:\n");
	info("[GL]OpenGL renderer: %s\n",ssc_gl_render);
	info("[GL]OpenGL vendor: %s\n",ssc_gl_vendor);
	info("[GL]OpenGL version: %s\n",ssc_gl_version);

	sscRenderList.sprites = g_ptr_array_new();
	sscRenderList.stage = g_ptr_array_new();
	g_mutex_init(&(sscRenderList.mutex));

	// 着色器
	if(!ssc_ui_gl_load_shader(&(ssc_stage_shader.v),"./shaders/stage.vsh")){g_error("Failed to load shader!"); return;}
	if(!ssc_ui_gl_load_shader(&(ssc_stage_shader.f),"./shaders/stage.fsh")){g_error("Failed to load shader!"); return;}

	ssc_stage_shader.m = glCreateProgram();
	glAttachShader(ssc_stage_shader.m,ssc_stage_shader.v);
	glAttachShader(ssc_stage_shader.m,ssc_stage_shader.f);
	glLinkProgram(ssc_stage_shader.m);

	int suc;
	glGetProgramiv(ssc_stage_shader.m, GL_LINK_STATUS, &suc);
	if(!suc)
	{
		gchar infoLog[512];
		glGetProgramInfoLog(ssc_stage_shader.m, 512, NULL, infoLog);
		g_error("Failed to link shader:\n%s",infoLog);
	}

	glDeleteShader(ssc_stage_shader.v);
	glDeleteShader(ssc_stage_shader.f);

	// 顶点缓冲
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1,&VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GLfloat),(void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);

	info("[GL]GLArea Ready!\n");
}

void ssc_ui_gl_destory(GtkWidget *area)
{
    g_ptr_array_free(sscRenderList.sprites,TRUE);
    g_ptr_array_free(sscRenderList.stage,TRUE);
}

gboolean ssc_ui_gl_draw(GtkWidget *area,GdkGLContext *context)
{
    // 开始 GL 操作
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear (GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glUseProgram(ssc_stage_shader.m);
	glBindVertexArray(VAO);

	int sWidthLocation = glGetUniformLocation(ssc_stage_shader.m,"sWidth");
	int sHeightLocation = glGetUniformLocation(ssc_stage_shader.m,"sHeight");
	GLfloat w,h;
	w = gtk_widget_get_allocated_width(area);
	h = gtk_widget_get_allocated_height(area);
	glUniform1f(sWidthLocation,w);
	glUniform1f(sHeightLocation,h);
	glDrawArrays(GL_TRIANGLES,0,6);

	return TRUE;
}
