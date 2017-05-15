#include "Entity.h"

Entity::Entity()
{
	collider.m_TL = Vector2(-30, -30);
	collider.m_BR = Vector2(30, 30);
	Parent = nullptr;
}


Entity::~Entity()
{
}

Collider Entity::GetCollider()
{
	return collider;
}

void Entity::SetPos(Vector2 pos)
{
	localTransform.m[2][0] = pos.x;
	localTransform.m[2][1] = pos.y;
	UpdateTransform();
}

Vector2 Entity::GetPos()
{
	Vector2 result;
	result.x = globalTransform.m[2][0];
	result.y = globalTransform.m[2][1];
	return result;
}

void Entity::UpdateTransform()
{
	if (Parent != nullptr)
		globalTransform = localTransform * Parent->globalTransform;
	else
		globalTransform = localTransform;
}

void Entity::SetParent(Entity* Parents)
{
	Parent = Parents;
}

void Entity::AddChild(Entity* Child)
{
	ChildList.push_back(Child);
}