#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

in vec2 u_TexCoord;

void main() {
	vec4 texCoord = texture(u_Texture, u_TexCoord);
	color = texCoord;
}
