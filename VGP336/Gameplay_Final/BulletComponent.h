#pragma once

#include "CustomTypeId.h"

class BulletComponent : public SumEngine::Component
{
public:
	SET_TYPE_ID(CustomComponentId::GunShoot);

	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Deserialize(const rapidjson::Value& value) override;
	void DebugUI() override;

	void SetupBullet(SumEngine::Math::Vector3 startPoint,SumEngine::Math::Vector3 direction) const;
	bool IsActive() const {return mIsActive;}

private:
	SumEngine::TransformComponent* mTransformComponent = nullptr;

	mutable SumEngine::Math::Vector3 mStartPos = SumEngine::Math::Vector3::Zero;
	mutable SumEngine::Math::Vector3 mDirection = SumEngine::Math::Vector3::Zero;

	float mLifetime;
	float mSpeed;
	mutable bool mIsActive = false;
	mutable float mCurrentLifeTime;
};