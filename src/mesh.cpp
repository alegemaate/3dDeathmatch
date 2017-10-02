#include "mesh.h"

// Init
mesh::mesh(){
  // Set to 0
  vertexbuffer = 0;
  normalbuffer = 0;
  texturebuffer = 0;
}

// Load mesh
void mesh::configBuffers(){
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
}
