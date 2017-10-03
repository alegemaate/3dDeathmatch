/*
  Mesh
  Allan Legemaate
  02/07/16
  A nice class that stores vertices, uvs and normals of a mesh
*/

#ifndef MESH_H
#define MESH_H

#include <alleggl.h>
#include <vector>
#include <alleggl.h>
#include <GLM/GLM.hpp>

class mesh{
  public:
    mesh();
    virtual ~mesh() { };

    std::vector< glm::vec3 > vertices;
    std::vector< glm::vec2 > uvs;
    std::vector< glm::vec3 > normals;

    GLuint vertexbuffer;
    GLuint normalbuffer;
    GLuint texturebuffer;

    void configBuffers();
  protected:
  private:
};

#endif // MESH_H
