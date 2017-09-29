/*
  Program
  Allan Legemaate
  29/09/2017
  Program to be bound/unbound
*/

#ifndef PROGRAM_H
#define PROGRAM_H

#include "shader.h"
#include "tools.h"

class program{
  public:
    program();
    virtual ~program() {};

    void setup();
    bool link();
    bool addShader( shader *newShader);
    void use();
  protected:

  private:
    GLuint vertex_shader, fragment_shader;
    GLuint program_id;
    bool linked;
};

#endif // PROGRAM_H
