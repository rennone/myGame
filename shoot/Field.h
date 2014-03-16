#ifndef FIELD_H_2013_12_23
#define FIELD_H_2013_12_23
#include "Actor.h"

class Field:public Actor
{  
public:
  static constexpr float FIELD_WIDTH  = 4.8;
  static constexpr float FIELD_HEIGHT = 3.2;
  Field(string name, GLFWGame *game)
    :Actor(name, game)
  {
  }  
};


#endif
