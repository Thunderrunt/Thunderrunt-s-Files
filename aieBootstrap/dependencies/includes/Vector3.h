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

class Vector3
{
public:
	MATHLIBRARY_API Vector3();
	MATHLIBRARY_API Vector3(float newX,
							float newY, 
							float newZ);
	MATHLIBRARY_API ~Vector3();

	MATHLIBRARY_API Vector3 operator+(const Vector3& rhs);
	MATHLIBRARY_API Vector3 operator+();
	MATHLIBRARY_API Vector3 operator-(const Vector3 & rhs);
	MATHLIBRARY_API Vector3 operator-();
	MATHLIBRARY_API Vector3 operator*(const float rhs);
	MATHLIBRARY_API Vector3 operator/(const float rhs);
	MATHLIBRARY_API Vector3 operator+=(const Vector3 & rhs);
	MATHLIBRARY_API Vector3 Normalised(Vector3 data);
	MATHLIBRARY_API Vector3 Cross(Vector3 rhs);

	MATHLIBRARY_API float & operator[](const int rhs);
	MATHLIBRARY_API operator float*();
	MATHLIBRARY_API float Magnitude();
	MATHLIBRARY_API void Normalise();
	MATHLIBRARY_API float Dot(Vector3 rhs);
	

	float x;
	float y;
	float z;
};

Vector3 operator*(float lhs, const Vector3 rhs);