#ifndef CURSOR_H
#define CURSOR_H
#include <SDL.h>
class Cursor
{
public:
	Cursor(int x, int y);
	void Update();
	void Render();
private:
	SDL_Rect cursorRect;
	int pixelSize;
	bool keyPressed; //
	unsigned int keyPressTimer; //timer before program reads hold button key
};

#endif