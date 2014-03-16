#ifndef BULLET_MANAGER_H_2013_12_23
#define BULLET_MANAGER_H_2013_12_23

#include "Actor.h"
#include "Bullet.h"
#include <glfw/SpriteBatcher.h>
#include <Pool.h>
class BulletManager: public Actor
{
static constexpr int bulletNum = 50;
SpriteBatcher *batcher;
Bullet *bullets[bulletNum];
public:
BulletManager(string name, GLFWGame *game, SpriteBatcher *_batcher)
:Actor(name, game)
,batcher(_batcher)
{
for(int i=0; i<bulletNum; i++)
{
bullets[i] = new Bullet("bullet", glfwGame, batcher);
bullets[i]->setStatus(Actor::NoUse);
addChild(bullets[i]);
}
}

void createBullet(const Vector2 &pos)
{
for(auto bullet : bullets)
{
if(bullet->getStatus() == Actor::NoUse)
{
  bullet->setPosition(pos);
bullet->setStatus(Actor::Action);
return;

}
}

}
};



#endif
