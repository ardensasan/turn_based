#include "src/Core/Engine.h"
#include "src/Core/Timer.h"
int main(int argc, char* argv[]) {
	Engine::GetInstance()->Init();
	while (Engine::GetInstance()->IsRunning()) {
		Engine::GetInstance()->HandleEvents();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
		Timer::GetInstance()->Delay();
	}
	Engine::GetInstance()->Clean();
	return 0;
}