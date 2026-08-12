#version 330 core

layout (location = 0) out vec3 fragColor;

uniform vec3 iResolution;
//~ uniform vec2 fragCoord; // idk if this is a good or bad idea, guess there is only only one way to find out... LOL!
uniform vec3 color;

void main() {	
	vec2 fragCoord = gl_FragCoord.xy;
	
	vec2 uv = fragCoord/iResolution.xy;// * 2.0 - 1.0;
	//~ vec2 uv =  gl_FragCoord.xy/iResolution.xy;// * 2.0 - 1.0;
    //~ float apsect = iResolution.x / iResolution.y;
    //~ uv.x *= apsect;	// * 2.0f * 1.0f;
    
    //~ uv.x *= 1.0 / apsect;
    //~ uv.x /= apsect;
    
	//~ fragColor.rg = uv;
    //~ fragColor.b = 0.0;
    
    //~ float thickness = 2.0;
    //~ float fade = 0.5;
    //~ thickness += fade;
    
    // here we invert our color, the middle is 1 and as we go out if goes closer to 0
    //~ float distance = 1.0 - length(uv);
    
    vec3 canvas = vec3(1.0);
	float circle = 0.0;
	
    circle = distance(uv, vec2(0.5));
    
	//~ vec3 col = vec3(smoothstep(0.0, fade, distance));   
	
	//~ circle = smoothstep(0.0, fade, distance);
	
	circle = smoothstep(0.9, 0.903, 1.0 - circle);
	
	//~ circle = smoothstep(0.0, fade + thickness, 1.0 - circle);
    
    //~ canvas = canvas * circle;
    
    canvas *= circle;
    
    //~ col *= vec3(smoothstep(thickness + fade, thickness, distance));
    
    //~ circle *= vec3(smoothstep(thickness + fade, thickness, 1.0 - circle));

    //~ fragColor.rgb = col * color;
    
    gl_FragColor = vec4(color * canvas, 1.0);
    
    //~ fragColor.rgb = col * color * circle;
    
    //~ fragColor.rgb = col;
    //~ fragColor.rgb *= color;
}
