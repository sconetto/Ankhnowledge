#include "TextObject.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

TextObject::TextObject(Sprite * sprite, float x, float y):GameObject(x,y)
{
	this->sprite = sprite;
}

TextObject::~TextObject() {}

void TextObject::render(float cameraX, float cameraY)
{
	
}

int TextObject::update(int dt)
{	
	
}

