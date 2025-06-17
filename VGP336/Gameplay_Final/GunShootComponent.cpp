#include "GunShootComponent.h"

#include "BulletShootService.h"
#include "CustomCharacterMovementComponent.h"

using namespace SumEngine;
using namespace SumEngine::Input;

void GunShootComponent::Initialize()
{
	mTransformComponent = GetOwner().GetComponent<TransformComponent>();
	mSoundEffectComponent = GetOwner().GetComponent<SoundEffectComponent>();
	mCharacter = GetOwner().GetComponent<CustomCharacterMovementComponent>();
	mTransformComponent->position = SumEngine::Math::Vector3::Zero;
}

void GunShootComponent::Terminate()
{

}

void GunShootComponent::Update(float deltaTime)
{
	auto* input = InputSystem::Get();

	mTransformComponent->position;

	if (input->IsMousePressed(MouseButton::LBUTTON))
	{
		//mSoundEffectComponent->Play();
		LOG("Shoot Bullet");
		BulletShootService* bss = GetOwner().GetWorld().GetService<BulletShootService>();
		bss->ShotBullet(mTransformComponent->position, mCharacter->GetFacingDirection());
	}
}

void GunShootComponent::Deserialize(const rapidjson::Value& value)
{

}

SumEngine::Math::Vector3 GunShootComponent::CalculateDirection()
{
	return SumEngine::Math::Vector3();
}
