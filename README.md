mvmath
======

A simple C implemention of some GLM Matrix and Vector Math functions.
---------------------------------------------------------------------

This library builds a left hand coordinate.

- From left to right is -1.0 to +1.0 in x axis.
- From bottom to top is -1.0 to +1.0 in x axis.
- From outside to inside is -1.0 to +1.0 in x axis.

Based on struct of array.

You need to link C standard math library libm.so (`-lm`) to use this.

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
