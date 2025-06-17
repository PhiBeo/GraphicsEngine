#pragma once

#include "CustomTypeId.h"

class BulletComponent;

class BulletShootService : public SumEngine::Service
{
public:
	SET_TYPE_ID(CustomServiceId::BulletShoot);

	void Update(float deltaTime) override;

	void Register(const BulletComponent* bulletComponent);
	void Unregister(const BulletComponent* bulletComponent);

	void ShotBullet(SumEngine::Math::Vector3 pos, SumEngine::Math::Vector3 direction);

private:
	using BulletComponents = std::vector<const BulletComponent*>;
	BulletComponents mBullets;
};