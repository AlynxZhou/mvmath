#ifndef __MVMATH_H__
#	define __MVMATH_H__
#	define PI 3.1415926

typedef float scalar;

/*
 * vec2 is a scalar[2] like this:
 * | 0 |
 * | 1 |
 */
typedef struct {
	scalar v[2];
} vec2;

/*
 * vec3 is a scalar[3] like this:
 * | 0 |
 * | 1 |
 * | 2 |
 */
typedef struct {
	scalar v[3];
} vec3;

/*
 * vec4 is a scalar[4] like this:
 * | 0 |
 * | 1 |
 * | 2 |
 * | 4 |
 */
typedef struct {
	scalar v[4];
} vec4;

/*
 * mat4 is a scalar[16] like this:
 * |   0   4   8  12   |
 * |   1   5   9  13   |
 * |   2   6  10  14   |
 * |   3   7  11  15   |
 */
typedef struct {
	scalar m[16];
} mat4;

#ifdef __DEBUG__
int v2print(vec2 v);
int v3print(vec3 v);
int v4print(vec4 v);
int m4print(mat4 m);
#endif

scalar sabs(scalar s);
scalar smax(scalar s1, scalar s2);
scalar smin(scalar s1, scalar s2);
scalar sclamp(scalar s, scalar min, scalar max);

vec2 v2s(scalar s1, scalar s2);
scalar v2length(vec2 v);
vec2 v2normalize(vec2 v);
vec2 v2add(vec2 v1, vec2 v2);
vec2 v2substract(vec2 v1, vec2 v2);
scalar v2dot(vec2 v1, vec2 v2);
vec2 v2multiply(vec2 v, scalar s);
vec2 v2abs(vec2 v);
vec2 v2clamp(vec2 v, vec2 vmin, vec2 vmax);

vec3 v3s(scalar s1, scalar s2, scalar s3);
vec3 v3v2s(vec2 v, scalar s);
scalar v3length(vec3 v);
vec3 v3normalize(vec3 v);
vec3 v3add(vec3 v1, vec3 v2);
vec3 v3substract(vec3 v1, vec3 v2);
vec3 v3cross(vec3 v1, vec3 v2);
scalar v3dot(vec3 v1, vec3 v2);
vec3 v3multiply(vec3 v, scalar s);
vec3 v3abs(vec3 v);
vec3 v3clamp(vec3 v, vec3 vmin, vec3 vmax);

vec4 v4s(scalar s1, scalar s2, scalar s3, scalar s4);
vec4 v4v2s(vec2 v, scalar s1, scalar s2);
vec4 v4v3s(vec3 v, scalar s);
vec4 v4v2(vec2 v1, vec2 v2);
scalar v4length(vec4 v);
vec4 v4normalize(vec4 v);
vec4 v4add(vec4 v1, vec4 v2);
vec4 v4substract(vec4 v1, vec4 v2);
scalar v4dot(vec4 v1, vec4 v2);
vec4 v4multiply(vec4 v, scalar s);
vec4 v4abs(vec4 v);
vec4 v4clamp(vec4 v, vec4 vmin, vec4 vmax);

mat4 m4identity(void);
mat4 m4translate(vec3 delta);
mat4 m4scale(vec3 scale);
mat4 m4rotate(vec3 axis, scalar angle);
mat4 m4perspective(scalar fov, scalar aspect, scalar near, scalar far);
mat4 m4ortho(scalar left, scalar right, \
	     scalar bottom, scalar top, \
	     scalar near, scalar far);
mat4 m4camera(vec3 eye, vec3 target, vec3 up);
mat4 m4multiply(mat4 m1, mat4 m2);
#endif
