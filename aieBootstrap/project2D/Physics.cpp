#include "Physics.h"
#include <iostream>
#include "Collider.h"

Physics* Physics::m_instance = nullptr;


Physics::Physics()
{
}


Physics::~Physics()
{
}

Physics* Physics::GetInstance()
{
	return m_instance;
}
void Physics::Create()
{
	if(m_instance == nullptr)
		m_instance = new Physics();
}
void Physics::Destroy()
{
	delete m_instance;
}
void Physics::AddObject(Entity* pObject)
{
	m_CollisionList.push_back(pObject);
}

void Physics::RemoveObject(Entity* pObject)
{
	auto iter = std::find(m_CollisionList.begin(), m_CollisionList.end(), pObject);
	if (iter != m_CollisionList.end())
		m_CollisionList.erase(iter);
}
bool Physics::TestCollision(Entity* pObject)
{
	for (int i = 0; i < m_CollisionList.size(); ++i)
	{
		if (pObject == m_CollisionList[i])
			continue;
		
		// If colliding 
		Collider collider1 = pObject->GetCollider();
		collider1.m_TL = collider1.m_TL + pObject->GetPos();
		collider1.m_BR = collider1.m_BR + pObject->GetPos();

		Collider collider2 = m_CollisionList[i]->GetCollider();
		collider2.m_TL = collider2.m_TL + m_CollisionList[i]->GetPos();
		collider2.m_BR = collider2.m_BR + m_CollisionList[i]->GetPos();

		// Test if two AABBs are overlapping
		if (collider1.m_BR.x > collider2.m_TL.x &&
			collider1.m_BR.y > collider2.m_TL.y &&
			collider1.m_TL.x > collider2.m_BR.x &&
			collider1.m_TL.y > collider2.m_BR.y)
		{
			return true;
		}

		//return true
	}

	return false;

}
