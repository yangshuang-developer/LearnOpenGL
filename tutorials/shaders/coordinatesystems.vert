#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main(){
	TexCoord = aTexCoord;
	gl_Position = u_model*u_view*u_proj*vec4(aPos,1.0);
}