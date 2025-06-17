#include "BulletShootService.h"

#include "BulletComponent.h"

using namespace SumEngine;
using namespace SumEngine::Graphics;
using namespace SumEngine::Math;

void BulletShootService::Update(float deltaTime)
{
	
}

void BulletShootService::Register(const BulletComponent* bulletComponent)
{
	auto iter = std::find(mBullets.begin(), mBullets.end(),
		bulletComponent);

	if (iter == mBullets.end())
	{
		mBullets.push_back(bulletComponent);
	}
}

void BulletShootService::Unregister(const BulletComponent* bulletComponent)
{
	auto iter = std::find(mBullets.begin(), mBullets.end(),
		bulletComponent);

	if (iter != mBullets.end())
	{
		mBullets.erase(iter);
	}
}

void BulletShootService::ShotBullet(SumEngine::Math::Vector3 pos, SumEngine::Math::Vector3 direction)
{
	for (const BulletComponent* component : mBullets)
	{
		if (!component->IsActive())
		{
			component->SetupBullet(pos, direction);
			break;
		}
	}
}
