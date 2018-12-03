#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include "tools.h"
#include "room.h"
#include "globals.h"


#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class entity {
  public:
    entity(float x, float y, float z, float x_rot, float y_rot);
    virtual ~entity();

    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }

    float* getPointX() { return &x; }
    float* getPointY() { return &y; }
    float* getPointZ() { return &z; }

    float getXRotation() { return x_rot; }
    float getYRotation() { return y_rot; }

    virtual void render() = 0;
    virtual void logic(room *newRoom) = 0;

  protected:
    float x;
    float y;
    float z;
    float x_rot;
    float y_rot;
};

#endif // ENTITY_H
