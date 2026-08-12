#version 330 core

layout (location = 0) out vec4 color;

void main() {
	vec2 uv = gl_FragCoord.xy;
	vec3 canvas = vec3(0.0);
	
	float circle = 1.0 - smoothstep(12.0, 50.0, distance(uv, vec2(245.0, 345.0)));
	
	float c1 = 1.0 - smoothstep(25.0, 80.0, distance(uv, vec2(120.0, 500.0))); // red
	float c2 = 1.0 - smoothstep(2.0, 5.0, distance(uv, vec2(640.0, 320.0))); // purple
	float c3 = 1.0 - smoothstep(20.0, 23.0, distance(uv, vec2(210.0, 80.0))); // pink
	
	canvas += vec3(1.0, 0.0, 0.0) * c1 + vec3(0.65, 0.56, 1.0) * c2 + vec3(1.0, 0.55, 0.76) * c3 + vec3(1.0, 1.0, 1.0) * circle;
	
	color = vec4(canvas, 1.0);
}
