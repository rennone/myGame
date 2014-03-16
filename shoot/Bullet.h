#ifndef BULLET_H_2013_12_23
#define BULLET_H_2013_12_23

#include "Actor.h"
#include <glfw/SpriteBatcher.h>
#include <math/Vector2.h>

class Bullet:public Actor
{
SpriteBatcher *batcher;
Vector2 position;
public:
Bullet(string name, GLFWGame *game, SpriteBatcher *batcher);
void update(float deltaTime);
void render(float deltaTime);
void reshape(int width, int height){ }
void dispose() { }
void setPosition(const Vector2 &pos)
{
  position.set(pos.x, pos.y);
}

};


#endif
