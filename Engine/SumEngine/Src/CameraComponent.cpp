#include "Precompiled.h"
#include "CameraComponent.h"

#include "GameObject.h"
#include "GameWorld.h"
#include "CameraService.h"
#include "SaveUtil.h"

using namespace SumEngine;
using namespace SumEngine::Graphics;
using namespace SumEngine::Math;

void CameraComponent::Initialize()
{
	CameraService* cameraService = GetOwner().GetWorld().GetService<CameraService>();
	if (cameraService != nullptr)
	{
		cameraService->Register(this);
	}
}

void CameraComponent::Terminate()
{
	CameraService* cameraService = GetOwner().GetWorld().GetService<CameraService>();
	if (cameraService != nullptr)
	{
		cameraService->Unregister(this);
	}
}

void CameraComponent::DebugUI()
{
	Vector3 pos = mCamera.GetPosition();

	if (ImGui::DragFloat3("Position##Camera", &pos.x, 0.1f))
	{
		mCamera.SetPosition(pos);
	}
}

void CameraComponent::Deserialize(const rapidjson::Value& value)
{
	Math::Vector3 readValue;
	if (SaveUtil::ReadVector3("Position", readValue, value))
	{
		mCamera.SetPosition(readValue);
	}
	if (SaveUtil::ReadVector3("LookAt", readValue, value))
	{
		mCamera.SetLookAt(readValue);
	}
	if (SaveUtil::ReadVector3("Direction", readValue, value))
	{
		mCamera.SetDirection(readValue);
	}
}

void CameraComponent::Serialize(rapidjson::Document& doc, rapidjson::Value& value, const rapidjson::Value& original)
{
	rapidjson::Value componentValue(rapidjson::kObjectType);
	Math::Vector3 readValue;
	if (SaveUtil::ReadVector3("Position", readValue, original))
	{
		SaveUtil::WriteVector3("Position", readValue, doc, componentValue);
	}
	if (SaveUtil::ReadVector3("LookAt", readValue, original))
	{
		SaveUtil::WriteVector3("LookAt", readValue, doc, componentValue);
	}
	if (SaveUtil::ReadVector3("Direction", readValue, original))
	{
		SaveUtil::WriteVector3("Direction", readValue, doc, componentValue);
	}

	value.AddMember("CameraComponent", componentValue, doc.GetAllocator());
}

Camera& CameraComponent::GetCamera()
{
	return mCamera;
}

const Camera& CameraComponent::GetCamera() const
{
	return mCamera;
}
