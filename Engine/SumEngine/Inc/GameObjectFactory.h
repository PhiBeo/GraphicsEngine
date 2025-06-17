#pragma once


namespace SumEngine
{
	class GameObject;
	class GameWorld;
	class Component;

	using CustomComponentCB = std::function<Component* (const std::string&, GameObject&)>;

	namespace GameObjectFactory
	{
		void SetCustomMake(CustomComponentCB callback);
		void SetCustomGet(CustomComponentCB callback);
		void Make(const std::filesystem::path& templatePath, GameObject& gameObject, GameWorld& gameWorld);
		void OverrideDeserialize(const rapidjson::Value& value, GameObject& gameObject);
		void SerializeGameObject(rapidjson::Document& doc, const rapidjson::Document& original, GameObject& gameObject);
	}
}