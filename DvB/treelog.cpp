// treelog.cpp

#include "treelog.h"

//float scr_width = ScreenSize.X;

Treelog::Treelog(): Entity()
{
	this->addSprite("assets/log.tga");
	this->alive = true;
}

Treelog::~Treelog()
{

}

void Treelog::update(float deltaTime)
{
	if (this->position.y < SHEIGHT-50)
	{
	 	this->position.y += deltaTime * 100;
	}
}