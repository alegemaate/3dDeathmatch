#include "room.h"

// Construct
room::room( BITMAP *tempBuffer){
  // Start in view mode
  gameMode = false;

  // Load tiles
  all_tile_defs.load( "data/tiles.xml");

  // Buffer
  buffPoint = tempBuffer;

  // Load models
  if( !(model_statue.loadMesh("models/statue.obj") && model_statue.loadTexture("models/statue_uv.png")))
    abort_on_error( "couldn't load the model!");

  model_statue.setMaterial( materials.at(getMaterial("MATERIAL_COPPER")));
}

// Deconstruct
room::~room(){

}

// Check if tile is on screen
bool room::onScreen( int tile_x, int tile_y, int tile_z){
  return false;
}

// Load images for tiles
void room::load_images(){

}

// Update map
void room::update(){
  //Gen
  if(key[KEY_R]){
    generateRoom();
  }
}

// Procedural Generation of map
void room::generateRoom(){
  // GENERATE ROOM
  std::cout << "   GENERATING ROOM\n-----------------------\n";

  this -> width = 32;
  this -> height = 8;
  this -> length = 16;

  // Done!
  quickPeek( "Done!");

  std::cout << "\n\n";
}

// Quick Peek
void room::quickPeek( std::string currentPhase){
  // Send to console
  std::cout << "PHASE:" << currentPhase.c_str() << "\n";

  // View matrix
  glMatrixMode(GL_MODELVIEW);

  // Clear screen
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw tiles
  draw();

  // Allegro drawing
  allegro_gl_set_allegro_mode();

  // Transparent buffer
  rectfill( buffPoint, 0, 0, SCREEN_W, SCREEN_H, makecol( 255, 0, 255));

  // Info
  textprintf_centre_ex( buffPoint, font, SCREEN_W/2, SCREEN_H/2, makecol(0,0,0), makecol(255,255,255), "%s", currentPhase.c_str());

  // Draw to screen
  draw_sprite( screen, buffPoint, 0, 0);

  allegro_gl_unset_allegro_mode();
  allegro_gl_flip();
}

//Draw map
void room::draw(){
  changeMaterial( "MATERIAL_DEFAULT");
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // Floor
  glPushMatrix();
  changeMaterial( "MATERIAL_DEFAULT");
  glBindTexture( GL_TEXTURE_2D, 3);
  glTranslatef( 0, 0, 0);
  quick_primatives::h_plane( this -> width, this -> length);
  glPopMatrix();

  // Ceiling
  glPushMatrix();
  changeMaterial( "MATERIAL_DEFAULT");
  glBindTexture( GL_TEXTURE_2D, 4);
  glTranslatef( 0, this -> height, 0);
  quick_primatives::h_plane( this -> width, this -> length);
  glPopMatrix();

  // Wall 1
  glPushMatrix();
  //glBindTexture(GL_TEXTURE_2D, 2);
  glTranslatef( 0, this -> height/2, this -> length/2);
  quick_primatives::v_plane( this -> width, this -> height, 0);
  glPopMatrix();

  // Wall 2
  glPushMatrix();
  glTranslatef( 0, this -> height/2, -(this -> length/2));
  quick_primatives::v_plane( this -> width, this -> height, 0);
  glPopMatrix();

  // Wall 3
  glPushMatrix();
  glTranslatef( this -> width/2, this -> height/2, 0);
  quick_primatives::v_plane( this -> length, this -> height, 90);
  glPopMatrix();

  // Wall 4
  glPushMatrix();
  glTranslatef( -(this -> width/2), this -> height/2, 0);
  quick_primatives::v_plane( this -> length, this -> height, 90);
  glPopMatrix();

  // Statue
  glPushMatrix();
    glTranslatef( 0.0f, 0.0f, 0.0f);
    model_statue.render( 0.4f);
  glPopMatrix();
}
