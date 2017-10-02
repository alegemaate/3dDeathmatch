#include "player.h"

player::player( float newX, float newY, float newZ, float newXRot, float newYRot){
  x = newX;
  y = newY;
  z = newZ;
  xRotation = newXRot;
  yRotation = newYRot;

  y_velocity = 0;
  sprinting = false;
  for( int i = 0; i < 3; i++)
    weapon_images[i] = nullptr;
}

player::~player(){

}

// Apply world transformations to players
// Perspective
void player::transformWorld(){
  glRotatef( xRotation, 1.0, 0.0, 0.0 );
  glRotatef( yRotation, 0.0, 1.0, 0.0 );
  glTranslatef( -x, -y, -z);

  // Place light 0 Back to normal
  GLfloat light_position[] = { 0.0f - x, 3.0f - y, 0.0f - z, 0.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

// Load images
void player::load_images(){
  BITMAP *temp_weapons;

  if( !(temp_weapons = load_bitmap( "images/gun.png", NULL)))
    abort_on_error("Could not laod temp_weapons");

  for( int i = 0; i < 3; i++){
    weapon_images[i] = create_bitmap( 180, 200);
    blit( temp_weapons, weapon_images[i], 180 * i, 0, 0, 0, 180, 200);
  }
}

// Draw tile
void player::render(){
  // Nothing.. YET EHHEAHAEH
}

// Draw tile
void player::render2D( BITMAP *tempBuf){
  // Shootemup
  bool shooting = false;
  if( mouse_b & 1 || key[KEY_SPACE])
    shooting = true;

  if( weapon_images[0 + 2 * shooting])
    draw_sprite( tempBuf, weapon_images[0 + 2 * shooting], SCREEN_W/2 + 90 - weapon_images[0 + 2 * shooting] -> w/2, SCREEN_H - weapon_images[0 + 2 * shooting] -> h);
}

// Move character and such
void player::logic( room *newRoom){
  // Move, slower in gamemode
  // Sprint
  if( key[KEY_LSHIFT])
    sprinting = true;
  else
    sprinting = false;

  // Pan around
  yRotation -= SCREEN_W/2 - mouse_x;
  xRotation -= SCREEN_H/2 - mouse_y;

  // No backflips!
  if( xRotation > 90)
    xRotation = 90;
  else if( xRotation < -90)
    xRotation = -90;

  // Reset spinning amount
  if( yRotation >= 360)
    yRotation -= 360;
  else if( yRotation < 0)
    yRotation += 360;

  // Reset mouse pos
  position_mouse( SCREEN_W/2, SCREEN_H/2);

  // LEFT 1 RIGHT 2 FRONT 3 BACK 4
  bool canMoveXPLUS  = true;
  bool canMoveXMINUS = true;
  bool canMoveZPLUS  = true;
  bool canMoveZMINUS = true;

  // Vars
  float yChange = -((float)sin(xRotation / 180 * M_PI)/(5 + 10 * gameMode) * (sprinting + 1));
  if( gameMode)
    yChange = 0;
  float xChange =  (float)sin(yRotation / 180 * M_PI)/(5 + 10 * gameMode) * (sprinting + 1);
  float zChange = -(float)cos(yRotation / 180 * M_PI)/(5 + 10 * gameMode) * (sprinting + 1);

  // Forward
  if( key[KEY_W] || key[KEY_UP]){
    if( !gameMode)
      y += yChange;
    if( !gameMode || (zChange < 0 && canMoveZMINUS) || (zChange > 0 && canMoveZPLUS))
      z += zChange;
    if( !gameMode || (xChange < 0 && canMoveXMINUS) || (xChange > 0 && canMoveXPLUS))
      x += xChange;
  }
  // Backward
  if( key[KEY_S] || key[KEY_DOWN]){
    if( !gameMode)
      y -= yChange;
    if( !gameMode || (zChange > 0 && canMoveZMINUS) || (zChange < 0 && canMoveZPLUS))
      z -= zChange;
    if( !gameMode || (xChange > 0 && canMoveXMINUS) || (xChange < 0 && canMoveXPLUS))
      x -= xChange;
  }
  // Left
  if( key[KEY_A] || key[KEY_LEFT]){
    if( !gameMode || (xChange > 0 && canMoveZMINUS) || (xChange < 0 && canMoveZPLUS))
      z -= xChange;
    if( !gameMode || (zChange < 0 && canMoveXMINUS) || (zChange > 0 && canMoveXPLUS))
      x += zChange;
  }
  // Right
  if( key[KEY_D] || key[KEY_RIGHT]){
    if( !gameMode || (xChange < 0 && canMoveZMINUS) || (xChange > 0 && canMoveZPLUS))
      z += xChange;
    if( !gameMode || (zChange > 0 && canMoveXMINUS) || (zChange < 0 && canMoveXPLUS))
      x -= zChange;
  }

  // Game mode
  if( key[KEY_G]){
    if( !gameMode){
      x = 0;
      y = 1;
      z = 0;
    }
    xRotation = 45;
    yRotation = 135;

    gameMode = !gameMode;
    rest( 300);
  }
}
