/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "player.h"
#include "arrow.h"
#include "treelog.h"
#include "enemy.h"
#include "background.h"
#include "gameclear.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	
	/// @brief a Timer to rotate the color every n seconds

	Timer t;
	Timer shoottimer;
	int lives;
	void updatePlayer();
	void restart();
	Player* player;
	Background* background;
	Gameclear* gameclear;
	
	
	std::vector<Arrow*> arrows;
	std::vector<Treelog*> treelogs;
	std::vector<Enemy*> enemies;

	std::vector<int> xpositions;

	void CheckCollisionArrowLogs();
	void CheckCollisionPlayerLogs();
	void CheckCollisionEnemyArrows();
	void HandleInput(float deltaTime);
	void CleanUptAbles();
	void SpawnTreeLogs(float deltatime);
	void Zmove(float deltaTime);
	void logforlog();
	void gameover();
	void SpawnEnemy();
};

#endif /* SCENE00_H */