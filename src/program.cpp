#include "program.h"

// Init program
program::program(){
  linked = false;
}

program::~program(){
  //dtor
}

// Use the program
void program::use(){
  glUseProgram( program_id);
}

// Link the program
void program::link(){
  // Link the program
  glLinkProgram( program_id);

  // Make sure it is linked
  GLint linked;
  glGetProgramiv(program_id, GL_LINK_STATUS, &linked);

  // Error checking
  if (!linked)
    abort_on_error( ("Program " + convertIntToString(program_id) + "didnt link...").c_str());
  else
    std::cout << "Program " << program_id << " linked!\n\n";
}

// Attatch the shaders to the program
void program::addShader( shader *newShader){
  glAttachShader( program_id, newShader -> getId());
}


// Setup program
void program::setup(){
  program_id = glCreateProgram();
}
