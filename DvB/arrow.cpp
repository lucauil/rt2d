// arrow.cpp

#include "arrow.h"

Arrow::Arrow() : Entity()
{
    this->addSprite("assets/arrow.tga");
}


Arrow::~Arrow()
{

}
void Arrow::update(float deltaTime)
{
	this->position.y -= deltaTime * 200;
}