
#include "HowToPlayScene.h"
#include "TitleScene.h"
#include "Globals.h"
#include "Enums.h"
#include "Spawner.h"
#include <memory>

USING_NS_CC;


Scene* HowToPlayScene::createScene()
{
  auto scene = Scene::create();
  auto layer = HowToPlayScene::create();


  scene->addChild(layer);
  return scene;
}

bool HowToPlayScene::init()
{
  if (!Layer::init()) {
    return false;
 }

  auto size = Director::getInstance()->getWinSize();


  //Spawn Background
  title_ = std::unique_ptr<GameObject>(Globals::spawner.spawn(Globals::screenHowToPlay));
  title_->getGraphic()->setParentNode(this, BACKGROUND);

  //Add mouse event listener
  auto touchListener = EventListenerTouchOneByOne::create();
  touchListener->onTouchBegan = [](Touch* touch, Event* event)->bool {
    auto scene = TitleScene::createScene();
    auto transition = TransitionFade::create(0.5f, scene);
    Director::getInstance()->replaceScene(transition);
    return true;
  };
  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);



  return true;
}



