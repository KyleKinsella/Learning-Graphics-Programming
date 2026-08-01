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

## Project Contents
Note: I will show images of the project as I develop this small project! 
This will be filled in, once I have completed the project or the project is work in progesss.

## Things are getting hot in here...
Since I've completed the OpenGL series, I have been reading over the codebase that we created in the OpenGL series, before I get started on my own OpenGL project.
I have spent the last 3 days reading over the codebase today is the - August 1st, 2026.

## Getting Going
I plan to start my project on Monday (August 3rd, 2026), but as this day comes closer I am starting to get nervous. The main reason to why I am getting 
nervous is for two main reasons:
1. Rembering the OpenGL API and what Parameters to use...
2. Math - how do I know if I should use a 'vec2', 'vec3', 'mat2' or 'mat4'...

But I guess the best way to get batter at anything is it practise! So on Monday, I plan to jump right into it and see how things go.

## My Ray Tracing Project (later on...)
TODO

## Game Engine Series ?!
Do or !Do ?!

<!--
## I'm a Pro Now... 
-->
