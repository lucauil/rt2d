#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>

class Background : public Entity
{
    public:
    //constructor
    Background();
    //destructor
    virtual ~Background();

    void update(float deltaTime) override;

    private:
    //add your private declarations
};

#endif