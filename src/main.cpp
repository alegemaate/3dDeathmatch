/*
  Forager!
  Allan Legemaate
  04/11/2015
  Foraging Game!
*/

//Includes
#define GLEW_STATIC


#include <allegro.h>
#include <alpng.h>
#include <alleggl.h>

#include <string>
#include <time.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iostream>
#include <stdio.h>


#include "ids.h"
#include "tile.h"
#include "room.h"
#include "tools.h"
#include "player.h"
#include "audio_3d.h"
#include "globals.h"
#include "material_manager.h"

//Create variables
int gameScreen = INGAME;
int animationFrame;
bool closeGame;
bool showFPS;

//Create fonts
FONT *f1, *f2, *f3, *f4, *f5;
FONT *ARIAL_BLACK;

//Create images
BITMAP *buffer;
BITMAP *cursor;

// Sounds
audio_3d *dinner;

//FPS System
int fps;
int frames_done;
int old_time;

// An array to store the number of frames we did during the last 10 tenths of a second
int frames_array[10];
int frame_index = 0;

volatile int ticks = 0;
void ticker(){
    ticks++;
}
END_OF_FUNCTION(ticker)

volatile int game_time = 0;
void game_time_ticker(){
    game_time++;
}
END_OF_FUNCTION(game_time_ticker)

const int updates_per_second = 60;

//Animations
void animationTicker(){
  if(animationFrame == 0){
    animationFrame = 1;
  }
  else if(animationFrame == 1){
    animationFrame = 0;
  }
}
END_OF_FUNCTION(animationTicker)

room* gameRoom;
player* jimmy;

/******************
 * KILLMESHADERS! *
 ******************/
unsigned long getFileLength( std::ifstream &file){
    if(!file.good()) return 0;

    unsigned long pos=file.tellg();
    file.seekg(0,std::ios::end);
    unsigned long len = file.tellg();
    file.seekg(std::ios::beg);
    return len;
}

int loadshader(char *filename, GLchar **ShaderSource, GLint *len){
  std::ifstream file;
  file.open(filename, std::ios::in); // opens as ASCII!

  if(!fexists(filename))
    return -1;

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

int unloadshader(GLubyte** ShaderSource){
   if (*ShaderSource != 0)
     delete[] *ShaderSource;
   *ShaderSource = 0;
}

void setupShader( std::string shaderFile, GLuint newShader){
  // Load them!
  GLchar *shaderSource;
  GLint shaderFileLength;

  // Convert from string to char*
  char * charShaderFile = const_cast<char*> ( shaderFile.c_str() );

  if(loadshader(charShaderFile, &shaderSource, &shaderFileLength) != 0)
    abort_on_error((shaderFile + " NOT found!").c_str());
  else
    std::cout << shaderFile << " found\n";

  glShaderSource(newShader, 1, const_cast<const GLcharARB**>(&shaderSource), &shaderFileLength);

  // Compile them
  glCompileShaderARB(newShader);

  // Check success
  GLint compiled;
  glGetShaderiv(newShader, GL_COMPILE_STATUS, &compiled);
  if (!compiled)
     abort_on_error( ("Dude, " + shaderFile + " didnt compile...").c_str());
  else
    std::cout << shaderFile << " shader compiled!\n";
}

// Setup program
void setupProgram( GLuint newProgram){
  glLinkProgram(newProgram);

  GLint linked;
  glGetProgramiv(newProgram, GL_LINK_STATUS, &linked);

  if (!linked)
    abort_on_error( ("Program " + convertIntToString(newProgram) + "didnt link...").c_str());
  else
    std::cout << "Program " << newProgram << " linked!\n\n";
}

/*********************
 * ENDKILLMESHADERS! *
 *********************/


//Load all ingame content
void setup(bool first){
  showFPS = true;

  if(first){
    /****************
     * SOME ALLEGRO *
     ****************/
    allegro_init();
    install_allegro_gl();
    alpng_init();
    install_keyboard();
    install_timer();
    install_mouse();
    if( install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"."))
      abort_on_error( allegro_error);

    set_color_depth( 32);
    set_window_title("Forager");

    /*******************
     * SOME ALLEGRO GL *
     *******************/
    allegro_gl_set(AGL_Z_DEPTH, 8);
    allegro_gl_set(AGL_COLOR_DEPTH, 32);
    allegro_gl_set(AGL_SUGGEST, AGL_Z_DEPTH | AGL_COLOR_DEPTH);
    allegro_gl_set(AGL_REQUIRE, AGL_DOUBLEBUFFER);

    //Set screenmode
    int monitor_width = 0;
    int monitor_height = 0;
    get_desktop_resolution( &monitor_width, &monitor_height);

    if( monitor_height < 960 || set_gfx_mode( GFX_OPENGL_WINDOWED, 1280, 960, 0, 0) !=0){
      if(set_gfx_mode( GFX_OPENGL_WINDOWED, 800, 600, 0, 0) !=0){
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        abort_on_error("Unable to go into any graphic mode\n%s\n");
      }
    }

    /****************
     * INIT OPEN GL *
     ****************/
    // Viewport
    glViewport(0, 0, SCREEN_W, SCREEN_H);

    // I am setting a state where I am editing the projection matrix.
    glMatrixMode(GL_PROJECTION);

    // Clearing the projection matrix...
    glLoadIdentity();

    // Set the perspective with the appropriate aspect ratio
    gluPerspective(60.0f,(GLfloat)SCREEN_W/(GLfloat)SCREEN_H,1.0f,1000.0f);

    // Now editing the model-view matrix.
    glMatrixMode(GL_MODELVIEW);

    // Clearing the model-view matrix.
    glLoadIdentity();

    // Depth test
    glEnable( GL_DEPTH_TEST);

    // Alpha (remove pixels less than 0.5)
    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(GL_ALPHA_TEST);
    glShadeModel (GL_SMOOTH);

    // Set default material
    changeMaterial( MATERIAL_DEFAULT);

    // Cull back faces
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // TEXTURING
    // Enable texturing and blending (all tiles use this so lets just call it once)
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);

    // Alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // LOAD SHADERS
    std::cout << "   SHADERS\n-------------\n";

    // Shaders
    // DEFAULT
    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    setupShader( "shaders/textured.vert", vertexShader);
    setupShader( "shaders/textured.frag", fragmentShader);

    // Make program
    defaultShader = glCreateProgram();

    glAttachShader(defaultShader, vertexShader);
    glAttachShader(defaultShader, fragmentShader);

    setupProgram( defaultShader);

    // Use our Shaders :D:D:D:D:D
    glUseProgram(defaultShader);

    // Enable lights
    glEnable(GL_LIGHTING); //turns the "lights" on
    glEnable(GL_LIGHT0);

    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat light_specular[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat light_position[] = { -1.5f, 0.5f, -4.0f, 0.0f };

    // Light 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // FPS STUFF
    //Creates a random number generator (based on time)
    srand (time(NULL));

    //Setup fNULLor FPS system
    LOCK_VARIABLE(ticks);
    LOCK_FUNCTION(ticker);
    install_int_ex(ticker, BPS_TO_TIMER(updates_per_second));

    LOCK_VARIABLE(game_time);
    LOCK_FUNCTION(game_time_ticker);
    install_int_ex(game_time_ticker, BPS_TO_TIMER(10));

    LOCK_VARIABLE(animationFrame);
    LOCK_FUNCTION(animationTicker);
    install_int_ex(animationTicker, SECS_TO_TIMER(1));

    fps = 0;
    frames_done = 0;
    old_time = 0;

    for(int ii = 0; ii < 10; ii++)
      frames_array[ii] = 0;

    //Creates a buffer
    buffer = create_bitmap( SCREEN_W, SCREEN_H);

    cursor = load_bitmap( "images/cursor2.png", NULL);

    // Mouse sensitivity
    set_mouse_speed( 3, 3);

    // Character
    jimmy = new player( 0, 1, 0, 45, 135);
    jimmy -> load_images();

    // Sounds
    dinner = new audio_3d( "sounds/dinner.wav", 0, 0, 0);

    //Sets Font
    f1 = load_font("fonts/arial_black.pcx", NULL, NULL);
    f2 = extract_font_range(f1, ' ', 'A'-1);
    f3 = extract_font_range(f1, 'A', 'Z');
    f4 = extract_font_range(f1, 'Z'+1, 'z');

    //Merge fonts
    ARIAL_BLACK = merge_fonts(f4, f5 = merge_fonts(f2, f3));

    //normal map
    // TRANSFORMS
    jimmy -> transformWorld();

    gameRoom = new room( buffer);
    gameRoom -> load_images();
    gameRoom -> generateRoom();

    // Load them models
    if( !quick_primatives::load_models()){
      abort_on_error( "quick_primatives couldnt load the damn model!");
    }
  }
}

//Run the game loops
void game(){
  if(gameScreen == SPLASH){

  }
  else if(gameScreen == MENU){

  }
  else if(gameScreen == LEVELSELECT){

  }
  else if(gameScreen == INGAME){
    gameRoom -> update();
    jimmy -> logic( gameRoom);

    if( key[KEY_M])
      dinner -> play3D( jimmy -> getPointX(), jimmy -> getPointY(), jimmy -> getPointZ(), 255, 127, 1000, true);
    dinner -> update();

    // Back to normal shader
    glUseProgram(defaultShader);
  }

  //Exit game
  if(key[KEY_ESC]){
    closeGame = true;
  }

  //Counter for FPS
  frames_done++;
}

//Draw images
void draw(){
  // View matrix
  glMatrixMode(GL_MODELVIEW);

  // Clear screen
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Reset transforms
  glLoadIdentity();

  /*******************
   * OPEN GL DRAWING *
   *******************/

  // Default shader
  glUseProgram(defaultShader);

  // Transform world to players view
  jimmy -> transformWorld();

  // Draw player
  //jimmy -> render();

  // Draw map
  if( !key[KEY_TILDE])
    gameRoom -> draw( 0);

  // Back to init shader
  glUseProgram(0);

  /**********************
   * ALLEGRO GL DRAWING *
   **********************/
  allegro_gl_set_allegro_mode();

  // Transparent buffer
  rectfill( buffer, 0, 0, SCREEN_W, SCREEN_H, makecol( 255, 0, 255));

  //FPS counter
  if(showFPS){
    textprintf_ex( buffer, font, 0, 0, makecol(0,0,0), makecol(255,255,255), "FPS-%i", fps);
  }

  // Hud
  jimmy -> render2D( buffer);

  // Cursor
  draw_sprite( buffer, cursor, (SCREEN_W - cursor -> w)/2, (SCREEN_H - cursor -> h)/2);

  // Debug text
  textprintf_ex( buffer, ARIAL_BLACK, 20, 20, makecol(0,0,0), makecol(255,255,255), "Camera X:%4.1f Y:%4.1f Z:%4.1f RotX:%4.1f RotY:%4.1f ", jimmy -> getX(), jimmy -> getY(), jimmy -> getZ(), jimmy -> getXRotation(), jimmy -> getYRotation());

  //Draws buffer
  draw_sprite( screen, buffer, 0, 0);

  allegro_gl_unset_allegro_mode();

  allegro_gl_flip();
}

int main( int argc, char* args[]){
  //Setup game
  setup(true);

  //Starts Game
  while(!closeGame){
    //Runs FPS system
    while(ticks == 0){
      rest(1);
    }
    while(ticks > 0){
      int old_ticks = ticks;
      // Update while in tick
      if( !key[KEY_1])
        game();
      ticks--;
      if(old_ticks <= ticks)
        break;
    }
    if(game_time >= old_time + 1){
      fps -= frames_array[frame_index];//decrement the fps by the frames done a second ago
			frames_array[frame_index] = frames_done;//store the number of frames done this 0.1 second
			fps += frames_done;//increment the fps by the newly done frames

			frame_index = (frame_index + 1) % 10;//increment the frame index and snap it to 10

			frames_done = 0;
			old_time += 1;
    }
    // Update every tick
    draw();
    frames_done++;
  }
  allegro_exit();

  return 0;
}
END_OF_MAIN();
