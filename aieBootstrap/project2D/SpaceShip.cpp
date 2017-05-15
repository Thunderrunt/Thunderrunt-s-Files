#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "SpaceShip.h"

using namespace aie;

SpaceShip::SpaceShip()
{
	m_shipTexture = new Texture("./textures/ship.png");
}


SpaceShip::~SpaceShip()
{

}

void SpaceShip::Update(float deltaTime)
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();
	Vector2 pos;

	// use arrow keys to move player
	if (input->isKeyDown(INPUT_KEY_UP))
		pos.y += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		pos.y -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		pos.x -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		pos.x += 500.0f * deltaTime;

	Matrix3 PlayerPos;
	PlayerPos.m[2][0] = pos.x;
	PlayerPos.m[2][1] = pos.y;

	localTransform = localTransform * PlayerPos;

	UpdateTransform();
}

void SpaceShip::Draw(aie::Renderer2D * m_2renderer)
{
	m_2renderer->drawSpriteTransformed3x3(m_shipTexture, globalTransform);
}

