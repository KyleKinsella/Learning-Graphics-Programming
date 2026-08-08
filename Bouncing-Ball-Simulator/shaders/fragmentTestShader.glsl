#version 330 core

layout (location = 0) out vec3 fragColor;

uniform vec3 iResolution;
//~ uniform vec2 fragCoord; // idk if this is a good or bad idea, guess there is only only one way to find out... LOL!
uniform vec3 color;

void main() {	
	vec2 fragCoord = gl_FragCoord.xy;
	
	vec2 uv = fragCoord/iResolution.xy * 2.0 - 1.0;
    float apsect = iResolution.x / iResolution.y;
    uv.x *= apsect;
    
	fragColor.rg = uv;
    fragColor.b = 0.0;
    
    float thickness = 1.0;
    float fade = 2.5;
    thickness += fade;
    
    // here we invert our color, the middle is 1 and as we go out if goes closer to 0
    float distance = 1.0 - length(uv);
    
	vec3 col = vec3(smoothstep(0.0, fade, distance));   
    col *= vec3(smoothstep(thickness + fade, thickness, distance));
    
    fragColor.rgb = col * color;
}
