# CG-DRAW
A simple SDL2 based project for drawing directly on to a surface (a.k.a. framebuffer).

Intended for learning the basics of computer graphics (e.g. drawing). 

# Requirements
- **C++ compiler** - tested with *gcc* on Arch Linux, but should be working on Windows and MacOS X
- **CMake** - for project setup.

# Instructions
The root ``CMakeLists.txt`` file automatically downloads and builds **SDL2** for the project

For building the project in **JetBrains Clion**:
1. clone the repository
2. open the cloned project in **Clion**: ``File -> Open`` and select the cloned directory.
3. Build the project ``cg-draw`` in **Clion**: ``File -> Build 'cg-draw'`` or press ``Ctrl + 9``
4. Wait for **CMake** to download and build **SDL2** and then build the project
5. Run the project: ``Run -> Run 'cg-draw'`` or press ``Shift + F10``
