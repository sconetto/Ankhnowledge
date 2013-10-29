#ifndef TEXTOBJECT_H_
#define TEXTOBJECT_H_

#include "Sprite.h"
#include "InputManager.h"
#include <vector>
#include "GameObject.h"
#include "Animation.h"

using namespace std;

class TextObject : public GameObject {
	public:
		TextObject(Sprite * sprite, float x, float y);
		void render(float cameraX, float cameraY);
		int update(int dt);
		virtual ~TextObject();

	private:
		Sprite * sprite;
};

#endif 
