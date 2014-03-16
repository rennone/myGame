#include "Player.h"
#include "Field.h"
#include "Assets.h"
#include <iostream>
using namespace std;

Player::Player(string name, GLFWGame *game, SpriteBatcher *_batcher)
  :Actor(name, game)
  ,batcher(_batcher)
{
  position.set(0,0);
  bulletMgr = new BulletManager("bulletManager", glfwGame, batcher);
  addChild(bulletMgr);  
}

void Player::update(float deltaTime)
{
  auto input = glfwGame->getInput();
  
  const float speed = 6.0f;
 
  if(input->isKeyPressed(GLFW_KEY_LEFT))      
    position.x -= speed*deltaTime;     
  
  if(input->isKeyPressed(GLFW_KEY_RIGHT))
    position.x += speed*deltaTime;
  
  if(input->isKeyPressed(GLFW_KEY_UP))
    position.y += speed*deltaTime;
  
  if(input->isKeyPressed(GLFW_KEY_DOWN))
    position.y -= speed*deltaTime;

  if(input->isKeyPressed(GLFW_KEY_P) == GLFW_PRESS)
    bulletMgr->createBullet(position);

  Actor::update(deltaTime);  
}

void Player::render(float deltaTime)
{
  const float size = Field::FIELD_WIDTH/10;
  
  batcher->drawSprite(position.x, position.y, size, size, Assets::player );
  Actor::render(deltaTime);
}

