#ifndef ASSETS_H_2013_12_22
#define ASSETS_H_2013_12_22

#include <glfw/GLFWTexture.h>
#include <glfw/XfileModel.h>
#include <string>
using namespace std;

class Assets
{
public:
  static string resourcePath;
  static GLFWTexture   *textureAtlas;
  static TextureRegion *virus;
  static TextureRegion *player;
  static TextureRegion *start;
  static TextureRegion *title;
  static TextureRegion *bullet;
  static XfileModel    *simpleModel;
  static void load();
  static void dispose();
private:
  Assets();
  Assets& operator=(const Assets& obj);
};

#endif
