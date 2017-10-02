/*
  Quick Primatives
  Allan Legemaate
  02/07/16
  An easy to drop in class that can draw primatives or models
*/

#ifndef QUICK_PRIMATIVES_H
#define QUICK_PRIMATIVES_H

#include <alleggl.h>
#include <GLM/GLM.hpp>
#include <GL/glu.h>

class quick_primatives
{
  public:
    quick_primatives();
    virtual ~quick_primatives();

    static void cube( float primative_size, float roundness);
    static void cube_flat( float primative_size);
    static void double_plane( float primative_size);
    static void double_plane_tall( float primative_size);
    static void pyramid( float primative_size);
    static void h_plane( float width, float length);
    static void v_plane( float width, float height, float rotation);
  protected:
  private:
};

#endif // QUICK_PRIMATIVES_H
