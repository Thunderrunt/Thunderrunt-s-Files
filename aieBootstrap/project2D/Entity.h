#pragma once
#include "Matrix3.h"
#include "Vector3.h"
#include "Collider.h"
#include <vector>

class Entity
{
public:
	Entity();
	~Entity();

	void UpdateTransform();
	void SetParent(Entity* Parents);
	void AddChild(Entity* Child);

	Collider GetCollider();
	void SetPos(Vector2 pos);
	Vector2 GetPos();

	Entity* Parent;
	std::vector<Entity*> ChildList;
	Matrix3 localTransform;
	Matrix3 globalTransform;

protected:
	Collider collider;
};

