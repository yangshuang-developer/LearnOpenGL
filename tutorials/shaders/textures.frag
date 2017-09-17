#version 330 core 
out vec4 FragColor;

in vec3 outColor;
in vec2 TexCoord;

uniform sampler2D u_tex;

void main(){
	FragColor = texture2D(u_tex,TexCoord);
	// gl_FragColor = vec4(1.0,0,0,1.0);
}