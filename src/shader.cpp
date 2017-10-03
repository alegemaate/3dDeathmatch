#include "shader.h"

// Init shader
shader::shader(){
  loaded = false;
}

// Loads shader
// ERRORS:
//   0  All good
//   -1 Could not load file
//   -2 Shader could not compile
int shader::loadShader( std::string filename, int type){
  // Assign type
  shader_type = type;

  // Open file
  FILE* file = fopen( filename.c_str(), "rt");
  if( !file)
    return -1;

  // Copy into vector
  std::vector<std::string> lines;
  char sLine[255];
  while(fgets(sLine, 255, file))
    lines.push_back(sLine);
	fclose(file);

  // Copy source over
  const char **shaderSource = new const char*[lines.size()];
  for( int i = 0; i < lines.size(); i++)
    shaderSource[i] = lines[i].c_str();

  // Create shader
  shader_id = glCreateShader( shader_type);

  // Bind and compile source
  glShaderSource( shader_id, lines.size(), shaderSource, NULL);
  glCompileShaderARB( shader_id);

  // Erase shader source
  delete[] shaderSource;

  // Check success
  GLint compiled;
  glGetShaderiv( shader_id, GL_COMPILE_STATUS, &compiled);
  if ( !compiled)
    return -2;

  // Success
  loaded = true;
  return 0;
}

// Delete shader
void shader::unloadShader(GLubyte** ShaderSource){
   if (*ShaderSource != 0)
     delete[] *ShaderSource;
   *ShaderSource = 0;

   loaded = false;
}
