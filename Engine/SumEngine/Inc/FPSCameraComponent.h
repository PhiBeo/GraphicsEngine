#pragma once

#include "Component.h"

namespace SumEngine
{
	class CameraComponent;
	class FPSCameraComponent final : public Component
	{
	public:
		SET_TYPE_ID(ComponentId::FPSCamera);
		
		void Initialize() override;
		void Terminate() override;
		void Update(float deltaTime) override;
		void Deserialize(const rapidjson::Value& value) override;
		void Serialize(rapidjson::Document& doc, rapidjson::Value& value, const rapidjson::Value& original) override;

	private:
		CameraComponent* mCameraComponent = nullptr;
		float mShiftSpeed = 10.f;
		float mMoveSpeed = 1.f;
		float mTurnSpeed = .1f;
	};
}