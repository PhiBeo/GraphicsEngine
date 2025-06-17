#pragma once

#include <SumEngine/Inc/SumEngine.h>

class GameState : public SumEngine::AppState
{
public:
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void Render() override;

protected:
    void UpdateCamera(float deltaTime);

    SumEngine::Graphics::Camera mCamera;
    SumEngine::Graphics::ConstantBuffer mConstantBuffer;
    SumEngine::Graphics::MeshBuffer mMeshBuffer;
    SumEngine::Graphics::VertexShader mVertexShader;
    SumEngine::Graphics::PixelShader mPixelShader;
    SumEngine::Graphics::Texture mDiffuseTexture;
    SumEngine::Graphics::Sampler mSampler;
};