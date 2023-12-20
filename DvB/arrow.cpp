// arrow.cpp

#include "arrow.h"

Arrow::Arrow() : Entity()
{
    this->addSprite("assets/arrow.tga");
    this->alive = true;
}


Arrow::~Arrow()
{

}
void Arrow::update(float deltaTime)
{
	this->position.y -= deltaTime * 200;
}