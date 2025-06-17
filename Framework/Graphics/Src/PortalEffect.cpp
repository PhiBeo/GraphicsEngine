#include "Precompiled.h"
#include "PortalEffect.h"
#include "VertexTypes.h"
#include "Camera.h"
#include "RenderObject.h"

using namespace SumEngine;
using namespace SumEngine::Graphics;

void PortalEffect::Initialize(const std::filesystem::path& path)
{
    mVertexShader.Initialize<Vertex>(path);
    mPixelShader.Initialize(path);
    mSampler.Initialize(Sampler::Filter::Linear, Sampler::AddressMode::Wrap);

    mTransformBuffer.Initialize();
    mLightBuffer.Initialize();
    mMaterialBuffer.Initialize();
    mSettingsBuffer.Initialize();
}

void PortalEffect::Terminate()
{
    mSettingsBuffer.Terminate();
    mMaterialBuffer.Terminate();
    mLightBuffer.Terminate();
    mTransformBuffer.Terminate();
    mSampler.Terminate();
    mPixelShader.Terminate();
    mVertexShader.Terminate();
}

void PortalEffect::Begin()
{
    mVertexShader.Bind();
    mPixelShader.Bind();
    mSampler.BindPS(0);

    mTransformBuffer.BindVS(0);

    mLightBuffer.BindVS(1);
    mLightBuffer.BindPS(1);

    mMaterialBuffer.BindPS(2);

    mSettingsBuffer.BindVS(3);
    mSettingsBuffer.BindPS(3);
}

void PortalEffect::End()
{

    // begin left render
    // render scene
    // end left render
    // begin right render
    // render scene
    // end render

    // render portal left with right render target
    // render portal right with left render target
    // when render, need to set the specific camera to the standard effect
    // after all rendered, need to render standard effect a third time, then render portals
    // render target into portal
    // render moving target through "PortalEffect" not standard
}

void PortalEffect::Render(const RenderObject& renderObject)
{
    ASSERT(mCamera != nullptr, "PortalEffect: must have a camera");
    SettingsData settingsData;
    settingsData.useDiffuseMap = mSettingsData.useDiffuseMap > 0 && renderObject.diffuseMapId > 0;
    settingsData.useNormalMap = mSettingsData.useNormalMap > 0 && renderObject.normalMapId > 0;
    settingsData.useSpecMap = mSettingsData.useSpecMap > 0 && renderObject.specMapId > 0;
    settingsData.useBumpMap = mSettingsData.useBumpMap > 0 && renderObject.bumpMapId > 0;
    settingsData.bumpWeight = mSettingsData.bumpWeight;
    settingsData.useShadowMap = false;
    settingsData.depthBias = mSettingsData.depthBias;

    const Math::Matrix4 matWorld = renderObject.transform.GetMatrix4();
    const Math::Matrix4 matView = mCamera->GetViewMatrix();
    const Math::Matrix4 matProj = mCamera->GetProjectionMatrix();

    const Math::Matrix4 matFinal = matWorld * matView * matProj;

    TransformData transformData;
    transformData.wvp = Transpose(matFinal);
    transformData.world = Transpose(matWorld);
    transformData.viewPosition = mCamera->GetPosition();

    mSettingsBuffer.Update(settingsData);
    mTransformBuffer.Update(transformData);
    mLightBuffer.Update(*mDirectionalLight);
    mMaterialBuffer.Update(renderObject.material);

    TextureCache* tc = TextureCache::Get();
    tc->BindPS(renderObject.diffuseMapId, 0);
    tc->BindPS(renderObject.normalMapId, 1);
    tc->BindPS(renderObject.specMapId, 2);
    tc->BindVS(renderObject.bumpMapId, 3);

    renderObject.meshBuffer.Render();
}

void PortalEffect::Render(const RenderGroup& renderGroup)
{
    ASSERT(mCamera != nullptr, "PortalEffect: must have a camera");

    const Math::Matrix4 matWorld = renderGroup.transform.GetMatrix4();
    const Math::Matrix4 matView = mCamera->GetViewMatrix();
    const Math::Matrix4 matProj = mCamera->GetProjectionMatrix();

    const Math::Matrix4 matFinal = matWorld * matView * matProj;

    SettingsData settingsData;
    settingsData.useShadowMap = false;
    settingsData.depthBias = mSettingsData.depthBias;
    settingsData.bumpWeight = mSettingsData.bumpWeight;

    TransformData transformData;
    transformData.wvp = Transpose(matFinal);
    transformData.world = Transpose(matWorld);
    transformData.viewPosition = mCamera->GetPosition();

    mTransformBuffer.Update(transformData);
    mLightBuffer.Update(*mDirectionalLight);
    for (const RenderObject& renderObject : renderGroup.renderObjects)
    {
        mMaterialBuffer.Update(renderObject.material);

        settingsData.useDiffuseMap = mSettingsData.useDiffuseMap > 0 && renderObject.diffuseMapId > 0;
        settingsData.useNormalMap = mSettingsData.useNormalMap > 0 && renderObject.normalMapId > 0;
        settingsData.useSpecMap = mSettingsData.useSpecMap > 0 && renderObject.specMapId > 0;
        settingsData.useBumpMap = mSettingsData.useBumpMap > 0 && renderObject.bumpMapId > 0;
        mSettingsBuffer.Update(settingsData);

        TextureCache* tc = TextureCache::Get();
        tc->BindPS(renderObject.diffuseMapId, 0);
        tc->BindPS(renderObject.normalMapId, 1);
        tc->BindPS(renderObject.specMapId, 2);
        tc->BindVS(renderObject.bumpMapId, 3);

        renderObject.meshBuffer.Render();
    }
}

void PortalEffect::SetRightPortalPosition(const Math::Vector3& pos)
{
    mRightPortal.renderObject.transform.position = pos;
}

void PortalEffect::SetLeftPortalPosition(const Math::Vector3& pos)
{
    mLeftPortal.renderObject.transform.position = pos;
}

void PortalEffect::SetCamera(const Camera& camera)
{
    mCamera = &camera;
}

void PortalEffect::SetDirectionalLight(const DirectionalLight& directionalLight)
{
    mDirectionalLight = &directionalLight;
}

void PortalEffect::DebugUI()
{
    if (ImGui::CollapsingHeader("PortalEffect", ImGuiTreeNodeFlags_DefaultOpen))
    {
        bool useDiffuse = mSettingsData.useDiffuseMap > 0;
        if (ImGui::Checkbox("UseDiffuse", &useDiffuse))
        {
            mSettingsData.useDiffuseMap = (useDiffuse) ? 1 : 0;
        }
        bool useNormal = mSettingsData.useNormalMap > 0;
        if (ImGui::Checkbox("UseNormal", &useNormal))
        {
            mSettingsData.useNormalMap = (useNormal) ? 1 : 0;
        }
        bool useSpec = mSettingsData.useSpecMap > 0;
        if (ImGui::Checkbox("UseSpec", &useSpec))
        {
            mSettingsData.useSpecMap = (useSpec) ? 1 : 0;
        }
        bool useBump = mSettingsData.useBumpMap > 0;
        if (ImGui::Checkbox("UseBump", &useBump))
        {
            mSettingsData.useBumpMap = (useBump) ? 1 : 0;
        }
        ImGui::DragFloat("BumpWeight", &mSettingsData.bumpWeight, 0.01f, 0.0f, 10000.0f);
    }
}
