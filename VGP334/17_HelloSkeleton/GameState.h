#pragma once

#include <SumEngine/Inc/SumEngine.h>


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

    // level data
    SumEngine::Graphics::Camera mCamera;
    SumEngine::Graphics::DirectionalLight mDirectionalLight;
    SumEngine::Graphics::StandardEffect mStandardEffect;

    // character data
    SumEngine::Graphics::RenderGroup mCharacter;

    // ground data
    SumEngine::Graphics::RenderObject mGround;

    bool mShowSkeleton = false;
};