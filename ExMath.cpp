#include "ExMath.h"

Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	Vector2 result = { v1.x + v2.x,v1.y + v2.y };
	return result;
}

Vector2 operator+=(const Vector2& v1, const Vector2& v2)
{
	Vector2 result = { v1.x + v2.x,v1.y + v2.y };
	return result;
}

Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

Vector2 operator-=(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

Vector2 operator*(float s, const Vector2& v)
{
	return Vector2(s * v.x, s * v.y);
}

Vector2 operator*(const Vector2& v, float s)
{
	return s * v;
}

Vector2 operator/(const Vector2& v, float s)
{
	return Vector2(v.x / s, v.y / s);
}
