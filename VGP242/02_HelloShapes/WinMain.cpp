#include <SumEngine/Inc/SumEngine.h>

#include "ShapeState.h"

using namespace SumEngine;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    AppConfig config;
    config.appName = L"Hello Shapes";

    App& myApp = MainApp();
    myApp.AddState<TriangleShapeState>("TriangleShapeState");
    myApp.AddState<SquareShapeState>("SquareShapeState");
    myApp.Run(config);
    return(0);
}