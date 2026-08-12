//~ #version 330 core


//~ #ifdef GL_ES
//~ precision mediump float;
//~ precision highp float;
//~ #endif


//~ #include 
//~ #include "../vendors/glm/glm.hpp"


//~ layout (location = 0) out vec3 fragColor;



//~ uniform vec2 u_resolution;


//~ in highp vec4 gl_FragCoord;

//~ uniform vec3 color;

//~ uniform Ball[] balls;

//~ glm::vec3 createCircle(glm::vec2 position, glm::vec3 color, float size) {
	//~ float circle = sqrt(pow(position.x, 2.0) + pow(position.y), 2.0));
	//~ circle = smoothstep(size, size + 0.003, 1.0 - circle);
	
	//~ return color * circle;
//~ }



//~ void createCircle() {
	//~ float circle = 0.0;
	//~ circle = distance(uv, vec2(0.5));
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);

	//~ canvas *= circle;	
//~ }








// works:
vec3 createCircle(vec2 position, vec3 color, float size) {
	float circle = sqrt(pow(position.x, 2.0) + pow(position.y, 2.0));
	circle = smoothstep(size, size + 0.003, 1.0 - circle);
	
	return color * circle;
}



//~ vec3 createCircle(vec2 position, vec3 color, float radius) {
    //~ float d = length(position);                 // distance from center
    //~ float a = 1.0 - smoothstep(radius, radius + 0.003, d);
    //~ return color * a;
//~ }





//~ vec3 createCircle(vec2 position, vec3 color, float radius) {
    //~ float d = length(position);
    //~ float a = 1.0 - smoothstep(radius, radius + 0.003, d);
    //~ return color * a;
//~ }



//~ vec3 createCircle(vec2 p, vec3 color, float radius) {
    //~ float d = distance(p, vec2(0.0));
    //~ float a = 1.0 - smoothstep(radius, radius + 0.01, d);
    //~ return color * a;
//~ }


//~ vec3 createCircle(vec2 position, vec3 color, float radius) {
    //~ float circle = length(position);
    //~ float d = smoothstep(radius, radius - 1.0, circle);
	
	//~ return color * d;
//~ }





//~ vec3 createCircle(vec2 position, vec3 color, float radius) {
    //~ float d = length(position);
    //~ float thickness = 0.01; // adjust
    //~ float circle = 1.0 - smoothstep(radius, radius + thickness, d);
    //~ return color * circle;



//~ vec3 createCircle(vec2 uv, vec2 pos, vec3 color, float radius) {
    //~ float circle = distance(uv, vec2(0.5));
	
    //~ float thickness = 0.005; // adjust
	//~ circle = smoothstep(pos.x, pos.x + pos.y, 1.0 - circle);
        
    //~ return color * circle;
//~ }

//~ vec2



//~ , float thickness
//~ vec3 createCircle(vec2 uv, vec3 color, float radius) {
    //~ float circle = distance(uv, vec2(0.5));
	
    //~ float thickness = 0.005; // adjust
	//~ float fade = 1.5;
    //~ thickness += fade;
    
	//~ float distance = 1.0 - length(uv);

	//~ vec3 col = vec3(smoothstep(0.0, fade, distance));   
    //~ col *= vec3(smoothstep(thickness + fade, thickness, distance));

    //~ fragColor.rgb = col * color;
    
    
	//~ circle = smoothstep(radius, radius + thickness, 1.0 - circle);
        
    //~ return color * circle;
//~ }

//~ out vec4 color;

//~ void main2() {
    //~ vec2 uv = (gl_FragCoord.xy * 2.0 - u_resolution) / min(u_resolution.x, u_resolution.y);

    //~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.35);
    //~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.0), 0.35);
    //~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.0, 0.548, 0.757), 0.35);

    //~ vec3 canvas = c1 + c2 + c3;
    //~ gl_FragColor = vec4(canvas, 1.0);
//~ }

//~ uniform vec2 resolution;

//~ void main3(void) {
    //~ vec2 uv = gl_FragCoord.xy / u_resolution; // Normalized coordinates
    //~ gl_FragColor = vec4(uv, 0.0, 1.0); // Output color based on normalized coordinates
//~ }

//~ out vec4 color;

//~ void main4() {
    // Use gl_FragCoord directly for full viewport access
    //~ vec2 pixelCoords = gl_FragCoord.xy; // This gives you the pixel coordinates
    // Set the fragment color based on its position
    //~ gl_FragColor = vec4(pixelCoords.x / u_resolution.x, pixelCoords.y / u_resolution.y, 0.0, 1.0); // Example for a 800x600 window
    
    //~ gl_FragColor = vec4(pixelCoords.x / 1066.0, pixelCoords.y / 600.0, 0.0, 1.0); // Example for a 800x600 window
    
    //~ color = vec4(pixelCoords.x / 1066.0, pixelCoords.y / u_resolution.y, 600.0, 1.0); // Example for a 800x600 window
    
    //~ gl_FragColor = vec4(pixelCoords.x / 800.0, pixelCoords.y / 600.0, 0.0, 1.0); // Example for a 800x600 window



//~ }



//~ #version 330 core

//~ out vec4 color;

//~ 2 || 3 || 4
void main() {



	//~ vec2 uv = gl_FragCoord.xy/u_resolution;	// * 2.0 - 1.0;	
	
	
	
	vec2 uv = gl_FragCoord.xy;
	
	
	
	
	//~ vec2 uv = gl_FragCoord.xy;
	//~ gl_FragColor = vec4(uv, 0.0, 1.0);
	
	
	
	
	//~ vec3 canvas = vec3(1.0);
	
	//~ vec3 canvas = vec3(0.0);

	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);
	
	//~ vec2(320.0, 240.0)

	//~ float circle = distance(uv, vec2(320.0, 240.0));
	//~ circle = smoothstep(50.0, 50.003, circle);



	//~ vec2 uv = gl_FragCoord.xy;



	// works:
	vec3 canvas = vec3(0.0);

	float c1 = 1.0 - smoothstep(25.0, 80.0, distance(uv, vec2(120.0, 500.0))); // red
	float c2 = 1.0 - smoothstep(2.0, 5.0, distance(uv, vec2(640.0, 320.0))); // purple
	float c3 = 1.0 - smoothstep(20.0, 23.0, distance(uv, vec2(210.0, 80.0))); // pink

	canvas += vec3(1.0, 0.0, 0.0) * c1 + vec3(0.65, 0.56, 1.0) * c2 + vec3(1.0, 0.55, 0.76) * c3;
	
	//~ canvas += vec3(1.0, 0.0, 0.0) * c1;
	//~ canvas += vec3(0.65, 0.56, 1.0) * c2;
	//~ canvas += vec3(1.0, 0.55, 0.76) * c3;

	gl_FragColor = vec4(canvas, 1.0);






	//~ vec3 c1 = createCircle(
		//~ uv - vec2(160.0, 165.0),
		//~ vec3(1.0, 0.0, 0.0),
		//~ 50.0
	//~ );

	//~ vec3 c2 = createCircle(
		//~ uv - vec2(330.0, 240.0),
		//~ vec3(0.654, 0.560, 1.0),
		//~ 50.0
	//~ );

	//~ vec3 c3 = createCircle(
		//~ uv - vec2(500.0, 350.0),
		//~ vec3(1.0, 0.548, 0.757),
		//~ 50.0
	//~ );


	//~ canvas *= c1 + c2 + c3;

	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	//~ gl_FragColor = vec4(gl_FragCoord.x / 640.0, gl_FragCoord.y / 480.0, 0.0, 1.0);





	 //~ color = vec4(
		//~ gl_FragCoord.x / 1066.0,
		//~ gl_FragCoord.y / 600.0,
		//~ 0.0,
		//~ 1.0
	//~ );














	
	//~ float d = distance(uv, vec2(320.0, 240.0));
	//~ float circle = 1.0 - smoothstep(50.0, 51.0, d);


	//~ gl_FragColor = vec4(circle, circle, circle, 1.0);
	

	//~ vec2 uv = gl_FragCoord.xy;

	//~ float c1 = 1.0 - smoothstep(
		//~ 49.0,
		//~ 50.0,
		//~ distance(uv, vec2(160.0, 165.0))
	//~ );

	//~ float c2 = 1.0 - smoothstep(
		//~ 49.0,
		//~ 50.0,
		//~ distance(uv, vec2(320.0, 240.0))
	//~ );

	//~ float c3 = 1.0 - smoothstep(
		//~ 49.0,
		//~ 50.0,
		//~ distance(uv, vec2(500.0, 350.0))
	//~ );

	//~ vec3 canvas = vec3(1.0);

	//~ canvas = mix(canvas, vec3(1,0,0), c1);
	//~ canvas = mix(canvas, vec3(0.654,0.560,1), c2);
	//~ canvas = mix(canvas, vec3(1,0.548,0.757), c3);

	//~ gl_FragColor = vec4(canvas, 1.0);































	//~ vec3 c1 = createCircle(
		//~ uv - vec2(160.0, 165.0),
		//~ vec3(1.0, 0.0, 0.0),
		//~ 50.0
	//~ );


	//~ vec3 c1 = createCircle(
		//~ uv - vec2(250.0, 345.0),
		//~ vec3(1.0, 0.0, 0.0),
		//~ 9.0
	//~ );

	//~ vec3 c2 = createCircle(
		//~ uv - vec2(330.0, 240.0),
		//~ vec3(0.654, 0.560, 1.0),
		//~ 50.0
	//~ );

	//~ vec3 c3 = createCircle(
		//~ uv - vec2(580.0, 385.0),
		//~ vec3(1.0, 0.548, 0.757),
		//~ 50.0
	//~ );

	//~ canvas *= circle + c1 + c2 + c3;	
	
	
	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ vec3 circle = createCircle(uv -  vec2(0.250, 0.345), vec3(1.0, 0.0, 1.0), 0.9);
	
	//~ vec3 c1 = createCircle((uv.x * uv.y * 2.0) - vec2(0.150, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	
	
	
	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	//~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.000), 0.9); // purple
	//~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.000, 0.548, 0.757), 0.9); // pink
	
	//~ canvas *= circle + c1 + c2 + c3;
	
	
	
	
	//~ canvas *= circle + c1;;
	
	
	
	
	
	//~ gl_FragColor = vec4(uv.x * canvas, 1.0);
	
	
	//~ gl_FragColor = vec4(canvas, 1.0);






    //~ gl_FragColor = vec4(uv.x / 1066.0, uv.y / 600.0, 0.0, 1.0); // Example for a 800x600 window
    
    
    
    
    
    
    
    
    
    //~ gl_FragColor = vec4((canvas * u_resolution.x) / u_resolution.x, (canvas * u_resolution.y) / u_resolution.y, 0.0, 1.0); // Example for a 800x600 window
    



















    //~ gl_FragColor = vec4(pixelCoords.x / u_resolution.x, pixelCoords.y / u_resolution.y, 0.0, 1.0); // Example for a 800x600 window
	
	//~ gl_FragColor = vec4(uv.x / u_resolution.x, ux.y / u_resolution.y, 0.0, 1.0);






































































































    //~ vec2 uv = (gl_FragCoord.xy * 4.0 - u_resolution) / min(u_resolution.x, u_resolution.y);


	
	//~ vec2 uv = (gl_FragCoord.xy * 2.0 - u_resolution) / min(u_resolution.x, u_resolution.y);
	//~ vec2 uv = (gl_FragCoord.xy * 2.0 - u_resolution) / min(u_resolution.x, u_resolution.y);

	
	//~ float r = 0.35; // choose radius in these corrected units

	//~ float circle = 1.0 - smoothstep(r, r+0.01, distance(uv, vec2(0.0)));
	
	//~ vec3 canvas = vec3(1.0);
	//~ vec3 canvas = vec3(0.0);

	//~ uv.x += 450;
	//~ uv.y += 200;

    //~ float apsect = iResolution.x / iResolution.y;
	//~ uv.x *= apsect;

	//~ float circle = 0.0;

	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);

	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	
	
	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.08);

	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	//~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.000), 0.9); // purple
	//~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.000, 0.548, 0.757), 0.9); // pink
	
	//~ canvas *= circle + c1 + c2 + c3;
	
	//~ canvas += createCircle(uv - vec2(-0.250, -0.155), vec3(1.0, 0.0, 0.0), 0.45); // red
	//~ canvas += createCircle(uv - vec2(-0.170,  0.000), vec3(0.654, 0.560, 1.0), 0.45); // purple
	//~ canvas += createCircle(uv - vec2( 0.080, -0.125), vec3(1.0, 0.548, 0.757), 0.45); // pink
	
	//~ canvas += c1 + c2 + c3;
	//~ gl_FragColor = vec4(canvas, 1.0);
	//~ gl_FragColor = vec4(c1, 1.0 );



































































































	//~ color = vec4(canvas, 1.0);
	
	
	
	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	// * 2.0;
	
	//~ * 2.0 - 1.0;
    //~ float apsect = iResolution.x / iResolution.y;
    //~ uv.x *= apsect;
    
	
	//~ vec3 canvas = vec3(1.0);

	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);

	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	//~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.000), 0.9); // white?
	//~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.000, 0.548, 0.757), 0.9); // pink
	
	//~ canvas *= circle + c1 + c2 + c3;
	//~ gl_FragColor = vec4(canvas, 1.0);



























































































































































































	///u_resolution;	// * 2.0 - 1.0;
	//~ u_resolution = vec2(640.0, 480.0)
	
	//~ float apsect = iResolution.x / iResolution.y;
    //~ uv.x *= apsect;	// * 2.0f * 1.0f;


	//~ vec3 canvas = vec3(1.0);

	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);

	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	//~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.000), 0.9); // white?
	//~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.000, 0.548, 0.757), 0.9); // pink

	//~ float c1 = createCircle(uv - vec2(0.250, 0.345), 50.0);
	//~ float c2 = createCircle(uv - vec2(0.330, 0.500), 50.0);
	//~ float c3 = createCircle(uv - vec2(0.580, 0.385), 50.0);

	//~ canvas *= circle + c1 + c2 + c3;

	//~ gl_FragColor = vec4(canvas * c1, 1.0);
	
	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ vec2 uv = gl_FragCoord.xy;

//~ vec3 canvas = vec3(1.0);

//~ canvas += createCircle(
    //~ uv - vec2(160.0, 165.0),
    //~ vec3(1.0, 0.0, 0.0),
    //~ 50.0
//~ );

//~ canvas += createCircle(
    //~ uv - vec2(250.0, 240.0),
    //~ vec3(0.654, 0.560, 1.0),
    //~ 50.0
//~ );

//~ canvas += createCircle(
    //~ uv - vec2(400.0, 180.0),
    //~ vec3(1.0, 0.548, 0.757),
    //~ 50.0
//~ );

//~ gl_FragColor = vec4(canvas, 1.0);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ vec2 uv = gl_FragCoord.xy;

	//~ vec3 canvas = vec3(1.0);

	//~ float c1 = createCircle(
		//~ uv - vec2(160.0, 165.0),
		//~ vec3(1.0, 0.0, 0.0),
		//~ 50.0
	//~ );

	//~ float c2 = createCircle(
		//~ uv - vec2(250.0, 240.0),
		//~ vec3(1.0, 0.0, 0.0),
		//~ 50.0
	//~ );

	//~ float c3 = createCircle(
		//~ uv - vec2(400.0, 180.0),
		//~ vec3(1.0, 0.0, 0.0),
		//~ 50.0
	//~ );

	//~ canvas = vec3(1.0) - (c1 + c2 + c3);

	//~ gl_FragColor = vec4(canvas, 1.0);

	
	
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);
































































	//~ vec3 c1 = createCircle(uv - vec2(0.350, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	
	//~ vec3 c1 = createCircle(uv, uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	
	//~ vec3 c1 = createCircle(uv - vec2(0.250, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	
	//~ vec3 c1 = createCircle(uv, vec3(1.0, 0.0, 0.0), 0.9, 0.005); // red
	//~ vec3 c1 = createCircle(uv, vec3(1.0, 0.0, 0.0), 0.9); // red
	
	//~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.000), 0.9); // white?
	
	//~ vec3 c2 = createCircle(uv, vec3(0.654, 0.560, 1.000), 0.9); // white?
	
	//~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.000, 0.548, 0.757), 0.9); // pink
	
	//~ vec3 c3 = createCircle(uv, vec3(1.000, 0.548, 0.757), 0.9); // pink
	
	//~ canvas *= circle + c1 + c2 + c3;
	//~ canvas *= c1 + c2 + c3;

	//~ gl_FragColor = vec4(canvas, 1.0);
	
	//~ gl_FragColor = vec4(canvas, 1.0);
















































	//~ canvas *= circle;	// + c1 + c2 + c3;
































	//~ vec2 uv = gl_FragCoord.xy/u_resolution;// * 2.0;// - 1.0;

































































	//~ uv.y = 1.0 - uv.y;
	
	//~ vec3 canvas = vec3(u_resolution.x);
	//~ vec3 canvas = vec3(1.0);
		
	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.980, 1.0 - circle);
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);
	
	//~ vec3 c1 = createCircle(uv - vec2(0.380, 0.345), vec3(0.888, 1.000, 0.307), 0.9); // yellow
	
	//~ float aspect = u_resolution.x / u_resolution.y;
	//~ uv.x *= apsect;	// * 2.0f * 1.0f;
	
	//~ vec2 q = uv - vec2(0.350, 0.345);
	//~ q.x *= aspect; // or q.x /= aspect depending on which direction you want
	//~ vec3 c1 = createCircle(q, vec3(1.0,0.0,0.0), 0.9);


	//~ vec2 p = uv - vec2(0.350, 0.345);
	//~ p.x *= aspect;

	
	//~ vec3 c1 = createCircle(p, vec3(1.0, 0.0, 0.0), 0.9);

	
	//~ vec3 c1 = createCircle(uv - vec2(0.350, 0.345), vec3(1.0, 0.0, 0.0), 0.9); // red
	
	//~ vec3 c2 = createCircle(uv - vec2(0.330, 0.500), vec3(0.654, 0.560, 1.000), 0.9); // white?
	
	//~ vec3 c3 = createCircle(uv - vec2(0.580, 0.385), vec3(1.000, 0.548, 0.757), 0.9); // pink
	
	//~ canvas *= color + circle + c3;
	//~ canvas *= circle + c3;
	
	//~ canvas *= circle + c1 + c2 + c3;
	
	//~ canvas *= circle + c1 + c3 + color;
	
	//~ canvas *= circle - c1 - c3;
	
	//~ canvas *= circle + c1 + c3;
	
	//~ canvas *= u_resolution + circle + c1 + c2 + c3;
	//~ canvas *= circle + c1 + c2 + c3;
	//~ canvas *= c2 + c3;
	
	//~ canvas *= c1 + c3;
	
	//~ canvas *= circle + c1 + c3;
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);
	//~ gl_FragColor = vec4(u_resolution * canvas, 1.0);
	//~ gl_FragColor = vec4(canvas, 1.0);



















//~ vec3 createCircle(vec2 position, vec3 color, float size) {
	//~ float circle = sqrt(pow(position.x, 2.0) + pow(position.y, 2.0));
	//~ circle = smoothstep(size, size + 0.003, 1.0 - circle);
	
	//~ return color * circle;
//~ }

	
	//~ float width = 230.0f;
	//~ float height = 220.0f;
	//~ float total = width + height;


	//~ vec2 st = gl_FragCoord.xy/width/height;

	
	//~ vec2 uv = gl_FragCoord.xy/u_resolution;
	//~ vec3 canvas = vec3(1.0);
		
	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);
	//~ canvas *= circle;
	//~ gl_FragColor = vec4(color * canvas, 1.0);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ vec3 canvas = vec3(0.0);
	
	//~ float circle1 = 0.0;
	//~ float circle = 0.0;
	//~ float circle1 = distance(uv, vec2(0.5));
	//~ float circle = distance(uv, vec2(0.5));
	
	//~ float circle = distance(uv, vec2(0.5));	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);
	//~ gl_FragColor = vec4(color * canvas, 1.0);

	
	//~ float d1 = distance(uv, vec2(0.5, 0.5));
	//~ float circle1 = smoothstep(0.48, 0.50, 1.0 - d1);
	//~ circle1 = smoothstep(0.9, 0.903, 1.0 - circle);
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);
	//~ canvas *= circle1;	
	
		//~ gl_FragColor = vec4(color * canvas, 1.0);


	//~ float circle2 = 0.0;
	//~ float circle2 = distance(uv, vec2(50.0));
	//~ float d2 = distance(uv, vec2(0.2, 0.5));
	//~ float circle2 = distance(uv, vec2(50.0));
	//~ float circle2 = smoothstep(0.18, 0.20, 1.0 - d2);
	//~ canvas *= circle1 + circle2;	
	
	//~ canvas *= (circle1 + circle2);
	
	//~ canvas += circle1 * color;
	//~ canvas += circle2 * color;
	
	//~ canvas += circle1 * circle2;

	//~ gl_FragColor = vec4(color * canvas, 0.1);
	//~ gl_FragColor = vec4(canvas, 0.1);
	//~ gl_FragColor = vec4(color * canvas, 1.0);
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);


	//~ canvas *= circle;
	
	//~ float thickness = 50.2;
    //~ float fade = 0.5;
    //~ thickness += fade;
  
	//~ vec3 col = vec3(smoothstep(0.0, fade, 1.0 - circle));   
    //~ col *= vec3(smoothstep(thickness + fade, thickness, circle));


	//~ gl_FragColor = vec4(col * color * canvas, 1.0);
	
	
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ createCircle();
	
	//~ gl_FragColor = createCircle();
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);

	
	//~ float circle = 0.0;
	
	//~ float circle1 = 0.0;
	//~ float circle2 = 0.0;
	//~ float circle3 = 0.0;
	
	
	
	
	//~ float anotherCircle = 0.0;
	
	//~ circle = distance(uv, vec2(0.5));
	
	//~ circle1 = distance(uv, vec2(0.5));
	//~ circle2 = distance(uv, vec2(0.2));
	//~ circle3 = distance(uv, vec2(2.0));
	
	
	
	//~ circle = distance(uv, vec2(0.5));
	
	
	
	//~ circle2 = distance(uv, vec2(0.2));
	
	//~ anotherCircle = distance(uv, vec2(1.5));

	
	//~ circle = smoothstep(0.4, 0.973, 1.0 - circle);

	
	//~ circle = smoothstep(0.9, 0.903, 1.0 - circle);
	
	
		
	
	
	
	
	//~ circle1 = smoothstep(0.9, 0.703, 1.0 - circle1);
	//~ circle2 = smoothstep(1.5, 1.503, 1.0 - circle2);
	//~ circle3 = smoothstep(2.9, 0.203, 1.0 - circle3);
	
	//~ anotherCircle = smoothstep(2.9, 1.903, 1.0 - anotherCircle);
	
	//~ canvas = canvas * circle * anotherCircle;
	
	//~ canvas = canvas * circle * circle2;	// * anotherCircle;
	
	
	//~ canvas = canvas * circle;	// * circle2;	// * anotherCircle;
	
	
	
	//~ canvas *= circle;	
	
	
	
	// * circle2;	// * anotherCircle;
	
	
	
	
	//~ canvas = canvas * circle1 * circle2 * circle3;	// * anotherCircle;

	//~ float 
	
	//~ float thickness = 5.2;
    //~ float fade = 0.005;
    //~ thickness += fade;
  
	//~ vec3 col = vec3(smoothstep(0.0, fade, 1.0 - circle));   
    //~ col *= vec3(smoothstep(thickness + fade, thickness, circle));

	//~ vec3 c1 = createCircle(uv - vec2(0.810, 0.770), vec3(0.888, 1.000, 0.307), 0.9);

	//~ gl_FragColor = vec3(color * c1 * canvas);
	//~ gl_FragColor = vec4(canvas * c1, 1.0);
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);
	
	//~ gl_FragColor = vec4(col * color * canvas, 1.0);
	
	
	//~ gl_FragColor = vec4(c1 * color * canvas, 1.0);
	
	//~ canvas = canvas * circle + c1;
	//~ canvas = canvas * circle * c1;

	
	//~ gl_FragColor = vec4(color * canvas * createCircle(uv - vec2(0.810, 0.770), vec3(0.888, 1.000, 0.307), 0.9), 1.0);
	
	//~ gl_FragColor = vec3(col * color);
	
	//~ fragColor.rgb = col * color * canvas;
	

	//~ fragColor.rgb = c1 + u_resolution;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ gl_FragColor = vec4(color*canvas*2*uv.xy, 2.0);

	
	//~ gl_FragColor = vec4(canvas, 1.0);

	//~ return;
	
	//~ vec2 pos1(0.810, 0.770);
	//~ vec2 pos2(0.220, 0.690);
	//~ vec2 pos3(0.500, 0.230);
	
	//~ vec3 c1(0.888, 1.000, 0.307);
	//~ vec3 c2(0.654, 0.560, 1.000);
	//~ vec3 c3(1.000, 0.548, 0.757);
	
	//~ const float size = 0.9;
	
	//~ float circle1 = uv - sqrt(pow(pos1.x, 2.0) + pow(pos1.y), 2.0));
	//~ circle1 = smoothstep(size, size + 0.003, 1.0 - circle1);	
	//~ color * circle1;
	//~ color * c1;
	
	//~ float circle2 = uv - sqrt(pow(pos2.x, 2.0) + pow(pos2.y), 2.0));
	//~ circle2 = smoothstep(size, size + 0.003, 1.0 - circle2);
	//~ color * circle2;
	//~ color * c2;

	//~ float circle3 = uv - sqrt(pow(pos3.x, 2.0) + pow(pos3.y), 2.0));
	//~ circle3 = smoothstep(size, size + 0.003, 1.0 - circle3);
	//~ color * circle3;
	//~ color * c3;
	
	//~ canvas += circle + circle1 + circle2 + circle3;
	
	
	//~ canvas += circle1 + circle2 + circle3;
	
	
	//~ canvas += c1 + c2 + c3;
	
	//~ canvas += circle1;
	
	//~ gl_FragColor = vec4(canvas * color, 1.0);
	//~ gl_FragColor = vec4(canvas, 1.0);

	//~ for (Ball ball : balls) {
		// compute each balls feilds
	//~ }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//~ glm::vec3 c1 = createCircle(uv - glm::vec2(0.810, 0.770), glm::vec3(0.888, 1.000, 0.307), 0.9);
	
	//~ vec3 c1 = createCircle(uv - vec2(0.810, 0.770), vec3(0.888, 1.000, 0.307), 0.9);
	
	//~ glm::vec3 c2 = createCircle(uv - glm::vec2(0.220, 0.690), glm::vec3(0.654, 0.560, 1.000), 0.9);
	//~ glm::vec3 c3 = createCircle(uv - glm::vec2(0.500, 0.230), glm::vec3(1.000, 0.548, 0.757), 0.9);
	
	//~ vec3 circle2 = createCircle(uv - vec2(0.810, 0.770), vec3(0.888, 1.000, 0.307), 0.9);
	
	//~ vec3 c1 = createCircle(uv - vec2(0.810, 0.770), vec3(0.888, 1.000, 0.307), 0.9);
	
	//~ vec3 circle3 = createCircle(uv - vec2(0.220, 0.690), vec3(0.654, 0.560, 1.000), 0.9);
	//~ vec3 circle4 = createCircle(uv - vec2(0.500, 0.230), vec3(1.000, 0.548, 0.757), 0.9);

	//~ canvas += color + c1 + c2 + c3;
	
	
	//~ canvas += color + c1;// + c2 + c3;
	
	//~ canvas += color + c1;
	
	
	//~ canvas *= color + c1;
	
	
	
	
	// + c2 + c3;
	
	
	//~ canvas += color + circle + cl;
	
	//~ gl_FragColor = vec4((color * canvas) + c1 + circle, 1.0);
	
	
	//~ gl_FragColor = c1 * uv.x * circle;
	
	
	//~ gl_FragColor = color * c1 * uv.x * circle;
	
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);
	
	//~ canvas += circle + c1 + uv.xy;
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);

	
	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	
	
	//~ vec4((color * canvas) + c1 + circle, 1.0);
	
	
	//~ canvas *= color + c1 + c2 + c3;

	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	//~ canvas = (canvas * c1) + circle * 4;
	
	//~ gl_FragColor = vec4(color * canvas * c1, 1.0);
	
	
	// * anotherCircle;
	
	
	
	
	//~ gl_FragColor = vec4(color * canvas * circle1, 1.0);
	
	
	
	//~ canvas += color + circle2 + circle3 + circle4;
	//~ canvas += circle2 + circle3 + circle4;
	
	//~ gl_FragColor = vec4(color * canvas, 1.0);
	//~ gl_FragColor = vec4(color, 1.0 );
	
	
	
	
	//~ gl_FragColor = vec4(canvas + color * canvas - color, 1.0);




	
	//~ gl_FragColor = vec4(canvas, 1.0);
	
	
	
	//~ gl_FragColor = color;
}
