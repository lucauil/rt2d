// arrow.h

#ifndef ARROW_H
#define ARROW_H

#include <rt2d/entity.h>

class Arrow : public Entity
{
public:
	Arrow();
	virtual ~Arrow();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* ARROW_H */
