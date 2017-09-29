#include "material.h"

// Constructor
material::material(){
  // Default values (probably looks horrible)
  for( int i = 0; i < 4; i++){
    ambient[i] = 1.0f;
    diffuse[i] = 1.0f;
    specular[i] = 1.0f;
  }
  shininess[0] = 100.0f;

  name = "MATERIAL_NULL";
}


// Destructor
material::~material(){

}

// Ambient
void material::setAmbient( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){
  this -> ambient[0] = red;
  this -> ambient[1] = green;
  this -> ambient[2] = blue;
  this -> ambient[3] = alpha;
}

// Diffuse
void material::setDiffuse( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){
  this -> diffuse[0] = red;
  this -> diffuse[1] = green;
  this -> diffuse[2] = blue;
  this -> diffuse[3] = alpha;
}

// Specular
void material::setSpecular( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha){
  this -> specular[0] = red;
  this -> specular[1] = green;
  this -> specular[2] = blue;
  this -> specular[3] = alpha;
}

// Shininess
void material::setShininess( GLfloat shininess){
  this -> shininess[0] = shininess;
}

// Set as material
void material::changeTo(){
  glMaterialfv( GL_FRONT, GL_AMBIENT  , ambient   );
  glMaterialfv( GL_FRONT, GL_DIFFUSE  , diffuse   );
  glMaterialfv( GL_FRONT, GL_SPECULAR , specular  );
  glMaterialfv( GL_FRONT, GL_SHININESS, shininess );
}
