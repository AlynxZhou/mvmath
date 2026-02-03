mvmath
======

A simple C implemention of some GLM Matrix and Vector Math functions.
---------------------------------------------------------------------

This library is based on OpenGL left hand coordinate.

# Data types

- vec2
- vec3
- vec4
- mat4

They are just structs of array.

# Usage

Add it as a submodule to your project and use Meson's `subdir()` for it. You could link against it by using `mvmath_dep`. You should at least use `c99` as the C standard (`-std=c99`).

If you want to get debug output, you should define `__DEBUG__` macro. If you want to use custom print function, define `MVPRINT` before include `mvmath.h`, for example `#define MVPRINT g_debug`. Otherwise it will use `printf` by default.

If your project does not use Meson, you can directly copy `srcs/mvmath.{c,h}` to your source tree, then you need to link it against C standard math library `libm.so` (`-lm`).
