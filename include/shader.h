/*
  Shader
  Allan Legemaate
  29/09/2017
  Shader to be attatched to a program
*/

#ifndef SHADER_H
#define SHADER_H

#include <alleggl.h>
#include <string>
#include <fstream>

#include "tools.h"

class shader{
  public:
    shader();
    virtual ~shader();

    int loadShader(char *filename, GLchar **ShaderSource, GLint *len);
    int unloadShader(GLubyte** ShaderSource);

    void setupShader( std::string shaderFile, int type);

    GLuint getId(){ return shader_id; }
  protected:

  private:
    GLuint shader_id;
    UINT shader_type;
    bool loaded;
};

#endif // SHADER_H
