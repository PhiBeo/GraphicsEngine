#include "CustomCharacterMovementComponent.h"

#include "CameraFollowService.h"

using namespace SumEngine;
using namespace SumEngine::Input;

void CustomCharacterMovementComponent::Initialize()
{
	mRigidBodyComponent = GetOwner().GetComponent<RigidBodyComponent>();
	mTransformComponent = GetOwner().GetComponent<TransformComponent>();
	mAnimatorComponent = GetOwner().GetComponent<AnimatorComponent>();
	//mModelTransformComponent = GetOwner().GetChild(0)->GetComponent<TransformComponent>();

	CameraFollowService* cfs = GetOwner().GetWorld().GetService<CameraFollowService>();
	cfs->SetPlayer(this);

	mStartPos = mTransformComponent->position;
}

void CustomCharacterMovementComponent::Terminate()
{
	CameraFollowService* cfs = GetOwner().GetWorld().GetService<CameraFollowService>();
	cfs->UnSetPlayer(this);
}

void CustomCharacterMovementComponent::Update(float deltaTime)
{
	UpdateMovement();
	UpdateRotation();
}

void CustomCharacterMovementComponent::Deserialize(const rapidjson::Value& value)
{
	SaveUtil::ReadFloat("Speed", mSpeed, value);
	SaveUtil::ReadFloat("RunSpeed", mRunSpeed, value);
}

Math::Vector3 CustomCharacterMovementComponent::GetPosition() const
{
	return mPosition;
}

SumEngine::Math::Vector3 CustomCharacterMovementComponent::GetStartPosition() const
{
	return mStartPos;
}

SumEngine::Math::Vector3 CustomCharacterMovementComponent::GetFacingDirection() const
{
	SumEngine::Math::Vector3 forward = SumEngine::Math::Vector3::Zero;
	
	forward = { -mTransformComponent->GetMatrix4()._31, 0.0f, -mTransformComponent->GetMatrix4()._33 };

	return SumEngine::Math::Normalize(forward);
}

void CustomCharacterMovementComponent::UpdateMovement()
{
	float horizontalSpeed = 0.0f;
	float verticalSpeed = 0.0f;

	auto input = InputSystem::Get();
	float currentSpeed = input->IsKeyDown(KeyCode::LSHIFT) ? mRunSpeed : mSpeed;

	if (input->IsKeyDown(KeyCode::W))
	{
		verticalSpeed = currentSpeed;
	}
	else if (input->IsKeyDown(KeyCode::S))
	{
		verticalSpeed = -currentSpeed;
	}
	if (input->IsKeyDown(KeyCode::A))
	{
		horizontalSpeed = -currentSpeed;
	}
	else if (input->IsKeyDown(KeyCode::D))
	{
		horizontalSpeed = currentSpeed;
	}

	mRigidBodyComponent->SetVelocity({ horizontalSpeed, mRigidBodyComponent->GetVelocity().y, verticalSpeed });

	mPosition = mTransformComponent->position;

	if (horizontalSpeed != 0 || verticalSpeed != 0)
	{
		currentState = AnimationState::Run;
	}
	else
	{
		currentState = AnimationState::Idle;
	}

	UpdateAnimationState();
}

void CustomCharacterMovementComponent::UpdateRotation()
{
	float angle = 0.5f;

	auto input = InputSystem::Get();
	
	if (input->IsKeyDown(KeyCode::E))
	{
		mRigidBodyComponent->SetAngularVelocity({ 0,-angle,0 });
	}
	else if (input->IsKeyDown(KeyCode::Q))
	{
		mRigidBodyComponent->SetAngularVelocity({ 0,angle,0 });
	}
	else
	{
		mRigidBodyComponent->SetAngularVelocity({ 0,0,0 });
	}
}

void CustomCharacterMovementComponent::UpdateAnimationState()
{
	if (currentState == LastState) return;

	mAnimatorComponent->Play((int)currentState, true);
	LastState = currentState;
}
