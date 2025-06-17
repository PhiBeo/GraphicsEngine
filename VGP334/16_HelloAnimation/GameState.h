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
    SumEngine::Graphics::Camera mCamera;

    SumEngine::Graphics::RenderObject mBall;
    SumEngine::Graphics::RenderObject mGround;
    SumEngine::Graphics::DirectionalLight mDirectionalLight;
    SumEngine::Graphics::StandardEffect mStandardEffect;

    // animation
    SumEngine::Graphics::Animation mAnimation;
    float mAnimationTime = 0.0f;
};