#pragma once
#include "Vector3.h"

#ifdef STATICLIB
#define MATHLIBRARY_API 
#else
#ifdef MATHLIBRARY_EXPORTS  
#define MATHLIBRARY_API __declspec(dllexport)   
#else  
#define MATHLIBRARY_API __declspec(dllimport)   
#endif  
#endif

class Matrix3
{
public:
	MATHLIBRARY_API Matrix3();
	MATHLIBRARY_API Matrix3(float xx, 
							float xy, float xz, 
							float yx, float yy,
							float yz, float zx,
							float zy, float zz);
	MATHLIBRARY_API ~Matrix3();

	MATHLIBRARY_API Vector3 operator*(const Vector3 & rhs);
	MATHLIBRARY_API Matrix3 operator*(const Matrix3 & rhs);

	MATHLIBRARY_API void setRotationX(const float a);
	MATHLIBRARY_API void setRotationY(const float a);
	MATHLIBRARY_API void setRotationZ(const float z);

	MATHLIBRARY_API Vector3 & operator[](const int rhs);
	MATHLIBRARY_API operator float*();

	float m[3][3];
};

