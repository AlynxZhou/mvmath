mvmath
======

A simple C implemention of some GLM Matrix and Vector Math functions.
---------------------------------------------------------------------

Based on struct of array.

You need to use C standard math library libm.so (`-lm`) to use this.

Data types:

- vec2, vec3, vec4

- mat4

Build:

```
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
$ make
```

Remove `-DCMAKE_BUILD_TYPE=Debug` if you don't need to debug.
