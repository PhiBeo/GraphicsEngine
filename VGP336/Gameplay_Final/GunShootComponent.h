#pragma once

#include "CustomTypeId.h"

class CustomCharacterMovementComponent;
class GunShootComponent : public SumEngine::Component
{
public:
	SET_TYPE_ID(CustomComponentId::GunShoot);

	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Deserialize(const rapidjson::Value& value) override;

	SumEngine::Math::Vector3 CalculateDirection();

private:
	SumEngine::TransformComponent* mTransformComponent = nullptr;
	SumEngine::SoundEffectComponent* mSoundEffectComponent = nullptr;
	CustomCharacterMovementComponent* mCharacter = nullptr;
};