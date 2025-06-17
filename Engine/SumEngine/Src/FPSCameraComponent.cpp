#include "Precompiled.h"
#include "FPSCameraComponent.h"
#include "SaveUtil.h"

#include "CameraComponent.h"
#include "GameObject.h"

using namespace SumEngine;
using namespace SumEngine::Graphics;
using namespace SumEngine::Input;
using namespace SumEngine::Math;

void FPSCameraComponent::Initialize()
{
	mCameraComponent = GetOwner().GetComponent<CameraComponent>();
	ASSERT(mCameraComponent != nullptr, "FPSCameraComponent: camera was not found");
}

void FPSCameraComponent::Terminate()
{
	mCameraComponent = nullptr;
}

void FPSCameraComponent::Update(float deltaTime)
{
	Camera& camera = mCameraComponent->GetCamera();

	auto input = Input::InputSystem::Get();
	const float moveSpeed = input->IsKeyDown(KeyCode::LSHIFT) ? mShiftSpeed : mMoveSpeed;
	const float turnSpeed = mTurnSpeed;

	if (input->IsKeyDown(KeyCode::W))
	{
		camera.Walk(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::S))
	{
		camera.Walk(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::D))
	{
		camera.Strafe(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::A))
	{
		camera.Strafe(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::E))
	{
		camera.Rise(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::Q))
	{
		camera.Rise(-moveSpeed * deltaTime);
	}
	if (input->IsMouseDown(MouseButton::RBUTTON))
	{
		camera.Yaw(input->GetMouseMoveX() * turnSpeed * deltaTime);
		camera.Pitch(input->GetMouseMoveY() * turnSpeed * deltaTime);
	}
}

void FPSCameraComponent::Deserialize(const rapidjson::Value& value)
{
	SaveUtil::ReadFloat("MoveSpeed", mMoveSpeed, value);
	SaveUtil::ReadFloat("ShiftSpeed", mShiftSpeed, value);
	SaveUtil::ReadFloat("TurnSpeed", mTurnSpeed, value);
}

void SumEngine::FPSCameraComponent::Serialize(rapidjson::Document& doc, rapidjson::Value& value, const rapidjson::Value& original)
{
	rapidjson::Value componentValue(rapidjson::kObjectType);
	SaveUtil::WriteFloat("MoveSpeed", mMoveSpeed, doc, componentValue);
	SaveUtil::WriteFloat("ShiftSpeed", mShiftSpeed, doc, componentValue);
	SaveUtil::WriteFloat("TurnSpeed", mTurnSpeed, doc, componentValue);
	value.AddMember("FPSCameraComponent", componentValue, doc.GetAllocator());
}
