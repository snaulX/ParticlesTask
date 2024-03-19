# Particles Test Task

https://github.com/snaulX/ParticlesTask/assets/43488179/d0d052e6-0c8a-43d4-831d-63ed1816aea2

**Creates a simple fireworks by click of mouse**

*Made using C++17, CMake, [CPM](https://github.com/cpm-cmake/CPM.cmake) and [raylib](https://github.com/raysan5/raylib)*

Test task for some gamedev company on C++ Programmer position. Shortly, task was in making firework effect without using any particles lib.
Also I need to develop own UI framework to check my OOP skills. Work of firework effect explained in `Source/ParticleSystem.cpp`.
## To Do and Done
* [x] Firework effect by mouse click
* [x] Stats UI (particles and fireworks count, FPS)
* [ ] UI to configure fireworks
* [ ] Quit button and modal dialog for this
## Build
Tested only on Windows but it should works on any other machine, that **raylib** supports.
To build you need only CMake and C++ 17 compiler.
```
cmake -B Build
cmake --build Build
```
