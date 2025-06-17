#pragma once

#include "CustomTypeId.h"

class CustomCharacterMovementComponent;
class CameraFollowComponent;

class CameraFollowService : public SumEngine::Service
{
public:
	SET_TYPE_ID(CustomServiceId::FollowCamera);

	void Update(float deltaTime) override;

	void SetPlayer(CustomCharacterMovementComponent* character);
	void UnSetPlayer(CustomCharacterMovementComponent* character);

	void SetCamera(CameraFollowComponent* camera);
	void UnSetCamera(CameraFollowComponent* camera);

private:
	CustomCharacterMovementComponent* mCharacterMovement = nullptr;
	CameraFollowComponent* mCameraFollow = nullptr;

	SumEngine::Math::Vector3 offset;
};