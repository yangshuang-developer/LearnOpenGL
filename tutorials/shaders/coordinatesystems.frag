#version 330 core 
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D u_tex0;
uniform sampler2D u_tex1;

void main(){
	FragColor = mix(texture(u_tex0, TexCoord), texture(u_tex1, TexCoord),0.45);
}