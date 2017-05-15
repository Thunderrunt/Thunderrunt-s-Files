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

class Vector4
{
public:
	MATHLIBRARY_API Vector4();
	MATHLIBRARY_API Vector4(float newX, float newY, 
							float newZ, float newW);
	MATHLIBRARY_API ~Vector4();

	MATHLIBRARY_API Vector4 operator+(const Vector4 & rhs);
	MATHLIBRARY_API Vector4 operator+();
	MATHLIBRARY_API Vector4 operator-(const Vector4 & rhs);
	MATHLIBRARY_API Vector4 operator-();
	MATHLIBRARY_API Vector4 operator*(float rhs);
	MATHLIBRARY_API Vector4 operator/(const float rhs);
	MATHLIBRARY_API Vector4 operator+=(const Vector4 & rhs);
	MATHLIBRARY_API Vector4 Cross(Vector4 rhs);

	MATHLIBRARY_API float & operator[](const int rhs);
	MATHLIBRARY_API operator float*();
	MATHLIBRARY_API float Magnitude();
	MATHLIBRARY_API void Normalise();
	MATHLIBRARY_API float Dot(Vector4 rhs);

	float x;
	float y;
	float z;
	float w;
};

Vector4 operator*(float lhs, const Vector4 rhs);