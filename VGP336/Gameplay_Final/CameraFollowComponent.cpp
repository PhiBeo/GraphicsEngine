#include "CameraFollowComponent.h"

#include "CameraFollowService.h"

using namespace SumEngine;
using namespace SumEngine::Input;

void CameraFollowComponent::Initialize()
{
	mCameraComponent = GetOwner().GetComponent<CameraComponent>();
	CameraFollowService* cfs = GetOwner().GetWorld().GetService<CameraFollowService>();
	cfs->SetCamera(this);

	mStartPos = mCameraComponent->GetCamera().GetPosition();
}

void CameraFollowComponent::Terminate()
{
	CameraFollowService* cfs = GetOwner().GetWorld().GetService<CameraFollowService>();
	cfs->UnSetCamera(this);
}

void CameraFollowComponent::Deserialize(const rapidjson::Value& value)
{
	SaveUtil::ReadFloat("Speed", mSpeed, value);
	SaveUtil::ReadFloat("RunSpeed", mRunSpeed, value);
}

void CameraFollowComponent::SetPosition(SumEngine::Math::Vector3 pos) const
{
	Graphics::Camera& camera = mCameraComponent->GetCamera();
	camera.SetPosition(pos);
}

SumEngine::Math::Vector3 CameraFollowComponent::GetPosition() const
{
	return mCameraComponent->GetCamera().GetPosition();
}

SumEngine::Math::Vector3 CameraFollowComponent::GetStartPosition() const
{
	return mStartPos;
}
