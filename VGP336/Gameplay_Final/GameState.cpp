#include "GameState.h"

#include "CustomDebugDrawComponent.h"
#include "CustomCharacterMovementComponent.h"
#include "CameraFollowComponent.h"
#include "GunShootComponent.h"
#include "BulletComponent.h"

#include "CustomDebugDrawService.h"
#include "CameraFollowService.h"
#include "BulletShootService.h"

using namespace SumEngine;
using namespace SumEngine::Graphics;
using namespace SumEngine::Math;
using namespace SumEngine::Input;
using namespace SumEngine::Audio;

Service* CustomServiceMake(const std::string& serviceName, GameWorld& gameWorld)
{
	if (serviceName == "CustomDebugDrawService")
	{
		return gameWorld.AddService<CustomDebugDrawService>();
	}
	else if (serviceName == "CameraFollowService")
	{
		return gameWorld.AddService<CameraFollowService>();
	}
	else if (serviceName == "BulletShootService")
	{
		return gameWorld.AddService<BulletShootService>();
	}
	return nullptr;
}

Component* CustomComponentMake(const std::string& componentName, GameObject& gameObject)
{
	if (componentName == "CustomDebugDrawComponent")
	{
		return gameObject.AddComponent<CustomDebugDrawComponent>();
	}
	else if (componentName == "CustomCharacterMovementComponent")
	{
		return gameObject.AddComponent<CustomCharacterMovementComponent>();
	}
	else if (componentName == "FollowCameraComponent")
	{
		return gameObject.AddComponent<CameraFollowComponent>();
	}
	else if (componentName == "GunShootComponent")
	{
		return gameObject.AddComponent<GunShootComponent>();
	}
	else if (componentName == "BulletComponent")
	{
		return gameObject.AddComponent<BulletComponent>();
	}
	return nullptr;
}

Component* CustomComponentGet(const std::string& componentName, GameObject& gameObject)
{
	if (componentName == "CustomDebugDrawComponent")
	{
		return gameObject.GetComponent<CustomDebugDrawComponent>();
	}
	else if (componentName == "CustomCharacterMovementComponent")
	{
		return gameObject.GetComponent<CustomCharacterMovementComponent>();
	}
	else if (componentName == "FollowCameraComponent")
	{
		return gameObject.GetComponent<CameraFollowComponent>();
	}
	return nullptr;
}

void GameState::Initialize()
{
	GameWorld::SetCustomService(CustomServiceMake);
	GameObjectFactory::SetCustomMake(CustomComponentMake);
	GameObjectFactory::SetCustomGet(CustomComponentGet);
	mGameWorld.LoadLevel(L"../../Assets/Templates/Levels/game_level.json");
}

void GameState::Terminate()
{
	mGameWorld.Terminate();
}

void GameState::Update(const float deltaTime)
{
	mGameWorld.Update(deltaTime);
}

void GameState::Render()
{
	mGameWorld.Render();
}

void GameState::DebugUI()
{
	ImGui::Begin("Debug Control", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

	mGameWorld.DebugUI();

	ImGui::End();
}


