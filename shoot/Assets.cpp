#include "Assets.h"

GLFWTexture   *Assets::textureAtlas = NULL;
TextureRegion *Assets::virus = NULL;
TextureRegion *Assets::start = NULL;
TextureRegion *Assets::title = NULL;
TextureRegion *Assets::player = NULL;
TextureRegion *Assets::bullet = NULL;

XfileModel    *Assets::simpleModel = NULL;
string Assets::resourcePath = "../resource/";
void Assets::load()
{
  textureAtlas = new GLFWTexture((resourcePath+"textureAtlas.png").c_str());  
  int size = 64;  
  virus  = new TextureRegion(textureAtlas , 7*size, 10*size, 2*size, 2*size);
  start  = new TextureRegion(textureAtlas , 7*size,  1*size, 4*size, 1*size);
  title  = new TextureRegion(textureAtlas , 7*size,  1*size, 4*size, 7*size);
  player = new TextureRegion(textureAtlas, 10*size,10*size, 2*size, 2*size);
  bullet = new TextureRegion(textureAtlas, 11*size, 1*size, 1*size, 1*size);
//  simpleModel = new XfileModel("sampleModel.x", 1);
}

void Assets::dispose()
{
  delete textureAtlas;
  delete virus;
  delete simpleModel;
  delete bullet;  
}

