#include "model.h"

// Init
model::model(){
  // Set to 0
  vertexbuffer = 0;
  normalbuffer = 0;
  texturebuffer = 0;
  texture_id = 0;
}

model::~model(){ }

// Load model
bool model::load( const char * path, const char * uv_path){
  if( model_loader::load_model( path, vertices, uvs, normals)){
    //vertices
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    //uvs
    glGenBuffers(1, &texturebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

    //normals
    glGenBuffers(1, &normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);


    // Image
    // Load image
    if( uv_path != "NULL"){
      BITMAP *image;
      if( !(image = load_bitmap( uv_path, NULL)))
        return false;
      texture_id = allegro_gl_make_texture_ex( AGL_TEXTURE_HAS_ALPHA | AGL_TEXTURE_FLIP, image, GL_RGBA);
    }

    return true;
  }
  return false;
}
