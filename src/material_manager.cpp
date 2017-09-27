#include "material_manager.h"

int currentMaterial = 0;

// Colours and properties of materials
void changeMaterial( int material){
  // DEFAULT
  if( material == MATERIAL_DEFAULT){
    GLfloat mat_ambient[] = { 0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat mat_diffuse[]  ={ 0.55f, 0.55f, 0.55f, 1.0f};
    GLfloat mat_specular[] = { 0.45f, 0.55f, 0.50f, 1.0f};
    GLfloat mat_shininess[] = { 20.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    currentMaterial = MATERIAL_DEFAULT;
  }
  // COPPER
  else if( material == MATERIAL_COPPER){
    GLfloat mat_ambient[] = { 0.16f, 0.09f, 0.00f, 1.0f};
    GLfloat mat_diffuse[]  ={ 0.85f, 0.46f, 0.14f, 1.0f};
    GLfloat mat_specular[] = { 1.0f, 0.7f, 0.1f, 1.0f};
    GLfloat mat_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    currentMaterial = MATERIAL_COPPER;
  }
  // WATER
  else if( material == MATERIAL_WATER){
    GLfloat mat_ambient[] = { 0.25f, 0.25f, 0.25f, 1.0f};
    GLfloat mat_diffuse[]  ={ 0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat mat_specular[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f};
    GLfloat mat_shininess[] = { 0.6f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    currentMaterial = MATERIAL_WATER;
  }
}
