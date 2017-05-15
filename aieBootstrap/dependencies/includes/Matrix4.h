#pragma once
#include "Vector4.h"

#ifdef STATICLIB
#define MATHLIBRARY_API 
#else
#ifdef MATHLIBRARY_EXPORTS  
#define MATHLIBRARY_API __declspec(dllexport)   
#else  
#define MATHLIBRARY_API __declspec(dllimport)   
#endif  
#endif

class Matrix4
{
public:
	MATHLIBRARY_API Matrix4();

	MATHLIBRARY_API Matrix4(float xx, float xy,
							float xz, float xw,
							float yx, float yy, 
							float yz, float yw, 
							float zx, float zy, 
							float zz, float zw, 
							float wx, float wy, 
							float wz, float ww);

	MATHLIBRARY_API ~Matrix4();

	MATHLIBRARY_API Vector4 operator*(const Vector4 & rhs);
	MATHLIBRARY_API Matrix4 operator*(const Matrix4 & rhs);

	MATHLIBRARY_API void setRotationX(const float a);
	MATHLIBRARY_API void setRotationY(const float a);
	MATHLIBRARY_API void setRotationZ(const float a);

	MATHLIBRARY_API Vector4 & operator[](const int rhs);
	MATHLIBRARY_API operator float*();

	float m[4][4];
};

