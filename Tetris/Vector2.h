#pragma once

#ifndef __VECTOR2_STRUCT__
#define __VECTOR2_STRUCT__

#include <Windows.h>
#include <math.h>

struct Vector2
{
	double x;
	double y;
	
public:
	Vector2() : x(0.f), y(0.f) {}
	Vector2(const int& _x, const int& _y) : x(static_cast<double>(_x)), y(static_cast<double>(_y)) {};
	Vector2(const float& _x, const float& _y) : x(static_cast<double>(_x)), y(static_cast<double>(_y)) {}
	Vector2(const double& _x, const double& _y) : x(static_cast<double>(_x)), y(static_cast<double>(_y)) {};
	Vector2(const POINT& _pt) : x(static_cast<double>(_pt.x)), y(static_cast<double>(_pt.y)) {};
	Vector2& operator=(const Vector2& _vt) {
		if (this != &_vt) {	// �ڱ� ���� �˻�
			x = _vt.x;
			y = _vt.y;
		}
		return *this;
	}
	Vector2& operator=(const POINT& _pt) {
		x = static_cast<double>(_pt.x);
		y = static_cast<double>(_pt.y);
	}
	Vector2 operator+(const POINT& _pt) {
		return Vector2(x + static_cast<double>(_pt.x), y + static_cast<double>(_pt.y));
	}
	Vector2 operator+(const Vector2& _vt) {
		return Vector2(x + _vt.x, y + _vt.y);
	}
	Vector2& operator+=(const POINT& _pt) {
		x += static_cast<double>(_pt.x);
		y += static_cast<double>(_pt.y);
		return *this;
	}
	Vector2& operator+=(const Vector2 _vt) {
		x += _vt.x;
		y += _vt.y;
		return *this;
	}
	Vector2 operator-(const POINT& _pt) {
		return Vector2(x - static_cast<double>(_pt.x), y - static_cast<double>(_pt.y));
	}
	Vector2 operator-(const Vector2& _vt) {
		return Vector2(x - _vt.x, y - _vt.y);
	}
	Vector2& operator-=(const POINT& _pt) {
		x -= (double)_pt.x;
		y -= (double)_pt.y;
		return *this;
	}
	Vector2& operator-=(const Vector2& _vt) {
		x -= (double)_vt.x;
		y -= (double)_vt.y;
		return *this;
	}
	Vector2 operator*(const POINT& _pt) {
		return Vector2(x * static_cast<double>(_pt.x), y * static_cast<double>(_pt.y));
	}
	Vector2 operator*(const Vector2& _vt) {
		return Vector2(x * _vt.x, y * _vt.y);
	}
	Vector2 operator*(const int& _n) {
		return Vector2(x * _n, y * _n);
	}
	Vector2 operator*(const float& _n) {
		return Vector2(x * _n, y * _n);
	}
	Vector2 operator*(const double& _n) {
		return Vector2(x * _n, y * _n);
	}
	Vector2& operator*=(const POINT& _pt) {
		x *= (double)_pt.x;
		y *= (double)_pt.y;
		return *this;
	}
	Vector2& operator*=(const Vector2& _vt) {
		x *= (double)_vt.x;
		y *= (double)_vt.y;
		return *this;
	}
	// 0���� ������ ������ ������ ������ �����ϴ� �ڵ忡�� �ذ��� ��.
	Vector2 operator/(const POINT& _pt) {
		return Vector2(x / static_cast<double>(_pt.x), y / static_cast<double>(_pt.y));
	}
	Vector2 operator/(const Vector2& _vt) {
		return Vector2(x / _vt.x, y / _vt.y);
	}
	Vector2 operator/(const int& _n) {
		return Vector2(x / _n, y / _n);
	}
	Vector2 operator/(const float& _n) {
		return Vector2(x / _n, y / _n);
	}
	Vector2 operator/(const double& _n) {
		return Vector2(x / _n, y / _n);
	}
	Vector2& operator/=(const POINT& _pt) {
		x /= (double)_pt.x;
		y /= (double)_pt.y;
		return *this;
	}
	Vector2& operator/=(const Vector2& _vt) {
		x /= (double)_vt.x;
		y /= (double)_vt.y;
		return *this;
	}
	double Length() { return sqrtl(x * x + y * y); }
	Vector2& Normalize() {
		double length = Length();
		if (length == 0) {
			return *this;
		}
		x /= length;
		y /= length;
		return *this;
	}
};

#endif // !__VECTOR2_STRUCT__
