#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

//~ layout(location = 1) in vec3 aColor;
//~ layout(location = 2) in vec2 aTexCoord;

//~ out vec3 ourColor;
//~ out vec2 TexCoord;

out vec2 u_TexCoord;

uniform mat4 u_MVP;

void main() {
   //~ gl_Position = u_MVP * vec4(position, 0.0, 1.0);
   gl_Position = u_MVP * position;
   //~ gl_Position = position;
   //~ gl_Position = position;
   u_TexCoord = texCoord;
   
   //~ gl_Position = vec4(position, 1.0);
   //~ ourColor = aColor;
   //~ TexCoord = aTexCoord;
}
