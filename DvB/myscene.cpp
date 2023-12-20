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

	arrows = std::vector<Arrow*>();
	// treelogs = std::vector<Treelog*>();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	Enemy* enemy = new Enemy();
	
	player->position = Point2(SWIDTH/2, SHEIGHT-20);
	enemy->position = Point2(SWIDTH/2,50);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);

	
	//lives = maxlives;

	restart();

	Treelog* log = new Treelog();
	this->addChild(log);
	treelogs.push_back(log);
	log->position = enemy->position;
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete player;

	for (int i = 0; i < arrows.size(); i++) 
    {
		delete arrows[i]; // delete Bullet from the heap (a pointer to it is still in the list)
		arrows[i] = nullptr; // set Bullet pointer to NULL (don't try to remove it from the list)
	}
	arrows.clear(); // list contains only NULL pointers. Empty the list with 1 command.
}

void MyScene::restart()
{
	
	//lives = maxlives;
	//player->position.x = 640;

	//player_bullets.clear();
	

	
}



void MyScene::update(float deltaTime)
{
	HandleInput(deltaTime);
	CheckCollisionArrowLogs();
	CheckCollisionPlayerLogs();
	//CheckCollisionEnemyArrows();
	CleanUptAbles();
	SpawnTreeLogs(deltaTime);
	Zmove(deltaTime);
	logforlog();
	
	
	// if (enemies.empty()) 
	// {
	// 	std::cout << "WELL DONE EARTHLING" << std::endl;
	// 	std::cout << "THIS TIME YOU WIN" << std::endl;
	// 	restart();
	// }
}



void MyScene::CleanUptAbles()
{
	if (arrows.empty()) { return; }
	if (treelogs.empty()) { return; }
	//if (enemies.empty()) { return; }
	
	for (int i = arrows.size()-1; i >= 0; i--)
	{
		if (!arrows[i]->alive)
		{
			this->removeChild(arrows[i]);
			delete arrows[i];
			arrows.erase(arrows.begin() + i);
		}
	}

	for (int i = treelogs.size()-1; i >= 0; i--)
	{
		if (!treelogs[i]->alive)
		{
			this->removeChild(treelogs[i]);
			delete treelogs[i];
			treelogs.erase(treelogs.begin() + i);
		}
	}

	// for (int i = enemies.size()-1; i >= 0; i--)
	// {
	// 	if (!enemies[i]->alive)
	// 	{
	// 		this->removeChild(enemies[i]);
	// 		delete enemies[i];
	// 		enemies.erase(enemies.begin() + i);
	// 	}
	// }
}

void MyScene::SpawnTreeLogs(float deltatime)
{
	if (t.seconds() > 2.0f)
	{
		Treelog* log = new Treelog();
		log->position = Vector2(rand()%SWIDTH, 50);
		this->addChild(log);
		treelogs.push_back(log);
		t.start();
	}
	
	// for (int i = -0; i < 1; i++)
	// {
	// 	Treelog* log = new Treelog();
	// 	this->addChild(log);
	// 	treelogs.push_back(log);
	// 	Vector2 ep = player->position;
	// 	log->position = Vector2(ep.x - (i * 1), SHEIGHT +20);
	// }

	
}

void MyScene::logforlog()
{
	// for (size_t i = 0; i < count; i++)
	// {
	// 	this->
	// }
	
}

void MyScene::CheckCollisionArrowLogs()
{
	for (size_t tl = 0; tl < treelogs.size(); tl++)
	{
		for (size_t ar = 0; ar < arrows.size(); ar++)
		{
			Vector2 diff = treelogs[tl]->position - arrows[ar]->position;
			float distance = diff.getLength();
			if (distance < 90) {
				arrows[ar]->sprite()->color = RED;
				arrows[ar]->alive = false;
				treelogs[tl]->alive = false;
			} else {
				arrows[ar]->sprite()->color = WHITE;
			}
		}
		
	}
	
}

void MyScene::CheckCollisionPlayerLogs()
{
	for (size_t tl = 0; tl < treelogs.size(); tl++)
	{
		Treelog* treelog = treelogs[tl];
		Vector2 diff = treelog->position - player->position;
		float distance = diff.getLength();
		
		if (distance < (treelog->sprite()->width() / 2) + player->sprite()->width() / 2) {
			if(treelog->position.x < player->position.x)
			{
				// player is on the right
				player->position.x = treelog->position.x + (treelog->sprite()->width() / 2) + player->sprite()->width() / 2;
			}
			if(treelog->position.x > player->position.x)
			{
				// player is on the left
				player->position.x = treelog->position.x - (treelog->sprite()->width() / 2) - player->sprite()->width() / 2;
			}
		} else {
			player->sprite()->color = WHITE;
		}
	}	
}

//void MyScene::CheckCollisionEnemyArrows()
//{
	// for (size_t ey = 0; ey < enemies.size(); ey++)
	// {
	// 	for (size_t ars = 0; ars < arrows.size(); ars++)
	// 	{
	// 		Vector2 diff = enemies[ey]->position - arrows[ars]->position;
	// 		float distance = diff.getLength();
	// 		if (distance < 90) {
	// 			arrows[ars]->sprite()->color = RED;
	// 			arrows[ars]->alive = false;
	// 			enemies[ey]->alive = false;
	// 		} else {
	// 			arrows[ars]->sprite()->color = WHITE;
	// 		}
	// 	}
		
	// }
	
//}

void MyScene::HandleInput(float deltaTime)
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
	if (player->position.x > SWIDTH-50)
	{
		player->position.x = SWIDTH-50;
	}
	if (player->position.x < 50)
	{
		player->position.x = 50;
	}
}

void MyScene::Zmove(float deltaTime)
{

	if (input()->getKeyDown( KeyCode::Z )) 
	{
		for (int i = -12; i < 13; i++)
		{
			Arrow* arrow = new Arrow();
			this->addChild(arrow);
			arrows.push_back(arrow);
			Vector2 pp = player->position;
			arrow->position = Vector2(pp.x - (i * 20), SHEIGHT-20);
		}
	}

}