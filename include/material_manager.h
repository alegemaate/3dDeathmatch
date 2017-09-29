/*
  Material Manager
  Allan Legemaate
  05/01/16
  Just a function to quickly change materials
*/

#ifndef MATERIAL_MANAGER_H
#define MATERIAL_MANAGER_H

#include <allegro.h>
#include <alleggl.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "tools.h"
#include "material.h"

extern void changeMaterial( std::string materialName);
extern bool loadMaterials( std::string fileName);

extern std::string currentMaterial;

extern std::vector<material> materials;

#endif // MATERIAL_MANAGER_H
