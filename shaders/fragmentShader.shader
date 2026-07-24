#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main() {
	// our vec4 is made up of the following: red color, green color, blue color (RGB) and alpha.
	
	// we are setting our output color (of each fragment for each pixel on our rectangle) to be the value of whatever the value of 'u_Color' is set to be
	color = u_Color;
}
