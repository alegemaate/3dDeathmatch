#include "material_manager.h"

std::string currentMaterial = "";
std::vector<material> materials;

// Colours and properties of materials
void changeMaterial( std::string materialName){
  // Find in all materials
  for( unsigned int i = 0; i < materials.size(); i++){
    if( materialName == materials.at(i).getName()){
      materials.at(i).changeTo();
      currentMaterial = materialName;
    }
  }
}

// Get material id
GLuint getMaterial( std::string materialName){
  // Find in all materials
  for( unsigned int i = 0; i < materials.size(); i++){
    if( materialName == materials.at(i).getName()){
      return i;
    }
  }
  return 0;
}

// Load materials from xml
bool loadMaterials( std::string fileName){
  // Load biomes from file
  rapidxml::xml_document<> doc;
  std::ifstream file;

  // Check exist
  if( fexists(fileName.c_str()))
    file.open(fileName.c_str());
  else
    return 0;

  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string content(buffer.str());
  doc.parse<0>(&content[0]);

  rapidxml::xml_node<> *allMats = doc.first_node();

  // Loading
  std::cout << "   MATERIALS\n----------------\n";

  // Load tiles
  for(rapidxml::xml_node<> *cMat=allMats-> first_node("material"); cMat; cMat=cMat->next_sibling()){
    // Create material
    material newMat;

    // ID
    int id = atoi(cMat-> first_attribute("id") -> value());

    // Name
    std::string name = cMat-> first_node("name") -> value();
    newMat.setName( name);

    // Load material data
    for( int i = 0; i < 3; i++){
      const char *node_on;

      if( i == 0)
        node_on = "ambient";
      else if( i == 1)
        node_on = "diffuse";
      else
        node_on = "specular";

      float type_r = atof( cMat-> first_node(node_on) -> first_node("r") -> value());
      float type_g = atof( cMat-> first_node(node_on) -> first_node("g") -> value());
      float type_b = atof( cMat-> first_node(node_on) -> first_node("b") -> value());
      float type_a = atof( cMat-> first_node(node_on) -> first_node("a") -> value());

      if( i == 0)
        newMat.setAmbient ( type_r, type_g, type_b, type_a);
      else if( i == 1)
        newMat.setDiffuse ( type_r, type_g, type_b, type_a);
      else
        newMat.setSpecular( type_r, type_g, type_b, type_a);
    }

    // Shininess
    float shininess = atof( cMat-> first_node("shininess") -> value());
    newMat.setShininess( shininess);

    // Draw to screen (debug)
    std::cout << "-> Loaded Material:" << name << "  ID:" <<  id << "  SHININESS:" << shininess << "\n";

    // Add the tile
    materials.push_back( newMat);
  }

  std::cout << "\n\n";

  return 1;
}
