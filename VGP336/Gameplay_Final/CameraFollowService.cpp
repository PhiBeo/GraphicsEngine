#include "CameraFollowService.h"

#include "CameraFollowComponent.h"
#include "CustomCharacterMovementComponent.h"

void CameraFollowService::Update(float deltaTime)
{
	if (mCharacterMovement == nullptr || mCameraFollow == nullptr) return;

	offset = mCameraFollow->GetStartPosition() - mCharacterMovement->GetStartPosition();

	SumEngine::Math::Vector3 targetPos = mCharacterMovement->GetPosition();
	SumEngine::Math::Vector3 disiredPos = targetPos + offset;

	mCameraFollow->SetPosition(disiredPos);
}

void CameraFollowService::SetPlayer(CustomCharacterMovementComponent* character)
{
	mCharacterMovement = character;
}

void CameraFollowService::UnSetPlayer(CustomCharacterMovementComponent* character)
{
	mCharacterMovement = nullptr;
}

void CameraFollowService::SetCamera(CameraFollowComponent* camera)
{
	mCameraFollow = camera;
}

void CameraFollowService::UnSetCamera(CameraFollowComponent* camera)
{
	mCameraFollow = nullptr;
}
