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
int stop = 0;

MyScene::MyScene() : Scene()
{
	lives = 3;
	// start the timer.
	t.start();

	arrows = std::vector<Arrow*>();
	treelogs = std::vector<Treelog*>();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	Treelog* treelog = new Treelog();
	//Treelog = new treelog();
	
	player->position = Point2(SWIDTH/2, SHEIGHT-20);
	treelog->position = Point2(SWIDTH/2,0);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(player);
	this->addChild(treelog);

	
	//lives = maxlives;
	;
	restart();
	//player_bullets.clear();
	//enemy_bullets.clear();
	
	for (int i = arrows.size() - 1; i >=0; i--) 
    { // backwards!!!
		if (arrows[i]->position.y < 0) 
        {
            this->removeChild(arrows[i]);
			delete arrows[i]; // delete from the heap first
			arrows.erase(arrows.begin() + i); // then, remove from the list
		}
	}

	for (int i = 0; i < arrows.size(); i++) 
    {
		

	// #############################################################
	// at the very end (close program / delete scene), delete all bullets still in the list
	
	for (int i = 0; i < arrows.size(); i++) 
    {
		
		delete arrows[i]; // delete Bullet from the heap (a pointer to it is still in the list)
		arrows[i] = nullptr; // set Bullet pointer to NULL (don't try to remove it from the list)
	}
	arrows.clear(); // list contains only NULL pointers. Empty the list with 1 command.

	// return 0;
    }
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

// int main(void)
// {
	

// }

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) 
	{
	this->stop();
	}

	if (input()->getKeyDown( KeyCode::Space )) 
	{
		Arrow* arrow = new Arrow();
		this->addChild(arrow);
		arrows.push_back(arrow);
		arrow->position = player->position; 	
	}

	if (input()->getKey(KeyCode::Left)) 
	{
		player->position.x -= speed*deltaTime;
	}

	
		
	
	if (input()->getKey(KeyCode::Right)) 
	{
		player->position.x += speed*deltaTime;
	}
	
	
	
}