#include <math.h>
#include "mvmath.h"

#ifdef __DEBUG__
#	include <stdio.h>

int v2print(vec2 v)
{
	return printf("vec2: {\n\t%8.3f, %8.3f\n}\n", v.v[0], v.v[1]);
}

int v3print(vec3 v)
{
	return printf("vec3: {\n\t%8.3f, %8.3f, %8.3f\n}\n",
		      v.v[0], v.v[1], v.v[2]);
}
int v4print(vec4 v)
{
	return printf("vec4: {\n\t%8.3f, %8.3f, %8.3f, %8.3f\n}\n",
		      v.v[0], v.v[1], v.v[2], v.v[3]);
}

int m4print(mat4 m)
{
	return printf("mat4: {\n"
		      "\t%8.3f, %8.3f, %8.3f, %8.3f\n"
		      "\t%8.3f, %8.3f, %8.3f, %8.3f\n"
		      "\t%8.3f, %8.3f, %8.3f, %8.3f\n"
		      "\t%8.3f, %8.3f, %8.3f, %8.3f\n"
		      "}\n",
		      m.m[0], m.m[4], m.m[8], m.m[12],
		      m.m[1], m.m[5], m.m[9], m.m[13],
		      m.m[2], m.m[6], m.m[10], m.m[14],
		      m.m[3], m.m[7], m.m[11], m.m[15]);
}
#endif

scalar sabs(scalar s)
{
	return s >= 0 ? s : -s;
}

scalar smax(scalar s1, scalar s2)
{
	return s1 > s2 ? s1 : s2;
}

scalar smin(scalar s1, scalar s2)
{
	return s1 < s2 ? s1 : s2;
}

scalar sclamp(scalar s, scalar min, scalar max)
{
	return smax(min, smin(max, s));
}

vec2 v2s(scalar s1, scalar s2)
{
	return (vec2){{s1, s2}};
}

scalar v2length(vec2 v)
{
	return sqrtf(v2dot(v, v));
}

vec2 v2normalize(vec2 v)
{
	return v2multiply(v, 1.0f / v2length(v));
}

vec2 v2add(vec2 v1, vec2 v2)
{
	return v2s(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1]);
}

vec2 v2substract(vec2 v1, vec2 v2)
{
	return v2s(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1]);
}

scalar v2dot(vec2 v1, vec2 v2)
{
	return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1];
}

vec2 v2multiply(vec2 v, scalar s)
{
	return v2s(v.v[0] * s, v.v[1] * s);
}

vec2 v2abs(vec2 v)
{
	return v2s(sabs(v.v[0]), sabs(v.v[1]));
}

vec2 v2clamp(vec2 v, vec2 vmin, vec2 vmax)
{
	return v2s(sclamp(v.v[0], vmin.v[0], vmax.v[0]), \
		   sclamp(v.v[1], vmin.v[1], vmax.v[1]));
}

vec3 v3s(scalar s1, scalar s2, scalar s3)
{
	return (vec3){{s1, s2, s3}};
}

vec3 v3v2s(vec2 v, scalar s)
{
	return v3s(v.v[0], v.v[1], s);
}

scalar v3length(vec3 v)
{
	return sqrtf(v3dot(v, v));
}

vec3 v3normalize(vec3 v)
{
	return v3multiply(v, 1.0f / v3length(v));
}

vec3 v3add(vec3 v1, vec3 v2)
{
	return v3s(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

vec3 v3substract(vec3 v1, vec3 v2)
{
	return v3s(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

vec3 v3cross(vec3 v1, vec3 v2)
{
	return v3s(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1], \
		   v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2], \
		   v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]);
}

scalar v3dot(vec3 v1, vec3 v2)
{
	return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
}

vec3 v3multiply(vec3 v, scalar s)
{
	return v3s(v.v[0] * s, v.v[1] * s, v.v[2] * s);
}

vec3 v3abs(vec3 v)
{
	return v3s(sabs(v.v[0]), sabs(v.v[1]), sabs(v.v[2]));
}

vec3 v3clamp(vec3 v, vec3 vmin, vec3 vmax)
{
	return v3s(sclamp(v.v[0], vmin.v[0], vmax.v[0]), \
		   sclamp(v.v[1], vmin.v[1], vmax.v[1]), \
		   sclamp(v.v[2], vmin.v[2], vmax.v[2]));
}

vec4 v4s(scalar s1, scalar s2, scalar s3, scalar s4)
{
	return (vec4){{s1, s2, s3, s4}};
}

vec4 v4v2s(vec2 v, scalar s1, scalar s2)
{
	return v4s(v.v[0], v.v[1], s1, s2);
}

vec4 v4v3s(vec3 v, scalar s)
{
	return v4s(v.v[0], v.v[1], v.v[2], s);
}

vec4 v4v2(vec2 v1, vec2 v2)
{
	return v4s(v1.v[0], v1.v[1], v2.v[0], v2.v[1]);
}

scalar v4length(vec4 v)
{
	return sqrtf(v4dot(v, v));
}

vec4 v4normalize(vec4 v)
{
	return v4multiply(v, 1.0f / v4length(v));
}

vec4 v4add(vec4 v1, vec4 v2)
{
	return v4s(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], \
		   v1.v[2] + v2.v[2], v1.v[3] + v2.v[3]);
}

vec4 v4substract(vec4 v1, vec4 v2)
{
	return v4s(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], \
		   v1.v[2] - v2.v[2], v1.v[3] - v2.v[3]);
}

scalar v4dot(vec4 v1, vec4 v2)
{
	return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + \
	       v1.v[2] * v2.v[2] + v1.v[3] * v2.v[3];
}

vec4 v4multiply(vec4 v, scalar s)
{
	return v4s(v.v[0] * s, v.v[1] * s, v.v[2] * s, v.v[3] * s);
}

vec4 v4abs(vec4 v)
{
	return v4s(sabs(v.v[0]), sabs(v.v[1]), sabs(v.v[2]), sabs(v.v[3]));
}

vec4 v4clamp(vec4 v, vec4 vmin, vec4 vmax)
{
	return v4s(sclamp(v.v[0], vmin.v[0], vmax.v[0]), \
		   sclamp(v.v[1], vmin.v[1], vmax.v[1]), \
		   sclamp(v.v[2], vmin.v[2], vmax.v[2]), \
		   sclamp(v.v[3], vmin.v[3], vmax.v[3]));
}

mat4 m4identity(void)
{
	mat4 m;
        m.m[0] = 1.0f;
        m.m[1] = 0.0f;
        m.m[2] = 0.0f;
        m.m[3] = 0.0f;
        m.m[4] = 0.0f;
        m.m[5] = 1.0f;
        m.m[6] = 0.0f;
        m.m[7] = 0.0f;
        m.m[8] = 0.0f;
        m.m[9] = 0.0f;
        m.m[10] = 1.0f;
        m.m[11] = 0.0f;
        m.m[12] = 0.0f;
        m.m[13] = 0.0f;
        m.m[14] = 0.0f;
        m.m[15] = 1.0f;
	return m;
}

mat4 m4translate(vec3 delta)
{
	mat4 m;
	m.m[0] = 1.0f;
	m.m[1] = 0.0f;
	m.m[2] = 0.0f;
	m.m[3] = 0.0f;
	m.m[4] = 0.0f;
	m.m[5] = 1.0f;
	m.m[6] = 0.0f;
	m.m[7] = 0.0f;
	m.m[8] = 0.0f;
	m.m[9] = 0.0f;
	m.m[10] = 1.0f;
	m.m[11] = 0.0f;
	m.m[12] = delta.v[0];
	m.m[13] = delta.v[1];
	m.m[14] = delta.v[2];
	m.m[15] = 1.0f;
	return m;
}

mat4 m4scale(vec3 scale)
{
	mat4 m;
	m.m[0] = scale.v[0];
	m.m[1] = 0.0f;
	m.m[2] = 0.0f;
	m.m[3] = 0.0f;
	m.m[4] = 0.0f;
	m.m[5] = scale.v[1];
	m.m[6] = 0.0f;
	m.m[7] = 0.0f;
	m.m[8] = 0.0f;
	m.m[9] = 0.0f;
	m.m[10] = scale.v[2];
	m.m[11] = 0.0f;
	m.m[12] = 0.0f;
	m.m[13] = 0.0f;
	m.m[14] = 0.0f;
	m.m[15] = 1.0f;
	return m;
}

mat4 m4rotate(vec3 axis, scalar angle)
{
	mat4 m;
	axis = v3normalize(axis);
	/*
	 * Don't know why but if not negetive here,
	 * you will get a wrong direction of rotation.
	 * Use a negetive to make positive angle
	 * shows clockwise rotation.
	 */
	const scalar s = sinf(-angle);
	const scalar c = cosf(-angle);
	const scalar temp = 1.0f - c;
	m.m[0] = temp * axis.v[0] * axis.v[0] + c;
	m.m[1] = temp * axis.v[0] * axis.v[1] - axis.v[2] * s;
	m.m[2] = temp * axis.v[2] * axis.v[0] + axis.v[1] * s;
	m.m[3] = 0.0f;
	m.m[4] = temp * axis.v[0] * axis.v[1] + axis.v[2] * s;
	m.m[5] = temp * axis.v[1] * axis.v[1] + c;
	m.m[6] = temp * axis.v[1] * axis.v[2] - axis.v[0] * s;
	m.m[7] = 0.0f;
	m.m[8] = temp * axis.v[2] * axis.v[0] - axis.v[1] * s;
	m.m[9] = temp * axis.v[1] * axis.v[2] + axis.v[0] * s;
	m.m[10] = temp * axis.v[2] * axis.v[2] + c;
	m.m[11] = 0.0f;
	m.m[12] = 0.0f;
	m.m[13] = 0.0f;
	m.m[14] = 0.0f;
	m.m[15] = 1.0f;
	return m;
}

mat4 m4perspective(scalar fov, scalar aspect, scalar near, scalar far)
{
	mat4 m;
	const scalar dz = near - far;
	const scalar cot = 1.0f / tanf(fov / 2.0f);
	m.m[0] = cot / aspect;
        m.m[1] = 0.0f;
        m.m[2] = 0.0f;
        m.m[3] = 0.0f;
        m.m[4] = 0.0f;
        m.m[5] = cot;
        m.m[6] = 0.0f;
        m.m[7] = 0.0f;
        m.m[8] = 0.0f;
        m.m[9] = 0.0f;
        m.m[10] = (far + near) / dz;
        m.m[11] = -1.0f;
        m.m[12] = 0.0f;
        m.m[13] = 0.0f;
        m.m[14] = (2.0f * far * near) / dz;
        m.m[15] = 0.0f;
	return m;
}

mat4 m4ortho(scalar left, scalar right, \
	     scalar bottom, scalar top, \
	     scalar near, scalar far)
{
	mat4 m;
	m.m[0] = 2 / (right - left);
	m.m[1] = 0;
	m.m[2] = 0;
	m.m[3] = 0;
	m.m[4] = 0;
	m.m[5] = 2 / (top - bottom);
	m.m[6] = 0;
	m.m[7] = 0;
	m.m[8] = 0;
	m.m[9] = 0;
	m.m[10] = -2 / (far - near);
	m.m[11] = 0;
	m.m[12] = -(right + left) / (right - left);
	m.m[13] = -(top + bottom) / (top - bottom);
	m.m[14] = -(far + near) / (far - near);
	m.m[15] = 1;
	return m;
}

mat4 m4camera(vec3 eye, vec3 target, vec3 up)
{
	mat4 m;
	vec3 direction = v3substract(target, eye);
	direction = v3normalize(direction);
	vec3 right = v3cross(direction, up);
	right = v3normalize(right);
	up = v3cross(right, direction);
	m.m[0] = right.v[0];
	m.m[1] = up.v[0];
	m.m[2] = -direction.v[0];
	m.m[3] = 0.0f;
	m.m[4] = right.v[1];
	m.m[5] = up.v[1];
	m.m[6] = -direction.v[1];
	m.m[7] = 0.0f;
	m.m[8] = right.v[2];
	m.m[9] = up.v[2];
	m.m[10] = -direction.v[2];
	m.m[11] = 0.0f;
	m.m[12] = -v3dot(right, eye);
	m.m[13] = -v3dot(up, eye);
	m.m[14] = v3dot(direction, eye);
	m.m[15] = 1.0f;
	return m;
}

mat4 m4multiply(mat4 m1, mat4 m2)
{
	mat4 m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m.m[i * 4 + j] = 0.0f;
			for (int k = 0; k < 4; ++k)
				m.m[i * 4 + j] += m1.m[k * 4 + j] * \
						  m2.m[i * 4 + k];
		}
	}
	return m;
}
