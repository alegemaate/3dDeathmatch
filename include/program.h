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
    virtual ~program();

    void setup();
    void addShader( shader *newShader);
    void link();
    void use();
  protected:

  private:
    GLuint vertexShader, fragmentShader;
    int program_id;
    bool linked;
};

#endif // PROGRAM_H
