/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

bool left;
bool right;
int speed = 200;

MyScene::MyScene() : Scene()
{
	lives = 3;
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	
	player->position = Point2(SWIDTH/2, SHEIGHT);
	

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(player);

	
	//lives = maxlives;
	;
	restart();
	//player_bullets.clear();
	//enemy_bullets.clear();
	
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete player;
}
void MyScene::restart()
{
	
	//lives = maxlives;
	//player->position.x = 640;

	//player_bullets.clear();
	

	
}
void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// if (input()->getKey( KeyCode::Space )) 
	// {
	 	
	//  	arrow = new Arrow();

	// 	arrow->posistion.y += 2f*deltaTime;
	 	
	// }

	

	if (input()->getKey(KeyCode::Left)) 
	{
		player->position.x -= speed*deltaTime;
	}
	if (input()->getKey(KeyCode::Right)) 
	{
		player->position.x += speed*deltaTime;
	}
}