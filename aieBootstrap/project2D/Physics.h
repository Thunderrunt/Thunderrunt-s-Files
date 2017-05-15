#pragma once
#include <vector>
#include "Entity.h"

class Physics
{
public:
	static Physics* GetInstance();
	static void Create();
	static void Destroy();

	void AddObject(Entity* pObject);
	void RemoveObject(Entity* pObject);
	bool TestCollision(Entity* pObject);

private:
	Physics();
	~Physics();
	static Physics* m_instance;

	std::vector<Entity*> m_CollisionList;

};

