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
    SumEngine::Graphics::DirectionalLight mDirectionalLight;

    SumEngine::Graphics::StandardEffect mStandardEffect;
    SumEngine::Graphics::GaussianBlurEffect mGaussianBlurEffect;
    SumEngine::Graphics::PostProcessingEffect mPostProcessingEffect;

    SumEngine::Graphics::RenderGroup mCharacter;
    SumEngine::Graphics::RenderObject mGround;
    SumEngine::Graphics::RenderObject mScreenQuad;

    SumEngine::Graphics::RenderTarget mRenderTarget;
    SumEngine::Graphics::RenderTarget mBloomRenderTarget;
};