#include "BulletComponent.h"

#include "BulletShootService.h"

using namespace SumEngine;

void BulletComponent::Initialize()
{
	mTransformComponent = GetOwner().GetComponent<TransformComponent>();
	BulletShootService* bss = GetOwner().GetWorld().GetService<BulletShootService>();
	bss->Register(this);
}

void BulletComponent::Terminate()
{
	BulletShootService* bss = GetOwner().GetWorld().GetService<BulletShootService>();
	bss->Unregister(this);
}

void BulletComponent::Update(float deltaTime)
{
	if (!mIsActive) return;

	SumEngine::Math::Vector3 velocity = mDirection * mSpeed;
	SumEngine::Math::Vector3 displacement = velocity * deltaTime;

	SumEngine::Math::Vector3 newPos = mTransformComponent->position + displacement;

	mTransformComponent->position = newPos;

	mCurrentLifeTime -= deltaTime;

	if (mCurrentLifeTime <= 0)
	{
		mIsActive = false;
	}
}

void BulletComponent::Deserialize(const rapidjson::Value& value)
{
	SaveUtil::ReadFloat("LifeTime", mLifetime, value);
	SaveUtil::ReadFloat("Speed", mSpeed, value);
}

void BulletComponent::DebugUI()
{
	ImGui::DragFloat("CurrentLifeTime", &mCurrentLifeTime, 0.1f);
	ImGui::Checkbox("Is Active", &mIsActive);
}

void BulletComponent::SetupBullet(SumEngine::Math::Vector3 startPoint, SumEngine::Math::Vector3 direction) const
{
	mCurrentLifeTime = mLifetime;
	mIsActive = true;
	mTransformComponent->position = startPoint;
	mDirection = direction;
}
