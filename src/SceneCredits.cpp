/*
 * SceneCredits.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: al
 */

#include "SceneCredits.h"
#include "TextObject.h"

SceneCredits::SceneCredits(string sceneName) : Scene (sceneName)  {
	// TODO Auto-generated constructor stub

}

SceneCredits::~SceneCredits() {
	delete this->text;
}

void SceneCredits::Enter()
{

	this->splashSprite = new Sprite(SDLBase::imagePath + "background.png");
	this->textSprite = new Sprite(SDLBase::imagePath + "credittext.png");

	this->text = new TextObject(textSprite, 200, 100);

	string nextScene = "SceneLogo";

	SplashScreen * splashScreen =  new SplashScreen(splashSprite, nextScene);
	this->addGameObject(splashScreen);
	this->addGameObject(text);

	GameManager::fadeScreen->fadeOut(0,6);
}

void SceneCredits::Exit()
{
	this->cleanGameObjects();
}

