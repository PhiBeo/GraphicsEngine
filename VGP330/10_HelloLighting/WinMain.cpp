#include <SumEngine/Inc/SumEngine.h>

#include "GameState.h"

using namespace SumEngine;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    AppConfig config;
    config.appName = L"Hello Simple Draw";

    App& myApp = MainApp();
    myApp.AddState<GameState>("GameState");
    myApp.Run(config);
    return(0);
}