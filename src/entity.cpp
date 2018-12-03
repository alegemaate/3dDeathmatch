#include "entity.h"

entity::entity(float x, float y, float z, float x_rot, float y_rot) {
  this -> x = x;
  this -> y = y;
  this -> z = z;
  this -> x_rot = x_rot;
  this -> y_rot = y_rot;
}

entity::~entity() {
  //dtor
}
