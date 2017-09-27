/*
  Room
  Allan Legemaate
  26/09/2017
  Consists of walls other collidables
*/

#ifndef ROOM_H
#define ROOM_H

#include <allegro.h>
#include <string>
#include <math.h>
#include "tile.h"
#include "ids.h"
#include "tools.h"
#include "tile_type_manager.h"
#include "quick_primatives.h"
#include "globals.h"
#include <glm/glm.hpp>
#include "glm/gtx/string_cast.hpp"

typedef glm::tvec3<GLbyte> byte3;

class room{
  public:
    room( BITMAP *tempBuffer);
    virtual ~room();

    bool onScreen( int tile_x, int tile_y, int tile_z);

    void load_images();
    void update();
    void generateRoom();
    void draw( int newAnimationFrame);

    tile *map_tiles[DEFAULT_MAP_WIDTH][DEFAULT_MAP_LENGTH][DEFAULT_MAP_HEIGHT];

    tile_type_manager *getManager(){ return &all_tile_defs; }
  protected:

  private:
    void quickPeek( std::string currentPhase);

    BITMAP *overlay_images[20];
    BITMAP *buffPoint;

    char width;
    char length;
    char height;

    tile_type_manager all_tile_defs;
};

#endif // ROOM_H
