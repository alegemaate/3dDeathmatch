#include "quick_primatives.h"

quick_primatives::quick_primatives(){

}

quick_primatives::~quick_primatives(){
  //dtor
}

// Resizable Cube
void quick_primatives::cube( float primative_size, float roundness){
  // Size / 2
  float temp_size = (primative_size / 2);

  float temp_round_top = roundness;
  float temp_round_bottom = 1 - roundness;

  glBegin(GL_TRIANGLES);
    // FRONT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,temp_round_top,1); glTexCoord2f(0, 0); glVertex3f( -temp_size, temp_size, temp_size );  //C
    glNormal3f(0,temp_round_bottom,1); glTexCoord2f(1, 0); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(0,temp_round_bottom,1); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, temp_size );  //B

    glNormal3f(0,temp_round_top,1); glTexCoord2f(0, 0); glVertex3f( -temp_size, temp_size, temp_size ); //C
    glNormal3f(0,temp_round_bottom,1); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, temp_size ); //B
    glNormal3f(0,temp_round_top,1); glTexCoord2f(0, 1); glVertex3f( temp_size, temp_size, temp_size ); //D

    // BACK
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,temp_round_top,-1); glTexCoord2f(0, 0); glVertex3f( temp_size, temp_size, -temp_size ); //H
    glNormal3f(0,temp_round_bottom,-1); glTexCoord2f(1, 0); glVertex3f( temp_size, -temp_size, -temp_size ); //F
    glNormal3f(0,temp_round_bottom,-1); glTexCoord2f(1, 1); glVertex3f( -temp_size, -temp_size, -temp_size ); //E

    glNormal3f(0,temp_round_top,-1); glTexCoord2f(0, 0); glVertex3f( temp_size, temp_size, -temp_size ); //H
    glNormal3f(0,temp_round_bottom,-1); glTexCoord2f(1, 1); glVertex3f( -temp_size, -temp_size, -temp_size ); //E
    glNormal3f(0,temp_round_top,-1); glTexCoord2f(0, 1); glVertex3f( -temp_size, temp_size, -temp_size ); //G

    // RIGHT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(1,temp_round_top,0); glTexCoord2f(0, 0); glVertex3f( temp_size, temp_size, temp_size ); //D
    glNormal3f(1,temp_round_bottom,0); glTexCoord2f(1, 0); glVertex3f( temp_size, -temp_size, temp_size );  //B
    glNormal3f(1,temp_round_bottom,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F

    glNormal3f(1,temp_round_top,0); glTexCoord2f(0, 0); glVertex3f( temp_size, temp_size, temp_size ); //D
    glNormal3f(1,temp_round_bottom,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F
    glNormal3f(1,temp_round_top,0); glTexCoord2f(0, 1); glVertex3f( temp_size, temp_size, -temp_size ); //H

    // LEFT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(-1,temp_round_top,0); glTexCoord2f(0, 0); glVertex3f(  -temp_size, temp_size, -temp_size ); //G
    glNormal3f(-1,temp_round_bottom,0); glTexCoord2f(1, 0); glVertex3f(  -temp_size, -temp_size, -temp_size ); //E
    glNormal3f(-1,temp_round_bottom,0); glTexCoord2f(1, 1); glVertex3f(  -temp_size, -temp_size, temp_size ); //A

    glNormal3f(-1,temp_round_top,0); glTexCoord2f(0, 0); glVertex3f( -temp_size, temp_size, -temp_size ); //G
    glNormal3f(-1,temp_round_bottom,0); glTexCoord2f(1, 1); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(-1,temp_round_top,0); glTexCoord2f(0, 1); glVertex3f( -temp_size, temp_size, temp_size ); //C

    // BOTTOM
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,-1,0); glTexCoord2f(0, 0); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(0,-1,0); glTexCoord2f(1, 0); glVertex3f(  -temp_size, -temp_size, -temp_size ); //E
    glNormal3f(0,-1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F

    glNormal3f(0,-1,0); glTexCoord2f(0, 0); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(0,-1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F
    glNormal3f(0,-1,0); glTexCoord2f(0, 1); glVertex3f( temp_size, -temp_size, temp_size ); //B

    // TOP
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,1,0); glTexCoord2f(0, 0); glVertex3f(  -temp_size, temp_size, -temp_size ); //G
    glNormal3f(0,1,0); glTexCoord2f(1, 0); glVertex3f( -temp_size, temp_size, temp_size ); //C
    glNormal3f(0,1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, temp_size, temp_size ); //D

    glNormal3f(0,1,0); glTexCoord2f(0, 0); glVertex3f(  -temp_size, temp_size, -temp_size ); //G
    glNormal3f(0,1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, temp_size, temp_size ); //D
    glNormal3f(0,1,0); glTexCoord2f(0, 1); glVertex3f( temp_size, temp_size, -temp_size ); //H
  glEnd();
}

// Flat cube
void quick_primatives::cube_flat( float primative_size){
  // Size / 2
  float temp_size = (primative_size / 2);

  glBegin(GL_TRIANGLES);
    // FRONT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,0,1); glTexCoord2f(0, 0); glVertex3f( -temp_size, -(temp_size-0.1), temp_size );  //C
    glNormal3f(0,0,1); glTexCoord2f(1, 0); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(0,0,1); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, temp_size );  //B

    glNormal3f(0,0,1); glTexCoord2f(0, 0); glVertex3f( -temp_size, -(temp_size-0.1), temp_size ); //C
    glNormal3f(0,0,1); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, temp_size ); //B
    glNormal3f(0,0,1); glTexCoord2f(0, 1); glVertex3f( temp_size, -(temp_size-0.1), temp_size ); //D

    // BACK
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,0,-1); glTexCoord2f(0, 0); glVertex3f( temp_size, -(temp_size-0.1), -temp_size ); //H
    glNormal3f(0,0,-1); glTexCoord2f(1, 0); glVertex3f( temp_size, -temp_size, -temp_size ); //F
    glNormal3f(0,0,-1); glTexCoord2f(1, 1); glVertex3f( -temp_size, -temp_size, -temp_size ); //E

    glNormal3f(0,0,-1); glTexCoord2f(0, 0); glVertex3f( temp_size, -(temp_size-0.1), -temp_size ); //H
    glNormal3f(0,0,-1); glTexCoord2f(1, 1); glVertex3f( -temp_size, -temp_size, -temp_size ); //E
    glNormal3f(0,0,-1); glTexCoord2f(0, 1); glVertex3f( -temp_size, -(temp_size-0.1), -temp_size ); //G

    // RIGHT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(1,0,0); glTexCoord2f(0, 0); glVertex3f( temp_size, -(temp_size-0.1), temp_size ); //D
    glNormal3f(1,0,0); glTexCoord2f(1, 0); glVertex3f( temp_size, -temp_size, temp_size );  //B
    glNormal3f(1,0,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F

    glNormal3f(1,0,0); glTexCoord2f(0, 0); glVertex3f( temp_size, -(temp_size-0.1), temp_size ); //D
    glNormal3f(1,0,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F
    glNormal3f(1,0,0); glTexCoord2f(0, 1); glVertex3f( temp_size, -(temp_size-0.1), -temp_size ); //H

    // LEFT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(-1,0,0); glTexCoord2f(0, 0); glVertex3f(  -temp_size, -(temp_size-0.1), -temp_size ); //G
    glNormal3f(-1,0,0); glTexCoord2f(1, 0); glVertex3f(  -temp_size, -temp_size, -temp_size ); //E
    glNormal3f(-1,0,0); glTexCoord2f(1, 1); glVertex3f(  -temp_size, -temp_size, temp_size ); //A

    glNormal3f(-1,0,0); glTexCoord2f(0, 0); glVertex3f( -temp_size, -(temp_size-0.1), -temp_size ); //G
    glNormal3f(-1,0,0); glTexCoord2f(1, 1); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(-1,0,0); glTexCoord2f(0, 1); glVertex3f( -temp_size, -(temp_size-0.1), temp_size ); //C

    // BOTTOM
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,-1,0); glTexCoord2f(0, 0); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(0,-1,0); glTexCoord2f(1, 0); glVertex3f(  -temp_size, -temp_size, -temp_size ); //E
    glNormal3f(0,-1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F

    glNormal3f(0,-1,0); glTexCoord2f(0, 0); glVertex3f( -temp_size, -temp_size, temp_size ); //A
    glNormal3f(0,-1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -temp_size, -temp_size ); //F
    glNormal3f(0,-1,0); glTexCoord2f(0, 1); glVertex3f( temp_size, -temp_size, temp_size ); //B

    // TOP
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,1,0); glTexCoord2f(0, 0); glVertex3f(  -temp_size, -(temp_size-0.1), -temp_size ); //G
    glNormal3f(0,1,0); glTexCoord2f(1, 0); glVertex3f( -temp_size, -(temp_size-0.1), temp_size ); //C
    glNormal3f(0,1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -(temp_size-0.1), temp_size ); //D

    glNormal3f(0,1,0); glTexCoord2f(0, 0); glVertex3f(  -temp_size, -(temp_size-0.1), -temp_size ); //G
    glNormal3f(0,1,0); glTexCoord2f(1, 1); glVertex3f( temp_size, -(temp_size-0.1), temp_size ); //D
    glNormal3f(0,1,0); glTexCoord2f(0, 1); glVertex3f( temp_size, -(temp_size-0.1), -temp_size ); //H
  glEnd();
}


void quick_primatives::double_plane( float primative_size){
  glBegin(GL_TRIANGLES);
    // SIDE 1 FRONT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, 0.25 );  //C
    glNormal3f(1,0,1); glTexCoord2f(0, 0); glVertex3f( -0.25, -0.5, 0.25 ); //A
    glNormal3f(1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, -0.25 );  //B

    glNormal3f(1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, 0.25 ); //C
    glNormal3f(1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, -0.25 ); //B
    glNormal3f(1,0,1); glTexCoord2f(1, 1); glVertex3f( 0.25, 0.5, -0.25 ); //D

    // SIDE 1 BACK
    glColor4ub(255, 255, 255, 255);
    glNormal3f(-1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, 0.25 );  //C
    glNormal3f(-1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, -0.25 );  //B
    glNormal3f(-1,0,-1); glTexCoord2f(0, 0); glVertex3f( -0.25, -0.5, 0.25 ); //A

    glNormal3f(-1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, 0.25 ); //C
    glNormal3f(-1,0,-1); glTexCoord2f(1, 1); glVertex3f( 0.25, 0.5, -0.25 ); //D
    glNormal3f(-1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, -0.25 ); //B


    // SIDE 2 FRONT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(-1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, -0.25 );  //C
    glNormal3f(-1,0,1); glTexCoord2f(0, 0); glVertex3f( -0.25, -0.5, -0.25 ); //A
    glNormal3f(-1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, 0.25 );  //B

    glNormal3f(-1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, -0.25 ); //C
    glNormal3f(-1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, 0.25 ); //B
    glNormal3f(-1,0,1); glTexCoord2f(1, 1); glVertex3f( 0.25, 0.5, 0.25 ); //D

    // SIDE 2 BACK
    glColor4ub(255, 255, 255, 255);
    glNormal3f(1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, -0.25 );  //C
    glNormal3f(1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, 0.25 );  //B
    glNormal3f(1,0,-1); glTexCoord2f(0, 0); glVertex3f( -0.25, -0.5, -0.25 ); //A

    glNormal3f(1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.25, 0.5, -0.25 ); //C
    glNormal3f(1,0,-1); glTexCoord2f(1, 1); glVertex3f( 0.25, 0.5, 0.25 ); //D
    glNormal3f(1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.25, -0.5, 0.25 ); //B
  glEnd();
}


void quick_primatives::double_plane_tall( float primative_size){
  glBegin(GL_TRIANGLES);
    // SIDE 1 FRONT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, 0.5 );  //C
    glNormal3f(1,0,1); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, 0.5 ); //A
    glNormal3f(1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, -0.5 );  //B

    glNormal3f(1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, 0.5 ); //C
    glNormal3f(1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, -0.5 ); //B
    glNormal3f(1,0,1); glTexCoord2f(1, 1); glVertex3f( 0.5, 2.5, -0.5 ); //D

    // SIDE 1 BACK
    glColor4ub(255, 255, 255, 255);
    glNormal3f(-1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, 0.5 );  //C
    glNormal3f(-1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, -0.5 );  //B
    glNormal3f(-1,0,-1); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, 0.5 ); //A

    glNormal3f(-1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, 0.5 ); //C
    glNormal3f(-1,0,-1); glTexCoord2f(1, 1); glVertex3f( 0.5, 2.5, -0.5 ); //D
    glNormal3f(-1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, -0.5 ); //B


    // SIDE 2 FRONT
    glColor4ub(255, 255, 255, 255);
    glNormal3f(-1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, -0.5 );  //C
    glNormal3f(-1,0,1); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, -0.5 ); //A
    glNormal3f(-1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, 0.5 );  //B

    glNormal3f(-1,0,1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, -0.5 ); //C
    glNormal3f(-1,0,1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, 0.5 ); //B
    glNormal3f(-1,0,1); glTexCoord2f(1, 1); glVertex3f( 0.5, 2.5, 0.5 ); //D

    // SIDE 2 BACK
    glColor4ub(255, 255, 255, 255);
    glNormal3f(1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, -0.5 );  //C
    glNormal3f(1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, 0.5 );  //B
    glNormal3f(1,0,-1); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, -0.5 ); //A

    glNormal3f(1,0,-1); glTexCoord2f(0, 1); glVertex3f( -0.5, 2.5, -0.5 ); //C
    glNormal3f(1,0,-1); glTexCoord2f(1, 1); glVertex3f( 0.5, 2.5, 0.5 ); //D
    glNormal3f(1,0,-1); glTexCoord2f(1, 0); glVertex3f( 0.5, -0.5, 0.5 ); //B
  glEnd();
}

// Pyramid
void quick_primatives::pyramid( float primative_size){
  glBegin(GL_TRIANGLES);
    // BOTTOM
    glColor4ub(255, 255, 255, 255);
    glNormal3f(0,-1,0); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, 0.5 ); //A
    glNormal3f(0,-1,0); glTexCoord2f(1, 0); glVertex3f(  -0.5, -0.5, -0.5 ); //E
    glNormal3f(0,-1,0); glTexCoord2f(1, 1); glVertex3f( 0.5, -0.5, -0.5 ); //F

    glNormal3f(0,-1,0); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, 0.5 ); //A
    glNormal3f(0,-1,0); glTexCoord2f(1, 1); glVertex3f( 0.5, -0.5, -0.5 ); //F
    glNormal3f(0,-1,0); glTexCoord2f(0, 1); glVertex3f( 0.5, -0.5, 0.5 ); //B

    // FRONT
    glNormal3f(0,0.2,-1); glTexCoord2f(1, 0); glVertex3f(  -0.5, -0.5, -0.5 ); //E
    glNormal3f(0,0.8,-1); glTexCoord2f(0, 0); glVertex3f( 0, 0.5, 0 ); //C
    glNormal3f(0,0.2,-1); glTexCoord2f(1, 1); glVertex3f( 0.5, -0.5, -0.5 ); //F

    // BACK
    glNormal3f(0,0.2,1); glTexCoord2f(0, 1); glVertex3f( 0.5, -0.5, 0.5 ); //B
    glNormal3f(0,0.8,1); glTexCoord2f(0, 0); glVertex3f( 0, 0.5, 0 ); //C
    glNormal3f(0,0.2,1); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, 0.5 ); //A

    // RIGHT
    glNormal3f(1,0.2,0); glTexCoord2f(0, 0); glVertex3f( -0.5, -0.5, 0.5 ); //A
    glNormal3f(0,0.8,-1); glTexCoord2f(0, 0); glVertex3f( 0, 0.5, 0 ); //C
    glNormal3f(1,0.2,0); glTexCoord2f(1, 0); glVertex3f(  -0.5, -0.5, -0.5 ); //E

    // LEFT
    glNormal3f(-1,0.2,0); glTexCoord2f(1, 1); glVertex3f( 0.5, -0.5, -0.5 ); //F
    glNormal3f(0,0.8,-1); glTexCoord2f(0, 0); glVertex3f( 0, 0.5, 0 ); //C
    glNormal3f(-1,0.2,0); glTexCoord2f(0, 1); glVertex3f( 0.5, -0.5, 0.5 ); //B
  glEnd();
}

// Horizontal plane
void quick_primatives::h_plane( float width, float length){
  // Plane
  glBegin(GL_TRIANGLES);
    // BOTTOM
    glColor4ub( 255, 255, 255, 255);
    glNormal3f( 0, -1, 0);
    glTexCoord2f( 0    , 0     ); glVertex3f( -width/2, 0, -length/2 ); //E
    glTexCoord2f( width, 0     ); glVertex3f(  width/2, 0, -length/2 ); //F
    glTexCoord2f( 0    , length); glVertex3f( -width/2, 0,  length/2 ); //A

    glTexCoord2f( 0    , length); glVertex3f( -width/2, 0,  length/2 ); //A
    glTexCoord2f( width, 0     ); glVertex3f(  width/2, 0, -length/2 ); //F
    glTexCoord2f( width, length); glVertex3f(  width/2, 0,  length/2 ); //B

    // TOP
    glColor4ub( 255, 255, 255, 255);
    glNormal3f( 0, 1, 0);
    glTexCoord2f( 0    , 0     ); glVertex3f( -width/2, 0, -length/2 ); //E
    glTexCoord2f( 0    , length); glVertex3f( -width/2, 0,  length/2 ); //A
    glTexCoord2f( width, 0     ); glVertex3f(  width/2, 0, -length/2 ); //F

    glTexCoord2f( width, 0     ); glVertex3f(  width/2, 0, -length/2 ); //F
    glTexCoord2f( 0    , length); glVertex3f( -width/2, 0,  length/2 ); //A
    glTexCoord2f( width, length); glVertex3f(  width/2, 0,  length/2 ); //B
  glEnd();
}

// Vertical plane
void quick_primatives::v_plane( float width, float height, float rotation){
  // Rotations
  glRotatef( rotation, 0.0f, 1.0f, 0.0f);

  // Plane
  glBegin(GL_TRIANGLES);
    // Front
    glColor4ub( 255, 255, 255, 255);
    glNormal3f( 0, 0, 1);
    glTexCoord2f( 0    , 0     ); glVertex3f( -width/2, -height/2, 0 ); //E
    glTexCoord2f( width, 0     ); glVertex3f(  width/2, -height/2, 0 ); //F
    glTexCoord2f( 0    , height); glVertex3f( -width/2,  height/2, 0 ); //A

    glTexCoord2f( 0    , height); glVertex3f( -width/2,  height/2, 0 ); //A
    glTexCoord2f( width, 0     ); glVertex3f(  width/2, -height/2, 0 ); //F
    glTexCoord2f( width, height); glVertex3f(  width/2,  height/2, 0 ); //B

    // Back
    glColor4ub( 255, 255, 255, 255);
    glNormal3f( 0, 0, -1);
    glTexCoord2f( 0    , 0     ); glVertex3f( -width/2, -height/2, 0 ); //E
    glTexCoord2f( 0    , height); glVertex3f( -width/2,  height/2, 0 ); //A
    glTexCoord2f( width, 0     ); glVertex3f(  width/2, -height/2, 0 ); //F

    glTexCoord2f( width, 0     ); glVertex3f(  width/2, -height/2, 0 ); //F
    glTexCoord2f( 0    , height); glVertex3f( -width/2,  height/2, 0 ); //A
    glTexCoord2f( width, height); glVertex3f(  width/2,  height/2, 0 ); //B
  glEnd();
}
