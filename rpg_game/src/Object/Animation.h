//handles animation of objects
#ifndef ANIMATION_H
#define ANIMATION_H
#include "../Graphics/TextureManager.h"
class Animation
{
public:
	Animation(std::string textureid);
	void Update();
	void UpdateCol(int col); // set spritesheet
	void Render(int xPosition, int yPosition);
private:
	int frameRowCount; // number of row in spritesheet
	int frameColCount; // number of columns in spritesheet
	int currentFrameRow; // current row in spritesheet
	int currentFrameCol; // current col in sprtesheet
	int animationDelay; // delay before frame change
	std::string textureID;
};
#endif

