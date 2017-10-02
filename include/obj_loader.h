/*
  OBJ Loader
  Allan Legemaate
  02/10/17
  Loads obj from file
*/

#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <stdio.h>
#include <cstring>

class obj_loader{
  public:
    obj_loader() { };
    virtual ~obj_loader() { };

    static bool load( const char * path, std::vector < glm::vec3 > & out_vertices, std::vector < glm::vec2 > & out_uvs, std::vector < glm::vec3 > & out_normals);
  protected:

  private:
};

#endif // OBJ_LOADER_H
