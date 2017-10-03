#include "model.h"

// Constructor
model::model( mesh newMesh, material newMaterial, GLuint newTexture){
  this -> model_mesh = newMesh;
  this -> model_material = newMaterial;
  this -> model_texture_id = newTexture;
}

// Destructor
model::model(){
  this -> model_texture_id = 0;
}

// Load mesh from file
bool model::loadMesh( const char *path){
  if( !(obj_loader::load( path, model_mesh.vertices, model_mesh.uvs, model_mesh.normals)))
     return false;
  model_mesh.configBuffers();
  return true;
}

// Load texture from file
bool model::loadTexture( const char *path){
  BITMAP *image;
  if( !(image = load_bitmap( path, NULL)))
    return false;
  model_texture_id = allegro_gl_make_texture_ex( AGL_TEXTURE_HAS_ALPHA | AGL_TEXTURE_FLIP, image, GL_RGBA);
  return true;
}

// Set texture from gltexture id
void model::setTexture( GLuint textureId){
  model_texture_id = textureId;
}

// Set material
void model::setMaterial( material newMaterial){
  model_material = newMaterial;
}

// Render to screen
void model::render( float scale){
  // Push in case of scale
  glPushMatrix();
    // Scale
    glScaled( scale, scale, scale);

    // Set material
    model_material.changeTo();

    // Verticies
    glEnableClientState( GL_VERTEX_ARRAY);
    glBindBuffer( GL_ARRAY_BUFFER, model_mesh.vertexbuffer);
    glVertexPointer( 3, GL_FLOAT, sizeof(glm::vec3), NULL);

    // Normals
    glEnableClientState( GL_NORMAL_ARRAY);
    glBindBuffer( GL_ARRAY_BUFFER, model_mesh.normalbuffer);
    glNormalPointer( GL_FLOAT, sizeof(glm::vec3), NULL);

    // Textures
    glEnableClientState( GL_TEXTURE_COORD_ARRAY);
    glBindBuffer( GL_ARRAY_BUFFER, model_mesh.texturebuffer);
    glTexCoordPointer( 2, GL_FLOAT, sizeof(glm::vec2), NULL);
    glBindTexture( GL_TEXTURE_2D, model_texture_id);

    // Send all info to ogl for drawing
    glDrawArrays( GL_TRIANGLES, 0, model_mesh.vertices.size());

    // Disable vbo arrays
    glDisableClientState( GL_VERTEX_ARRAY);
    glDisableClientState( GL_NORMAL_ARRAY);
    glDisableClientState( GL_TEXTURE_COORD_ARRAY);

  // Pop in case of scale
  glPopMatrix();
}
