// player.cpp

#include "player.h"
Player* player;
Player::Player(): Entity()
{
	this->addSprite("assets/square.tga");
}

Player::~Player()
{
		
	// if ( epos.x > left && epos.x < right && epos.y < top && epos.y > bottom ) 
	// {
	// 		lives--;
	// 		std::cout << "PLAYER HIT! lives: " << lives << std::endl;
	// 		canvas->clearSprite(player);


	// 		it = enemy_bullets.erase(it);
	// } 
	// else 
	// {
	// 	++it;
	// }
}

void Player::update(float deltaTime)
{
	// this->position.x += deltaTime; // 90 deg/sec
	
}