#ifndef CAMERA_H
#define CAMERA_H
#include <SDL.h>
#include "../Map/MapParser.h"
class Camera
{
public:
	static Camera* GetInstance() {
		if (s_Instance == nullptr)
			s_Instance = new Camera();
		return s_Instance;
	}

	inline SDL_Rect GetCameraRect() { return cameraRect; }
	void Set(); // set width and height of camera
	void Update(int x, int y);
private:
	Camera();
	static Camera* s_Instance;
	SDL_Rect cameraRect;
	int screenHeight, screenWidth;
	MapDetails mapDetails;
};
#endif

