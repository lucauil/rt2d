#include "enemy.h"

Enemy::Enemy(): Entity()
{
	this->addSprite("assets/bph.tga");
	this->alive = true;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	
}