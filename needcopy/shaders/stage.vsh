#version 330 core

layout (location = 0) in vec3 point; // 顶点

uniform float sWidth;	// 屏幕宽度
uniform float sHeight;	// 屏幕高度

void main()
{
	float ratio = sWidth / sHeight;
	gl_Position = vec4(point.x/ratio,point.y,point.z,1.0);
}
