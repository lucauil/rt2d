// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);


private:
	/* add your private declarations */
};

#endif /* PLAYER_H */
