#include <SumEngine/Inc/SumEngine.h>
#include "GameState.h"
#include "EditTemplateState.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	SumEngine::App& mainApp = SumEngine::MainApp();

	SumEngine::AppConfig config;
	config.appName = L"Editor";
	config.winWidth = 1280;
	config.winHeight = 780;
	mainApp.AddState<GameState>("GameState");
	mainApp.AddState<GameState>("EditTemplateState");
	mainApp.Run(config);
	return(0);
}