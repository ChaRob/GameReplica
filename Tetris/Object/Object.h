#pragma once
#include "../pch.h"

using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Update();

private:
	string m_name;
	Vector2 m_pos;
	Vector2 m_size;

public:
	Vector2 GetPos() const { return m_pos; }
	void SetPos(const Vector2& _vec) { m_pos = _vec; }
	string GetName() const { return m_name; }
	void SetName(const string& _name) { m_name = _name; }
	Vector2 GetSize() const { return m_size; }
	void SetSize(const Vector2& _vec) { m_size = _vec; }
};

