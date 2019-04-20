#version 330 core

layout (position = 0) in vec3 point; // 顶点

uniform float ratio;

void main()
{
	gl_Position = vec4(point.x/ratio,point.y,point.z,1.0);
}
