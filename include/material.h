/*
  Material
  Allan Legemaate
  29/09/2017
  Holds all the shading information for materials
*/

#ifndef MATERIAL_H
#define MATERIAL_H

#include <alleggl.h>
#include <string>

class material{
  public:
    // Construct and destruct
    material();
    virtual ~material();

    // Sets levels
    void setAmbient( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void setDiffuse( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void setSpecular( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void setShininess( GLfloat shininess);

    // Sets as current material
    void changeTo();

    // Set name
    void setName( std::string name){ this -> name = name; }
    std::string getName(){ return this -> name; }
  protected:

  private:
    // Stores levels
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess[1];

    // Name
    std::string name;
};

#endif // MATERIAL_H
