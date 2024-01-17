// gameover.h

#ifndef GAMECLEAR_H
#define GAMECLEAR_H

#include <rt2d/entity.h>

class Gameclear : public Entity
{
public:
	Gameclear();
	virtual ~Gameclear();
/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
private:
	/* add your private declarations */
};

#endif /* GAMEOVER_H */
