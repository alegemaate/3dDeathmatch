#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

#include "quick_primatives.h"

class enemy  : public entity {
  public:
    enemy(float x, float y, float z, float x_rot, float y_rot);
    virtual ~enemy();

    virtual void render() override;
    virtual void logic(room *newRoom) override;
  protected:

  private:
};

#endif // ENEMY_H
