mvmath
======

A simple C implemention of some GLM Matrix and Vector Math functions.
---------------------------------------------------------------------

This library is based on OpenGL left hand coordinate.

You need to link C standard math library libm.so (`-lm`) to use this.

# Data types

- vec2
- vec3
- vec4
- mat4

They are just structs of array.

# Usage

Add it as a submodule to your project and use Meson to build and compile it. If your project does not use Meson, you can directly copy `srcs/mvmath.{c,h}` to your source tree.

If you want to use custom print function, define `MVPRINT` before include `mvmath.h`, for example `#define MVPRINT g_debug`. Otherwise it will use `printf` by default.
