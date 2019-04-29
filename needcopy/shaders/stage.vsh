#version 330 core
layout (location = 0) in vec3 in_point; // 顶点

uniform float sWidth;	// 屏幕宽度
uniform float sHeight;	// 屏幕高度
uniform float clock;	// 时钟

out vec4 color;

#define PI (3.1415926535897932384626433832795)
#define PI_H (1.5707963267948966192313216916398)
#define SIN45 (0.70710678118654752440084436210485)

void main()
{
	float ratio = sWidth / sHeight;
	float scale = 1; //(sin(clock*2)+1)/2;
	float rot = radians(clock*6);
	vec3 point = in_point;

	if(point.x == 1.0 && point.y == 1.0)
	{
		point.x = sin(rot);
		point.y = sin(rot+PI_H);
	}else if(point.x == 1.0 && point.y == -1.0)
	{
		point.x = sin(rot+PI_H);
		point.y = sin(rot+PI);
	}else if(point.x == -1.0 && point.y == -1.0)
	{
		point.x = sin(rot-PI);
		point.y = sin(rot-PI_H);
	}else if(point.x == -1.0 && point.y == 1.0)
	{
		point.x = sin(rot-PI_H);
		point.y = sin(rot);
	}
	point.xy /= SIN45;
	color = vec4(0,0,0,0.5);
	gl_Position = vec4(point.x/ratio * scale,point.y * scale,point.z,1.0);
}
