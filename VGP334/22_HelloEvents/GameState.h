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
    void OnMoveEvent();
    void OnSpacePressedEvent(const SumEngine::Event& e);

    SumEngine::Graphics::Camera mCamera;

    SumEngine::Graphics::RenderObject mBall;
    SumEngine::Graphics::RenderObject mGround;
    SumEngine::Graphics::DirectionalLight mDirectionalLight;
    SumEngine::Graphics::StandardEffect mStandardEffect;

    SumEngine::Math::Vector3 mOffset = { 0.0f, 0.0f, 0.0f };
    SumEngine::ListenerId mSpacePressedEventId = 0;
    SumEngine::Audio::SoundId mGunEventId = 0;
    SumEngine::Audio::SoundId mExplosionEventId = 0;

    // animation
    SumEngine::Graphics::Animation mAnimation;
    float mAnimationTime = 0.0f;
};