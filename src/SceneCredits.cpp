#include "SceneCredits.h"
#include "TextObject.h"

SceneCredits::SceneCredits(string sceneName) : Scene (sceneName)  {
	// TODO Auto-generated constructor stub

}

SceneCredits::~SceneCredits() {

}

void SceneCredits::Enter()
{
	this->splashSprite = new Sprite(SDLBase::imagePath + "credit_background.png");
	this->textSprite = new Sprite(SDLBase::imagePath + "credit_text.png");


	this->text = new TextObject(textSprite, 0, 135);

	string nextScene = "SceneMainMenu";

	SplashScreen * splashScreen =  new SplashScreen(splashSprite, nextScene);
	this->addGameObject(splashScreen);
	this->addGameObject(text);
	

	GameManager::fadeScreen->fadeOut(0,2);
}

void SceneCredits::Exit()
{
	this->cleanGameObjects();
}

