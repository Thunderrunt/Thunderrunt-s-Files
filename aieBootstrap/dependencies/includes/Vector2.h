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

class Vector2
{
public:
	MATHLIBRARY_API Vector2();
	MATHLIBRARY_API Vector2(float newX, 
							float newY);
	MATHLIBRARY_API ~Vector2();

	MATHLIBRARY_API Vector2 operator+(const Vector2& rhs);
	MATHLIBRARY_API Vector2 operator+();
	MATHLIBRARY_API Vector2 operator-(const Vector2 & rhs);
	MATHLIBRARY_API Vector2 operator-();
	MATHLIBRARY_API Vector2 operator*(const float rhs);
	MATHLIBRARY_API Vector2 operator/(const float rhs);
	MATHLIBRARY_API Vector2 operator+=(const Vector2& rhs);
	MATHLIBRARY_API Vector2 Normalised(Vector2 data);

	MATHLIBRARY_API float & operator[](const int rhs);
	MATHLIBRARY_API operator float*();
	MATHLIBRARY_API float Magnitude();
	MATHLIBRARY_API void Normalise();
	MATHLIBRARY_API float Dot(Vector2 rhs);

	
	float x;
	float y;	
};

Vector2 operator*(float lhs, const Vector2 rhs);
