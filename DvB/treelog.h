// treelog.h

#ifndef TREELOG_H
#define TREELOG_H

#include <rt2d/entity.h>

class Treelog : public Entity
{
public:
	Treelog();
	virtual ~Treelog();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* TREELOG_H */
