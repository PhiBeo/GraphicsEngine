#pragma once

#include "TypeIds.h"

namespace SumEngine
{
	class GameObject;
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		Component(const Component&) = delete;
		Component(const Component&&) = delete;
		Component& operator=(const Component&) = delete;
		Component& operator=(const Component&&) = delete;

		virtual void Initialize() {};
		virtual void Terminate() {};
		virtual void Update(float deltaTime) {};
		virtual void DebugUI() {}

		//saving data to a file
		virtual void Serialize(rapidjson::Document& doc, rapidjson::Value& value, const rapidjson::Value& original) {}
		//reading data from a file
		virtual void Deserialize(const rapidjson::Value& value) {}

		virtual uint32_t GetTypeId() const = 0;

		GameObject& GetOwner() { return *mOwner; }
		const GameObject& GetOwner() const { return *mOwner; }

	private:
		friend class GameObject;
		GameObject* mOwner = nullptr;
	};
}