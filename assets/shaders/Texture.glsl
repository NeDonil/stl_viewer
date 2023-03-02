#type vertex
#version 330 core
layout (location = 0) in vec3 a_Position;
		
void main()
{
	gl_Position = vec4(a_Position, 1.0f);
}		

#type fragment
#version 330 core

out vec4 color;


void main()
{
	color = vec4(0.2, 0.8, 0.5, 1.0);
}		
		