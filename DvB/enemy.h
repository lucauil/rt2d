// enemy.h

#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>

class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

bool alive;

private:
	/* add your private declarations */
};

#endif /* ENEMY_H */
