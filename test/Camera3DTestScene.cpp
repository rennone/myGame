#include "Camera3DTestScene.h"
#include "TestListsScene.h"
#include <glfw/GL/freeglut.h>
#include <string>
using namespace std;

Camera3DTestScene::Camera3DTestScene(GLFWGame* glfwGame)
  :GLFWScene(glfwGame)
  ,cellSize(10)
  ,cellNum(10)
{
  //3Dカメラ設定
  //引数:
  //glfwのウィンドウ,  近平面, 遠平面, 視野角
  camera = new Camera3D(glfwGame->getWindow(), 1, 1000, 45);  
  camera->setPosition( Vector3(100, 0, 0) );  //カメラの位置
  camera->setLook(Vector3(0,0,0));  //カメラの見ている位置

  //2Dカメラの位置
  //引数
  //glfwのウィンドウ, プログラム上での画面の横幅, 縦幅 (真ん中に描画したければ, (WIDTH/2, HEIGHT/2)に描画する
  camera2 = new Camera2D(glfwGame->getWindow(), Camera3DTestScene::WIDTH, Camera3DTestScene::HEIGHT);

  int width, height;
  glfwGetFramebufferSize(glfwGame->getWindow(), &width, &height);  //画面の横幅と縦幅(ピクセル)を取得
  
  camera2->setViewportWidth(width/4);       //このカメラサイズを変更
  camera2->setViewportHeight(height/4);
  camera2->setViewportPosition(width/8, height/8*7); //位置を変更(左上にする)
  
  theta = phi = 0;  //Θ, φ
  pos.set(0,0,0);   //描画する立方体の位置
}

void Camera3DTestScene::update(float deltaTime)
{
  //キーボードでカメラを操作
  //このフレームに置けるキーイベントを取得, ループで一回だけ呼び出す (KeyEvent型)
  auto keyEvents = glfwGame->getInput()->getKeyEvents();
  for (auto event : keyEvents)
  { 
    switch(event->keyCode)
    {
    case GLFW_KEY_ENTER:
      if(event->action != GLFW_PRESS)
        continue;
      glfwGame->setScene(new TestListsScene(glfwGame));      //setScene->シーンの切り替え, タイトルに戻る
      return;      
    case GLFW_KEY_LEFT:
      theta -= 100*deltaTime;
      if(theta<0) theta+=2*M_PI;
      break;
    case GLFW_KEY_RIGHT:
      theta += 100*deltaTime;
      if(theta>2*M_PI) theta-=2*M_PI;
      break;
    case GLFW_KEY_UP:
      phi = min(phi+100*deltaTime, (float)M_PI/3.8f);
      break;
    case GLFW_KEY_DOWN:
      phi = min(phi-100*deltaTime, 0.0f);
      break;
    case GLFW_KEY_T:
      theta = 0;
      break;
    case GLFW_KEY_P:
      phi = 0;
      break;
    }
  }
  
  //カメラの位置を更新
  float R = 100;
  camera->setPosition(Vector3(R*cos(phi)*cos(theta), R*sin(phi), R*cos(phi)*sin(theta)));

  //マウスイベントの取得
  auto mouse = glfwGame->getInput()->getMouseEvent();
  
  auto touch = Vector2(mouse->x, mouse->y);  //Vector2型に変換
  Vector3 direction = camera->screenToWorld(touch);  //タッチ位置をワールドベクトルに変換
  pos = camera->getPosition() + 100*direction;  //カメラから, タッチした位置にモデルを置く
}

void Camera3DTestScene::render(float deltaTime)
{
  //このカメラの設定(これは3Dカメラ) レンダーする前に呼び出す
  camera->setViewportAndMatrices(); 
  
  glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT);
  glEnable(GL_LIGHTING);    
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_DEPTH_TEST);
    
  GLfloat color[]     = {    1.0,    1.0,    1.0, 1.0 };
  GLfloat lightpos1[] = {  200.0, -200.0, -200.0, 1.0 };
  GLfloat lightpos2[] = { -200.0,  200.0,  200.0, 1.0 };
  GLfloat lightpos3[] = { -200.0, -200.0, -200.0, 1.0 };
  GLfloat lightpos4[] = {  200.0,  200.0,  200.0, 1.0 };
    
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos1);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
  glLightfv(GL_LIGHT1, GL_POSITION, lightpos2);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
    
  glLightfv(GL_LIGHT2, GL_POSITION, lightpos3);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, color);
  glLightfv(GL_LIGHT3, GL_POSITION, lightpos4);
  glLightfv(GL_LIGHT3, GL_DIFFUSE, color);

  glColor3f(1,1,1);
  drawAxis(); //軸を表示(自作)
    
  glPushMatrix();
  glTranslatef(pos.x, pos.y, pos.z);
  glRotatef((float) glfwGetTime() * 50.f, glfwGetTime(), glfwGetTime()*2, glfwGetTime()*3);
  glutSolidCube(5); 
  glPopMatrix();

  glPopAttrib();

  //2Dビューに描画
  camera2->setViewportAndMatrices();
  glRasterPos2f(-Camera3DTestScene::WIDTH/2,Camera3DTestScene::HEIGHT/3);
  string str = "push Enter to back Title";
  for(int i=0; i<str.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);  
}

