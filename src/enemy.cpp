#include "enemy.h"

enemy::enemy(float x, float y, float z, float x_rot, float y_rot) :
  entity(x, y, z, x_rot, y_rot) {
  //ctor
}

enemy::~enemy() {
  //dtor
}

void enemy::render() {
  changeMaterial("MATERIAL_DEFAULT");
  glBindTexture(GL_TEXTURE_2D, 3);

  glPushMatrix();
    glTranslatef(-x, -y, -z);
    quick_primatives::cube(1, 0);
  glPopMatrix();
}

void enemy::logic(room *newRoom) {
  x += 0.001;
}
