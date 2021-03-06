/*
 * Copyright 2019 Alynx Zhou
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __MVMATH_H__
#define __MVMATH_H__
#include <math.h>

#define PI 3.141593f

#define SABS(S) ((S) >= 0 ? (S) : -(S))
#define SMAX(S1, S2) ((S1) > (S2) ? (S1) : (S2))
#define SMIN(S1, S2) ((S1) < (S2) ? (S1) : (S2))
#define SCLAMP(S, MIN, MAX) (SMAX(MIN, SMIN(MAX, S)))
#define SDEGREES(RADIANS) ((RADIANS) * PI / 180.0f)
#define SRADIANS(DEGREES) ((DEGREES) * 180.0f / PI)
#define VARRAY(V) ((V).v)
#define VX(V) VARRAY(V)[0]
#define VY(V) VARRAY(V)[1]
#define VZ(V) VARRAY(V)[2]
#define VW(V) VARRAY(V)[3]
#define VR(V) VR(V)
#define VG(V) VG(V)
#define VB(V) VB(V)
#define VA(V) VA(V)
#define MARRAY(M) ((M).m)

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
scalar sdegrees(scalar radians);
scalar sradians(scalar degrees);

vec2 v2s(scalar s1, scalar s2);
vec2 v2v3(vec3 v);
vec2 v2v4(vec4 v);
scalar v2length(vec2 v);
vec2 v2normalize(vec2 v);
vec2 v2abs(vec2 v);
int v2compare(vec2 v1, vec2 v2);
vec2 v2add(vec2 v1, vec2 v2);
vec2 v2substract(vec2 v1, vec2 v2);
scalar v2dot(vec2 v1, vec2 v2);
vec2 v2smultiply(vec2 v, scalar s);
vec2 v2multiply(vec2 v1, vec2 v2);
vec2 v2clamp(vec2 v, vec2 vmin, vec2 vmax);

vec3 v3s(scalar s1, scalar s2, scalar s3);
vec3 v3v2s(vec2 v, scalar s);
vec3 v3v4(vec4 v);
scalar v3length(vec3 v);
vec3 v3normalize(vec3 v);
int v3compare(vec3 v1, vec3 v2);
vec3 v3abs(vec3 v);
vec3 v3add(vec3 v1, vec3 v2);
vec3 v3substract(vec3 v1, vec3 v2);
vec3 v3cross(vec3 v1, vec3 v2);
scalar v3dot(vec3 v1, vec3 v2);
vec3 v3smultiply(vec3 v, scalar s);
vec3 v3multiply(vec3 v1, vec3 v2);
vec3 v3clamp(vec3 v, vec3 vmin, vec3 vmax);

vec4 v4s(scalar s1, scalar s2, scalar s3, scalar s4);
vec4 v4v2s(vec2 v, scalar s1, scalar s2);
vec4 v4v3s(vec3 v, scalar s);
vec4 v4v2(vec2 v1, vec2 v2);
scalar v4length(vec4 v);
vec4 v4normalize(vec4 v);
int v4compare(vec4 v1, vec4 v2);
vec4 v4abs(vec4 v);
vec4 v4add(vec4 v1, vec4 v2);
vec4 v4substract(vec4 v1, vec4 v2);
scalar v4dot(vec4 v1, vec4 v2);
vec4 v4smultiply(vec4 v, scalar s);
vec4 v4multiply(vec4 v1, vec4 v2);
vec4 v4clamp(vec4 v, vec4 vmin, vec4 vmax);

mat4 m4identity(void);
int m4compare(mat4 m1, mat4 m2);
mat4 m4inverse(mat4 m);
mat4 m4transpose(mat4 m);
mat4 m4multiply(mat4 m1, mat4 m2);
vec4 m4v4multiply(mat4 m, vec4 v);
mat4 m4translate(vec3 delta);
mat4 m4scale(vec3 scale);
mat4 m4rotate(vec3 axis, scalar angle);
mat4 m4perspective(scalar fov, scalar aspect, scalar near, scalar far);
mat4 m4ortho(scalar left, scalar right, scalar top, scalar bottom, scalar near,
	     scalar far);
mat4 m4camera(vec3 eye, vec3 target, vec3 up);
#endif
