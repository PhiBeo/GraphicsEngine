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

    // ball info
    SumEngine::Graphics::RenderObject mBall;
    SumEngine::Physics::CollisionShape mBallShape;
    SumEngine::Physics::RigidBody mBallRB;

    // ground info
    SumEngine::Graphics::RenderObject mGround;
    SumEngine::Physics::CollisionShape mGroundShape;
    SumEngine::Physics::RigidBody mGroundRB;

    struct BoxData
    {
        SumEngine::Graphics::RenderObject box;
        SumEngine::Physics::CollisionShape boxShape;
        SumEngine::Physics::RigidBody boxRB;
    };
    using Boxes = std::vector<BoxData>;
    Boxes mBoxes;
};