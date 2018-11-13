#include "tools.h"

//Collision
bool collisionAny(int xMin1, int xMax1, int xMin2, int xMax2, int yMin1, int yMax1, int yMin2, int yMax2){
  if (xMin1 < xMax2 && yMin1 < yMax2 && xMin2 < xMax1 && yMin2 < yMax1){
    return true;
  }
  return false;
}
bool collisionOverlap(double x1, double width1, double x2, double width2){
  if(x1 - width1 < x2 + width2 && x1 - width1 > x2 - width2){
    return true;
  }
  return false;
}
bool collisionOverlap2(double x1, double width, double x2){
  if(x1 + width > x2 && x1 < x2){
    return true;
  }
  return false;
}

// 3D collision
bool collision3d(double x1, double width1, double x2, double width2, double y1, double height1, double y2, double height2, double z1, double depth1, double z2, double depth2){
  //check the X axis
  if(abs(x1 - x2) < width1 + width2){
    //check the Y axis
    if(abs(y1 - y2) < height1 + height2){
        //check the Z axis
        if(abs(z1 - z2) < depth1 + depth2){
           return true;
        }
    }
  }
  return false;
}

//Checks if file exists
bool fexists(const char *filename){
  std::ifstream ifile(filename);
  return !ifile.fail();
}

//Random number generator. Use int random(lowest,highest);
int random(int newLowest, int newHighest){
  if( newHighest < newLowest)
    return -1;

  int lowest = newLowest, highest = newHighest;
  int range = (highest - lowest) + 1;
  int randomNumber = lowest+int(range*rand()/(RAND_MAX + 1.0));
  return randomNumber;
}

//Convert int to string
std::string convertIntToString(int number){
  std::stringstream ss;
  ss << number;
  return ss.str();
}

//Convert double to string
std::string convertDoubleToString(double number){
  std::stringstream ss;
  ss << number;
  return ss.str();
}

//Convert bool to string
std::string convertBoolToString(bool boolean){
  std::stringstream ss;
  ss << boolean;
  return ss.str();
}

// Slope of line
double findSlope( int y_1, int y_2, int x_1, int x_2){
  if( (x_2 - x_1) == 0)
    return 0;
  return (y_2 - y_1)/(x_2 - x_1);
}

// Objects are close
bool closeTo( double val1, double val2, double maxDifference){
  if( abs(val1 - val2) > maxDifference)
    return false;
  return true;
}

// Returns distance 1D
int distanceTo1D( int x1, int x2){
  return abs(x1 - x2);
}

// Returns distance 2D
int distanceTo2D(int x1, int y1, int x2, int y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

// Returns distance 3D
int distanceTo3D(int x1, int y1, int z1, int x2, int y2, int z2){
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
}

// Divide catch 0
int divideCatchZero( int number1, int number2){
  if( number2 != 0)
    return number1/number2;
  return 0;
}

/*
 *  ERROR REPORTING
 */
void abort_on_error(const char *message){
  if( screen != NULL){
    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0);
  }
  allegro_message( "%s.\n %s\n", message, allegro_error);
  exit(-1);
}

// Get file length
unsigned long getFileLength( std::ifstream &file){
  if( !file.good())
    return 0;

  unsigned long pos = file.tellg();
  file.seekg( 0, std::ios::end);
  unsigned long len = file.tellg();
  file.seekg( std::ios::beg);
  return len;
}

