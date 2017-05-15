#pragma once
#include "Renderer2D.h"
#include "Entity.h" 
class SpaceShip : public Entity
{
public:
	SpaceShip();
	~SpaceShip();
	aie::Texture* m_shipTexture;
	void Update(float deltaTime);
	void Draw(aie::Renderer2D * m_2renderer);

	float input;
	float m_timer;

};

