#include "Assets.h"

GLFWTexture   *Assets::textureAtlas = NULL;
TextureRegion *Assets::virus = NULL;
XfileModel    *Assets::simpleModel = NULL;
string Assets::resourcePath = "../resource/";
void Assets::load()
{
  textureAtlas = new GLFWTexture((resourcePath+"textureAtlas.png").c_str());  
  int size = 64;  
  virus = new TextureRegion(textureAtlas, 7*size, 10*size, 2*size, 2*size);

  simpleModel = new XfileModel("sampleModel.x", 1);
}

void Assets::dispose()
{
  delete textureAtlas;
  delete virus;
  delete simpleModel;  
}

