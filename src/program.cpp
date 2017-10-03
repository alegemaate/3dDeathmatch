#include "program.h"

// Init program
program::program(){
  linked = false;
}

// Setup program with opengl
void program::setup(){
  program_id = glCreateProgram();
}

// Link the program
// ERRORS:
//   0 Success
//   1 Could not link
bool program::link(){
  // Link
  glLinkProgram( program_id);

  // Make sure it is linked
  GLint linkTest;
  glGetProgramiv( program_id, GL_LINK_STATUS, &linkTest);

  // Check for errors
  linked = linkTest == GL_TRUE;
  return linked;
}

// Attach the shaders to the program
// ERRORS:
//   0 Success
//   1 Shader is null
bool program::addShader( shader *newShader){
  // Make sure shader is loaded
  if( !(newShader -> isLoaded()))
    return false;

  glAttachShader( program_id, newShader -> getId());

  return true;
}

// Use this program
void program::use(){
  if( linked)
    glUseProgram( program_id);
}

