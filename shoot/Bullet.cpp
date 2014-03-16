#include "Bullet.h"
#include "Field.h"
#include "Assets.h"
Bullet::Bullet(string name, GLFWGame *game, SpriteBatcher *_batcher)
  :Actor(name, game)
  ,batcher(_batcher)
{
  position.set(0,0);  
}

void Bullet::update(float deltaTime)
{
  const float speed = 10.0f;
  
  if( (position.y += deltaTime*speed) > Field::FIELD_HEIGHT/2)
    setStatus(Actor::NoUse);  
}

void Bullet::render(float deltaTime)
{
  const float size = Field::FIELD_WIDTH/40;  
  batcher->drawSprite(position.x-size, position.y, size, size, Assets::bullet);
  batcher->drawSprite(position.x+size, position.y, size, size, Assets::bullet);
}




