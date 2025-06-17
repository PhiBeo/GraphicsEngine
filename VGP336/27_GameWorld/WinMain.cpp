#include <SumEngine/Inc/SumEngine.h>
#include "GameState.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	SumEngine::App& mainApp = SumEngine::MainApp();
	mainApp.AddState<GameState>("GameState");

	SumEngine::AppConfig config;
	config.appName = L"GameWorld";
	config.winWidth = 1280;
	config.winHeight = 780;
	mainApp.Run(config);
	return(0);
}