#ifndef PLAYER_H_2013_12_23
#define PLAYER_H_2013_12_23

#include "Actor.h"
#include "BulletManager.h"
#include <glfw/SpriteBatcher.h>
#include <math/Vector2.h>
class Player:public Actor
{
  SpriteBatcher *batcher;
  Vector2 position;
  BulletManager *bulletMgr;
  
public:
  Player(string name, GLFWGame *game, SpriteBatcher *_batcher);
  
  void update(float deltaTime);
  void render(float deltaTime);
  void reshape(int width, int height) {  }  
  void dispose() {  }  
};

#endif
