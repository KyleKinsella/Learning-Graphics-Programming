//~ #ifdef GL_ES
//~ precision mediump float;
//~ #endif

uniform vec2 u_resolution;

uniform vec3 color;

void main() {
	
	//~ float width = 230.0f;
	//~ float height = 220.0f;
	//~ float total = width + height;
	
	vec2 st = gl_FragCoord.xy/u_resolution;
	//~ vec2 st = gl_FragCoord.xy/width/height;
	vec3 canvas = vec3(1.0);
	float circle = 0.0;
	
	circle = distance(st, vec2(0.5));

	circle = smoothstep(0.9, 0.903, 1.0 - circle);

	canvas = canvas * circle;

	//~ gl_FragColor = vec4(canvas, 1.0);
	gl_FragColor = vec4(color * canvas, 1.0);
	//~ gl_FragColor = color;
}
