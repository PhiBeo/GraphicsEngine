#pragma once

#include "CustomTypeId.h"

enum class AnimationState 
{
	None,
	Idle,
	Run
};

class CustomCharacterMovementComponent : public SumEngine::Component
{
public:
	SET_TYPE_ID(CustomComponentId::PlayerMovement);

	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Deserialize(const rapidjson::Value& value) override;

	SumEngine::Math::Vector3 GetPosition() const;
	SumEngine::Math::Vector3 GetStartPosition() const;
	SumEngine::Math::Vector3 GetFacingDirection() const;

private:
	void UpdateMovement();
	void UpdateRotation();
	void UpdateAnimationState();

	const SumEngine::TransformComponent* mTransformComponent = nullptr;
	SumEngine::RigidBodyComponent* mRigidBodyComponent = nullptr;
	SumEngine::AnimatorComponent* mAnimatorComponent = nullptr;
	SumEngine::TransformComponent* mModelTransformComponent = nullptr;

	SumEngine::Math::Vector3 mPosition = SumEngine::Math::Vector3::Zero;
	SumEngine::Math::Vector3 mStartPos = SumEngine::Math::Vector3::Zero;

	AnimationState currentState = AnimationState::None;
	AnimationState LastState = AnimationState::None;

	float mSpeed = 0.0f;
	float mRunSpeed = 0.0f;
};