# Intel iGPU Memory Leak

This is a sample project demonstrating the memory leak reported [here](https://www.reddit.com/r/intel/comments/m46fe7/some_intel_igpus_opengl_window_resizing_leads_to/).

## Summary

Some Intel iGPU's in combination with OpenGL lead to leaked memory if the window is resized and redrawn.
Specifically, I think the first OpenGL-Draw-Command after the window being resized is responsible for the memory leak.

The memory usage of the program rises to about 700mb for me and it doesn't get freed for as long as the program is running. It eventually settles at 500mb, if not resized for a while.

This behavior is confirmed with [Krita](https://krita.org/) (with OpenGL rendering enabled), [Qt](https://www.qt.io/) applications using OpenGL, and OpenGL programs using something like [GLFW](https://www.glfw.org/) or [SDL](http://www.libsdl.org/).
I've tried multiple combinations of [SDL](http://www.libsdl.org/), [GLFW](https://www.glfw.org/), [GLEW](http://glew.sourceforge.net/), and [GLAD](https://github.com/Dav1dde/glad). All lead to the same leak for my machine.

It seems like a problem only occuring on Windows.

## Results

### This behavior is confirmed for the following iGPU's
| iGPU | Driver version | Operating System |
|:-----|:---------------|:-----------------|
| Intel UHD 620 | 30.0.100.9360 | Windows 10 |
| Intel Iris Xe | 27.20.100.8935 | Windows 10 |

### This behavior does not occur with the following (i)GPU's
| (i)GPU | Driver version | Operating System |
|:-----|:---------------|:-------------------|
| NVIDIA GeForce GTX 1060 | 27.21.14.5671 | Windows 10 |
| Intel HD Graphics (Cherry Trail) | 20.19.15.4549 | Windows 10 |

## Building

This project depends on [GLFW](https://www.glfw.org/) and [GLEW](http://glew.sourceforge.net/) and needs [CMake](https://cmake.org/) and a C++ compiler to be built.

### Dependencies

Arch Linux:
```bash
sudo pacman -S glfw glew
```

Using [vcpkg](https://github.com/microsoft/vcpkg) (Useful on Windows):
```powershell
./vcpkg.exe install glew glfw3
```

### Building

This can be built in your preferred IDE supporting [CMake](https://cmake.org/).

The following are steps for building it on the command line on linux:
```bash
mkdir build && cd build
cmake ..
make
```

The resulting executable is located in `build/`.

## Testing

- Start the resulting executable. (But don't resize it yet)
- Track the memory usage of this program. (It should be at around 30mb)
- Resize the window. (not the cmd window if one gets opened)
- Observe the memory usage rising if your iGPU is affected. (For me it rises to around 700mb)
- Please open an issue with your test result and your system information. (For both positive and negative results)
