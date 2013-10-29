/*
 * SceneCredits.h
 *
 *  Created on: Oct 28, 2013
 *      Author: al
 */

#ifndef SCENECREDITS_H_
#define SCENECREDITS_H_
#include "Scene.h"
#include "Sprite.h"
#include "SplashScreen.h"
#include "TextObject.h"
#include <string>


class SceneCredits : public Scene {
public:
	SceneCredits(string sceneName);
	virtual ~SceneCredits();
	void Enter();
	void Exit();

private:
	Sprite * splashSprite, *textSprite;
	TextObject * text;
};

#endif /* SCENECREDITS_H_ */
