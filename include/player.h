/*
  Player
  Allan Legemaate
  21/11/15
  The controllable player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class player : public entity {
  public:
    player (float x, float y, float z, float x_rot, float y_rot);
    virtual ~player();

    void transformWorld();

    void load_images();

    void render2D(BITMAP *tempBuf);

    virtual void render() override;
    virtual void logic(room *newRoom) override;
  protected:
  private:
    float y_velocity;

    bool sprinting;

    BITMAP *image[6];
    BITMAP *weapon_images[3];
};

#endif // PLAYER_H
