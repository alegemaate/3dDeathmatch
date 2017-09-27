/*
  Player
  Allan Legemaate
  21/11/15
  The controllable player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "tools.h"
#include "room.h"
#include "globals.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


class player{
  public:
    player( float newX, float newY, float newZ, float newXRot, float newYRot);
    virtual ~player();

    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }

    float* getPointX() { return &x; }
    float* getPointY() { return &y; }
    float* getPointZ() { return &z; }

    float getXRotation() { return xRotation; }
    float getYRotation() { return yRotation; }

    void transformWorld();

    void render();
    void logic( room *newRoom);
  protected:
  private:
    float x;
    float y;
    float z;
    float xRotation;
    float yRotation;

    float y_velocity;

    bool sprinting;

    BITMAP *image[6];
};

#endif // PLAYER_H
