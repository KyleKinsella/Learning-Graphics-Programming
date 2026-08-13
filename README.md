# Learning-Graphics-Programming

### Why am I learning Graphics Programming ?
The main reason to why I want to learn graphics programming is for two simple reasons:
1. boredom - due to unemployment.
2. I was inspired by a Youtuber called tokyospliff. View his Youtube channel: https://www.youtube.com/@tokyospliff. 

### What API am I using ?
While I have been watching tokyospliff he always keeps referencing 'OpenGL', so I have decided to learn OpenGL. But I am aware of other api's, such as:
1. SDL
2. Vulkan

### Getting Started
As of today (July 21st, 2026), I have done 3 full days of graphics programming. I started learning graphics programming on July 19th and I am going to continue to try and learn as much as I can. That 
being said, I have found it quite hard to get up and running with a simple 'Hello World' program for graphics, compared to other computer science topics. So, what did I do, to get my first Hello World 
program working for graphics ? I am using The Cherno (another Youtuber) to get up and running and get the basics kinda down. View his Youtube channel: https://www.youtube.com/@TheCherno.

The Cherno, has created a playlist specifically for 'OpenGL', see here for more info: https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2

### What have I learned so far ?
I have learned some of the terms used in graphics programming, such as: 
1. Vertex Buffer - an array of your vertexes that you want to send to the GPU.
2. Index Buffer - an array that contains indexes into our vertex buffer, to reduce duplication of the same vertex values, this keeps our GPU memory happy.
3. Shader - this is just source code that runs on the GPU. Initially I thought this was for 'shadowing' or something, I was wrong, lol...
	1. Vertex Shader - this shader is responsible for placing a vertex variable to where you want it to be.
	2. Fragment Shader - this shader, runs once for every pixel.
4. OpenGL - an API for talking to our GPU. Initially, I thought this was a piece of software that you needed to download (I was wrong again), but after watching 'Welcome to OpenGL' the first
video in the OpenGL playlist, I found out that OpenGL, is already on our GPU. 
5. Uniforms - getting data from our CPU (our c++ code), into our shader (our code for the GPU) and use it like a variable. Uniforms are set per draw, you can set up a uniform up before you wish
to draw your element, aka: 'glDrawElements(...)' or 'glDrawArrays(...)'

### But how is it on my GPU already ? 
The manufacturer, that created my laptop (Intel), when they were designing the GPU, they put OpenGL onto my GPU. 

### Do I like Graphics Programming ?
As I have only started doing graphics programming for roughly 3 days or so, I cannot say too much just yet... but from my experience so far, I kinda like it. For example, yesterday (July 20th, 2026),
I was watching one of the videos in the OpenGL playlist and I was coding it all out myself manually, but I was not really enjoying it, at all. But today I am starting to really enjoy it.

My biggest complaint about graphics programming, is that - you have to do a lot of configuring and coding, but at the end of it, it does not look like much. For example, currently my 'main.cpp' file
is 184 lines of code and all we have done is draw a square, that flashes from a kinda pink-ish color, to blue and blue back to the pick-ish color...

### Learning by Doing
The best way for me to learn something is to do the following:
1. Watch the video.
2. Pause it.
3. Write the code out manually, compile the program, make sure it works, if not debug it until it works. 
4. Then continue into the video.

### Linux
Most people like to use the Windows but as I am a developer / Engineer and I don't like Windows, I am doing all of this work on Linux, specifically Fedora Linux.

## Why ?
Well, Linux is open-source, it is incredebly fast, no spyware, no bloatware, no AI slop pushed in our face, brilliant community and so much more. And I really enjoy using Linux.

So, this means, I do everything via my terminal, meaning I can do things very fast and efficiently.

## An Update - What have I done for the last while ?
On the July 19th 2026, I started an OpenGL series with 'The Cherno'. And each day I would do either one, two or three (and sometimes even more than three) vidoes per day 
and I simply did this until I finished this series. I have successfully completed the OpenGL series on - July 29th 2026. It took me 9 days to complete the entire OpenGL series.

## So, What is Next ?
Before I even started the OpenGL series, I said to myself: 'When I am done the OpenGL series, I am going to create my own project for OpenGL, BUT, I need to implement everything I learned in the OpenGL
series in this project'! So, I need to create a project that contains the following:
1. Vertex Buffer.
2. Index Buffer.
3. Shaders (Vertex & Fragment).
4. Sending data from the CPU to the GPU (aka, uniforms).
5. Renderering something on the screen.
6. Textures.
7. Blending.
8. Maths, Projection, Model View Projection (MVP) matrices.
9. ImGui - this is optional.
10. Test framework - something we created in the series (this is also optional).
11. Batch Renderering - the code 'The Cherno' wrote in these videos is different to the code we did throughout the OpenGL series, so I have not done this, so I might do this OR I might 
not do it at all.

## Into the Future
Once I have completed my OpenGL project (I have not even started it yet, heck I don't even have a project idea, yet, lol), I plan to go through 'The Cherno's' series on 'Ray Tracing'.
Do one or more videos each day and at the end of that series do my very own Ray Tracing project, based on everything I will learn in that series.

Once the 'Ray Tracing' series and my project is complete, I might or might not do 'The Cherno's' game engine series... If I do it, I will do the same process as I am going to do for my OpenGL
project and soon enough ray tracing project. If I don't do the game engine series, I am not exactly sure what I will do (as of right now, July 29th, 2026).

<!--
I might do one of the following:
1. I will create my own game, with OpenGL and Ray Tracing. 
or,
2. 
-->

## My OpenGL Project (Current)
I did not know what project idea to do for my OpenGL project, so, I asked ChatGPT for some ideas and he gave me lots of ideas, but one of the ideas he gave me I really liked! 

So, what am I going to build ?
A 'Bouncing Ball Simulator'. I know this seems very easy and even stupid, but I don't want to create anything to complex, I just want to learn OpenGL by doing and after doing the OpenGL series 
with The Cherno. This is going to be hard (and scary, lol) but, in return I will learn lots and this is the best way to learn how to build something from scratch.

## Problems & Challanges & Solution's & Answer's
This part of the README explains what problems I have faced during this OpenGL project and how I fixed these problems.

1. My first big problem that i had to face was sending data from my C++ code (CPU side) to OpenGL (GPU side), this is known as a uniform variable. I was sending 2 or 3 uniform variables, while the window was open, but for some
reason I kept getting this error:

- Warning: uniform 'iResolution' doesn't exist!

And i was very confused because I had set-up everything to work perfectly for my uniforms. So, i spent roughly around 2-3 hours last night (August 7th, 2026) and around 4 hours today (August 8th, 2026) I eventually found the culprit!
I did some research and I found this: https://wikis.khronos.org/opengl/GLSL_:_common_mistakes. I had a read and aparently if you send over a uniform variable to your fragment shader and you use that variable for processing but you 
don't use that uniform in the output color, the GLSL compiler will optimize it out! When I read this, I was very angry because, i spent 4 hours today and 2-3 hours yesterday and all along my code was right but because of the error, 
i got, i was under the impression that i had a problem with how i was sending my uniforms to my GPU, but this was not the problem at all, it was the GLSL compiler optimzing my fragment shader code to remove it because it was 
not used in the output color (a incredebly stupid design descision, glsl team).

See Image 2 to view the project so far.

2. This problem, was very hard for me to fix, it took me 2-3 days to fix this problem. After I was able to create one circle I thought it was going to be a walk in the park
to get to create multiple circles. I thought this would be true but turns out it was not. For example: in my Blockchain from Scratch (Simulation) project, I was able to create one block 
(the Genesis block) and then just loop N times to create N other blocks, see here for more info: https://github.com/KyleKinsella/BlockChain-Project-From-Scratch/blob/main/Blocks/block.go.

Because I was able to do this for my blockchain project, I thought, this would be easy to do (I was very wrong). After 1-2 days of trying to figure it out on my own I decided to go to
YouTube, to try and see if I could find a helpful video and I found this video: https://www.youtube.com/watch?v=L-BA4nJJ8bQ. After watching this video I was able to produce the circle 
in Image 3 (see below). But in this video the creator made a function so that we can create as many circles/balls as we want. But when I wrote this function and involked it, I did not 
get the same result as the video creator did. So, this left me very confused, why am I not getting the same result !? So, I spent hours try to debug it myself (without AI). But after many
hours I said to myself: "I have spent hours at this and I have not found the solution to this problem, I don't want to use AI because it is a guessing machine but I am soooo
confused, I'll use AI even do I don't want to"! So, after wayyy to many prompts I eventually got something that produced a circle/ball, see Image 4 for more details.

But before I got the output of Image 4, I had a massive problem - my circle/ball was getting cut off, literally. See image and fragment shader below for more info. 
But I have learned why this occured. For example: In my fragment shader, for the variable 'redCircle', the 'xCoord' and 'yCoord' values are 120.0, 500.0. But in my main.cpp I have
defined SCREEN_WIDTH = 640 and SCREEN_HEIGHT = 480, so if my window (aka, quad) is of these values '640x480', it's very obvious to its going to be cut off!

Note: this also applies to the purple circle also. And in my fragment shader, I have defined a variable called 'UV'. This variable is built-in to opengl and the x and y
coordinates are your viewport size, so in this case the x = 640 and y = 480, this runs for every fragment / pixel on the screen (aka, window or quad).

<!--
because the SCREEN_HEIGHT variable is set to 480 and the 'yCoord' parameter is 500.0, to its going to be cut off!
-->

Image of Red & Purple Circle's being cut off

![Image of Red & Purple Circle's being cut off](https://github.com/KyleKinsella/Learning-Graphics-Programming/blob/main/project-images/Screenshot%20From%202026-08-13%2013-16-38.png)

```
#version 330 core

layout (location = 0) out vec4 color;

#define UV gl_FragCoord.xy

// TODO: add color...
float createCircle(float lowerEdge, float higherEdge, float xCoord, float yCoord) {
	return 1.0 - smoothstep(lowerEdge, higherEdge, distance(UV, vec2(xCoord, yCoord)));
}

void main() {
	float whiteCircle = createCircle(12.0, 50.0, 245.0, 345.0);
	float redCircle = createCircle(25.0, 80.0, 120.0, 500.0);
	float purpleCircle = createCircle(2.0, 5.0, 640.0, 320.0);
	float pinkCircle = createCircle(20.0, 23.0, 210.0, 80.0);
		
	vec3 canvas = vec3(1.0, 1.0, 1.0) * whiteCircle + vec3(1.0, 0.0, 0.0) * redCircle + vec3(0.65, 0.56, 1.0) * purpleCircle + vec3(1.0, 0.55, 0.76) * pinkCircle;
	color = vec4(canvas, 1.0);
}
```

main.cpp
```
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
```

## Project Contents (so far)
Note: I will show images of the project as I develop this small project! 
This will be filled in, once I have completed the project or the project is work in progesss.

The project is early doors at the moment there is not much done (to the eye), but what happens on the backend is very important. The project currently has the following:
- Vertex Buffer.
- Index Buffer.
- Shaders (Vertex & Fragment).
- My own types called (There will be more to come):
	- Circle: this is what a ball is going to consist of, such as: (origin, radius, velocity, color, etc).
	- Shader: this is my code for reading a shader file, compiling and creating a shader.

## Project Images
Below is the first image of the project so far:

Image 1:

![A yellow triangle - image one](https://github.com/KyleKinsella/Learning-Graphics-Programming/blob/main/project-images/Screenshot%20From%202026-08-07%2021-31-14.png)

Image 2:

![A faded dark blue triangle - image two](https://github.com/KyleKinsella/Learning-Graphics-Programming/blob/main/project-images/Screenshot%20From%202026-08-08%2020-23-01.png)

As you can see in the image above is not a cicle/ball, just yet. I am very aware of this, but i have learned a lot from the OpenGL YouTube series by The Cherno. And I have spent two days
designing my code-base, such that: its easy to read and undertand the data-flow of my application.

Image 3:

![A small blue circle/ball](https://github.com/KyleKinsella/Learning-Graphics-Programming/blob/main/project-images/Screenshot%20From%202026-08-10%2016-19-09.png)

Image 4:

![My OpenGL Project so far](https://github.com/KyleKinsella/Learning-Graphics-Programming/blob/main/project-images/Screenshot%20From%202026-08-13%2012-37-56.png)

## Project Contents (to be added)
- Uniforms - complete.
- Textures.
- Maths, Projection, Model View Projection (MVP) matrices, Physics.
- An interactive GUI, for play testing the project.
- An input system, for example: press the 'spacebar' button and your ball goes into the air.
- Collision checking - has a ball hit our box or the end our of window.

## Things are getting hot in here...
Since I've completed the OpenGL series, I have been reading over the codebase that we created in the OpenGL series, before I get started on my own OpenGL project.
I have spent the last 3 days reading over the codebase today is the - August 1st, 2026.

## Getting Going
I plan to start my project on Monday (August 3rd, 2026), but as this day comes closer I am starting to get nervous. The main reason to why I am getting 
nervous is for two main reasons:
1. Rembering the OpenGL API and what Parameters to use...
2. Math - how do I know if I should use a 'vec2', 'vec3', 'mat2' or 'mat4'...

But I guess the best way to get batter at anything is it practise! So on Monday, I plan to jump right into it and see how things go.

## A bit of a Story
On Monday (August 3rd, 2026), I planned to start my OpenGL project, but I had only started working on my project for about 43 minutes and let's just say 
the rest of my day did not go good at all, subsequently, I did not do any more work on the project (I got little to nothing done)!

So, after this happened I got quite depressed and annoyed, so I said to myself: "I am not going to do this OpenGL project anymore, it's a waste of time". 
And then I did something I should have not done, I watched the first two videos in the Ray Tracing series by 'The Cherno'.
And in that video, he mentions that he is going to use the 'Vulkan' graphics API, for the Ray Tracing series
(I have heard how hard Vulkan is from tokyospliff and some other content creators), so I said to myself: "I am not going to do that series". 

So, the next day (August 4th, 2026), I did not do anything other than play Xbox and chill. But around nine or ten pm I said to myself:
"I could just abandon my OpenGL project, because, I did little to nothing on it". But then I thought, well then what was the point of learning
OpenGL, that was a waste of time. But roughly 30 minutes later I thought: I don't want to just forget about OpenGL and Ray Tracing, so I did a small bit 
of research - 'can you do ray tracing in opengl?' and turns out, you absoultly can. But for some odd reason it is not recommended. So, this 
actually brightnened up my night, a lot! And I really enjoyed working in C++ again (I did it in college, but its been a while) and its very fun coding
in C++, that is another reason, to why I want to keep working on this project and future graphics projects :).

But I did not stop there, I went onto 'DuckDuckGo' (the search engine) and I searched for the following: "how to do ray tracing in opengl" and 
I was shown a handful of github projects and blogs of how they did Ray Tracing in OpenGL.

Then I went to YouTube and searched for the following: "ray tracing opengl c++". And I was shown a few videos, but I scrolled down a few
videos and I found a video by the cherno, called: "how to render circles". And let me tell you something, I couldn't have been any happier!

## Why was I so happy ?
Well, I am trying to make a 'Bouncy Ball Simulator' and I was trying to figure it out on Monday - how do i represent cicles in my vertex buffer ? And well this video is a brilliant resource!

## So, the main thing is you don't ever give up (things happen for a reason)!
In life we have good and bad days, but turns out, the bad days actually can help use grow bigger and stronger. At the end of the day
we are human, we have up's and down's, we make mistakes and we makes good projects and idea's, but all that matters is that we continue forward, always! 
For example, I could have just said "fuck it", fuck this (I kinda did), but after doing some reflecting, thinking and 
a small bit of research, turns out my night got much better! And now I am going to work on my OpenGL project for the next while (until it is done) and then I will attack Ray Tracing!

## Summary (of the story)
1. Monday (August 3rd): Planned to start my project on Monday (August 3rd), things we wrong. 
Got depressed and very angry, found out that the Ray Tracing series is in 'Vulkan'...
2. Tuesday (August 4th): Took it easy, did some thinking, reflecting and research and found very useful information.
3. Wednesday (August 5th): back working on the project and back learning!

## Really Learning
During this week I watched a YouTube video called: 'how to render circles' by The Cherno. And in that video we write a fragment shader that renders a circle. The below code is the code we wrote in that video:

```
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy * 2.0 - 1.0;
    float apsect = iResolution.x / iResolution.y;
    uv.x *= apsect;
    
    fragColor.rg = uv;
    fragColor.b = 0.0;
    
    float thickness = 1.0;
    float fade = 0.5;
    thickness += fade;
    
    // here we invert our color, the middle is 1 and as we go out if goes closer to 0
    float distance = 1.0 - length(uv);
    
    vec3 col = vec3(smoothstep(0.0, fade, distance));   
    col *= vec3(smoothstep(thickness + fade, thickness, distance));
    
    fragColor.rgb = col;
    fragColor.rgb *= vec3(0.2, 0.3, 0.8); // blue circle
}
```

And this is the cool part, i have converted this example (we did this on ShaderToy: https://www.shadertoy.com/new) to mostly work in my very own fragment shader that my code processes!
This has been very rewarding but also incredebly very fun! To view my current fragment shader see here: https://github.com/KyleKinsella/Learning-Graphics-Programming/blob/main/Bouncing-Ball-Simulator/shaders/fragmentTestShader.glsl.

## My Ray Tracing Project (later on...)
TODO

## Game Engine Series ?!
Do or !Do ?!

<!--
## I'm a Pro Now... 
-->
