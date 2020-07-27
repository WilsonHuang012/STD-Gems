#pragma once
template<typename T>
class Vec2_
{
public:
	Vec2_(T x, T y)
		:x(x), y(y)
	{}
	~Vec2_() = default;

	bool operator==(const Vec2_<T> &rhs) const
	{
		return (x == rhs.x) && (y == rhs.y);
	}

public:
	T x;
	T y;
};

typedef Vec2_<int> Vei2;
typedef Vec2_<float> Vec2;