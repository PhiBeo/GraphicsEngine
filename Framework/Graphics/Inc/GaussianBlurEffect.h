#pragma once

#include "ConstantBuffer.h"
#include "PixelShader.h"
#include "Sampler.h"
#include "VertexShader.h"
#include "RenderTarget.h"

namespace SumEngine::Graphics
{
    class RenderObject;

    class GaussianBlurEffect
    {
    public:
        void Initialize();
        void Terminate();

        void Begin();
        void End();

        void Render(const RenderObject& renderObject);

        void DebugUI();

        void SetSourceTexture(const Texture& texture);

        const Texture& GetHorizontalBlurTexture() const;
        const Texture& GetVerticalBlurTexture() const;
        const Texture& GetResultTexture() const;

    private:
        struct SettingsData
        {
            float screenWidth = 0.0f;
            float screenHeight = 0.0f;
            float multiplier = 0.0f;
            float padding = 0.0f;
        };

        using SettingsBuffer = TypedConstantBuffer<SettingsData>;
        SettingsBuffer mSettingsBuffer;

        RenderTarget mHorizonalBlurRenderTarget;
        RenderTarget mVerticalBlurRenderTarget;

        VertexShader mVertexShader;
        PixelShader mHorizontalBlurPixelShader;
        PixelShader mVerticalBlurPixelShader;

        Sampler mSampler;

        const Texture* mSourceTexture = nullptr;

        int mBlurIterations = 10;
        float mBlurSaturation = 1.0f;
    };
}