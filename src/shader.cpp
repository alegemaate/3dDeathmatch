#include "shader.h"



// Init shader
shader::shader(){
  loaded = false;
}

shader::~shader(){ }

// Load shader from file
int shader::loadShader(char *filename, GLchar **ShaderSource, GLint *len){
  std::ifstream file;
  file.open(filename, std::ios::in); // opens as ASCII!

  if(!fexists(filename))
    return -1; // Error: No file

  GLint fileLength = getFileLength(file);
  *len = fileLength;

  if (*len == 0)
    return -2;   // Error: Empty File

  char *tShaderSource = (GLchar*)new char[*len+1]();

  // can't reserve memory
  if (tShaderSource == 0)
    return -3;

  // len isn't always strlen cause some characters are stripped in ascii read...
  // it is important to 0-terminate the real length later, len is just max possible value...
  tShaderSource[*len] = '\0';

  unsigned int i = 0;
  while (file.good()){
    tShaderSource[i] = file.get();     // get character from file.
    if (!file.eof())
      i++;
  }
  tShaderSource[i] = '\0';  // 0-terminate it at the correct position

  file.close();

  *ShaderSource = tShaderSource;

  return 0; // No Error
}

// Delete shader
int shader::unloadShader(GLubyte** ShaderSource){
   if (*ShaderSource != 0)
     delete[] *ShaderSource;
   *ShaderSource = 0;
   loaded = false;
}

void shader::setupShader( std::string shaderFile, int type){
  // Assign type
  shader_type = type;

  // Create a blank source and length
  GLchar *shaderSource;
  GLint shaderFileLength;

  // Convert from string to char*
  char *charShaderFile = const_cast<char*> ( shaderFile.c_str() );

  // Load them!
  if( loadShader( charShaderFile, &shaderSource, &shaderFileLength) != 0)
    abort_on_error((shaderFile + " NOT found!").c_str());
  else
    std::cout << shaderFile << " found\n";

  // Create shader
  shader_id = glCreateShader( shader_type);

  // Bind source
  glShaderSource( shader_id, 1, const_cast<const GLcharARB**>(&shaderSource), &shaderFileLength);

  // Compile them
  glCompileShaderARB( shader_id);

  // Check success
  GLint compiled;
  glGetShaderiv( shader_id, GL_COMPILE_STATUS, &compiled);
  if (!compiled)
     abort_on_error( ("Dude, " + shaderFile + " didnt compile...").c_str());
  else
    std::cout << shaderFile << " shader compiled!\n";

  // Done deal!
  loaded = true;
}
