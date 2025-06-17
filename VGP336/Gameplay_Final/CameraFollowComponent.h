#pragma once

#include "CustomTypeId.h"

class CameraFollowComponent : public SumEngine::Component
{
public:
	SET_TYPE_ID(CustomComponentId::FollowCamera);

	void Initialize() override;
	void Terminate() override;
	void Deserialize(const rapidjson::Value& value) override;

	void SetPosition(SumEngine::Math::Vector3 pos) const;
	SumEngine::Math::Vector3 GetPosition() const;
	SumEngine::Math::Vector3 GetStartPosition() const;

private:
	const SumEngine::TransformComponent* mTransformComponent = nullptr;
	SumEngine::CameraComponent* mCameraComponent = nullptr;

	SumEngine::Math::Vector3 mStartPos = SumEngine::Math::Vector3::Zero;

	float mSpeed = 0.0f;
	float mRunSpeed = 0.0f;
};