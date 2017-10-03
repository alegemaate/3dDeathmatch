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
#include <vector>
#include <stdio.h>

class shader{
  public:
    shader();
    virtual ~shader() {};

    int loadShader( std::string, int type);
    void unloadShader( GLubyte** ShaderSource);

    GLuint getId(){ return shader_id; }
    GLuint getType(){ return shader_type; }
    bool isLoaded(){ return loaded; }
  protected:

  private:
    GLuint shader_id;
    GLuint shader_type;
    bool loaded;
};

#endif // SHADER_H
