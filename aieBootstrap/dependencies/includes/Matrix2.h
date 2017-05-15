#pragma once

#ifdef STATICLIB
#define MATHLIBRARY_API 
#else
#ifdef MATHLIBRARY_EXPORTS  
#define MATHLIBRARY_API __declspec(dllexport)   
#else  
#define MATHLIBRARY_API __declspec(dllimport)   
#endif  
#endif

#include "Vector2.h"
class Matrix2
{
public:
	MATHLIBRARY_API Matrix2();
	MATHLIBRARY_API Matrix2(float xx, float xy, 
							float yy, float yx);
	MATHLIBRARY_API ~Matrix2();

	MATHLIBRARY_API Vector2 operator*(const Vector2& rhs);
	MATHLIBRARY_API Matrix2 operator*(const Matrix2& rhs);

	MATHLIBRARY_API operator float*();
	MATHLIBRARY_API void setRotation(const float a);
	MATHLIBRARY_API Vector2& operator[](const int rhs);

	float m[2][2];
};

