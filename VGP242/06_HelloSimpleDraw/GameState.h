#pragma once

#include <SumEngine/Inc/SumEngine.h>

enum class DebugDrawType
{
    None,
    Line,
    Sphere
};

class GameState : public SumEngine::AppState
{
public:
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void Render() override;
    void DebugUI() override;

protected:
    void UpdateCamera(float deltaTime);
    SumEngine::Graphics::Camera mCamera;
    DebugDrawType mDebugDrawType = DebugDrawType::None;
};