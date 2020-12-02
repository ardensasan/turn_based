#include "Settings.h"
#include "../../Input/InputListener.h"
Settings* Settings::s_Instance = nullptr;
Settings* Settings::GetInstance() {
	if (s_Instance == nullptr)
		s_Instance = new Settings();
	return s_Instance;
}

Settings::Settings() {
	screenHeight = screenWidth = 0;
	resolutionChoice = 0;
	colorList = { {255, 255, 255} , {255, 0, 0} };
	settingStrings = { "Resolution", "Volume", "Settings", "Back" };
	resolutionStrings = { "< 1024 x 576 >" ,"< 1152 x 648 >" , "< 1280 x 720 >" , "< 1366 x 768 >", "< 1600 x 900 >", "< 1920 x 1080 >"};
	resolutions = { { 1024, 576 }, { 1152, 648 }, { 1280, 720 }, { 1366, 768 },  { 1600, 900 }, { 1920, 1080 } };
	for (unsigned int i = 0;i < resolutions.size(); i++) {
		if (resolutions[i][0] == Engine::GetInstance()->GetScreenWidth() && resolutions[i][1] == Engine::GetInstance()->GetScreenHeight()) {
			screenWidth = resolutions[i][0];
			screenHeight = resolutions[i][1];
			resolutionChoice = i;
		}
	}
	if (screenHeight == 0 && screenWidth == 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"Resolution Error",
			"Invalid Resolution. Please reinstall the program.",
			NULL);
		Engine::GetInstance()->Quit();
	}
	fontFile = "Assets/Fonts/Ancient Modern Tales.otf";
	fontSize = 100;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	currentChoice = 0;
	keyPressed = false;
	return;
}

void Settings::Update() {
	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) &&
		!keyPressed) {
		currentChoice = currentChoice > 2 ? 0 : currentChoice + 1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_S) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_DOWN))
		&& keyPressed) {
		keyPressed = false;
	}

	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) &&
		!keyPressed) {
		currentChoice = currentChoice < 1 ? 3 : currentChoice - 1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_W) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_UP)) &&
		keyPressed) {
		keyPressed = false;
	}

	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_A) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT)) &&
		!keyPressed) {
		if (currentChoice == 0)
			resolutionChoice = resolutionChoice < 1 ? resolutionStrings.size()-1 : resolutionChoice - 1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_A) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_LEFT)) &&
		keyPressed) {
		keyPressed = false;
	}


	if ((InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_D) ||
		InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT)) &&
		!keyPressed) {
		if (currentChoice == 0)
			resolutionChoice = resolutionChoice > int(resolutionStrings.size()) - 2 ?  0 : resolutionChoice + 1;
		keyPressed = true;
	}
	if ((InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_D) ||
		InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RIGHT)) &&
		keyPressed) {
		keyPressed = false;
	}

	if (InputListener::GetInstance()->GetKeyDown(SDL_SCANCODE_RETURN) && !keyPressed) {
		if (currentChoice == 3) { //back
			Engine::GetInstance()->SetMenuState(4); //change resolution
			Engine::GetInstance()->SetScreenWidth(resolutions[resolutionChoice][0]);
			Engine::GetInstance()->SetScreenHeight(resolutions[resolutionChoice][1]);
			currentChoice = 0;
		}
		keyPressed = true;
	}

	if (InputListener::GetInstance()->GetKeyUp(SDL_SCANCODE_RETURN) && keyPressed) {
		keyPressed = false;
	}
	return;
}

void Settings::Render() {
	SDL_Surface* textSurface;
	SDL_Texture* texture;
	int textWidth = 200;
	int textHeight = 50;
	int screenWidth = Engine::GetInstance()->GetScreenWidth();
	int screenHeight = Engine::GetInstance()->GetScreenHeight();
	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
	SDL_Rect rect = { int((screenWidth - textWidth) / 2),int((screenHeight - textHeight) / 2),textWidth,textHeight };
	std::vector<std::string>::iterator it;
	int counter = 0;
	for (it = settingStrings.begin();it != settingStrings.end();++it) {
		if (it == settingStrings.end() - 1) {
			textWidth /= 2;
			rect.x = int((screenWidth - textWidth) / 2);
			rect.w = textWidth;
		}
		SDL_Color color = (counter == currentChoice) ? colorList[1] : colorList[0]; // set red color for current choice or white color
		std::string res = "Resolution";
		if (res.compare(it->c_str()) == 0) {
			SDL_Rect rect1 = { int((screenWidth - textWidth) / 2) + 200,int((screenHeight - textHeight) / 2),textWidth,textHeight };
			textSurface = TTF_RenderText_Solid(font, resolutionStrings[resolutionChoice].c_str(), color);
			texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			SDL_RenderCopy(renderer, texture, NULL, &rect1);
		}
		textSurface = TTF_RenderText_Solid(font, it->c_str(), color);
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		rect.y += rect.h + 4;
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(textSurface);
		counter++;
	}
	return;
}

void Settings::Clean() {
	TTF_CloseFont(font);
	font = nullptr;
	return;
}