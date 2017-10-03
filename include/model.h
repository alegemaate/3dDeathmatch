/*
  Model
  Allan Legemaate
  02/10/17
  Contains a mesh, texture and material
*/

#ifndef MODEL_H
#define MODEL_H

#include <mesh.h>
#include <material.h>
#include "obj_loader.h"

class model{
  public:
    model( mesh newMesh, material newMaterial, GLuint newTexture);
    model();
    virtual ~model() {};

    bool loadMesh( const char *path);
    bool loadTexture( const char *path);
    void setTexture( GLuint textureId);
    void setMaterial( material newMaterial);

    void render( float scale);
  protected:

  private:
    mesh model_mesh;
    material model_material;
    GLuint model_texture_id;
};

#endif // MODEL_H
