#pragma once


namespace SumEngine
{
	enum class ComponentId
	{
		Invalid,		//default value, not valid
		Transform,		//transform component for location data
		Camera,			//contains the Camera for viewing
		FPSCamera,		//nove the camera with FPS controls
		Mesh,			//add a mesh shape to a gameobject
		Model,			//add a model to the gameobject
		Animator,		//add animation controller to the gameobject
		RigidBody,		//add a physics body shape to the game object
		SoundEffect,	//add a sound effect to the object
		SoundBank,		//add a group of sound effects to an object
		UIText,			//add a ui text component
		UISprite,		//add a sprite to the UI
		UIButton,		//add a button to the UI
		Count			//last value, chain ids in custom components
	};

	enum class ServiceId
	{
		Invalid,		//default value, not valid
		Camera,			//manages the cameras in the world
		Render,			//render object to the world
		Physics,		//manage the physics system for game objects
		UIRender,		//render ui object to the world
		Count			//last value, chain ids in custom services
	};
}

#define SET_TYPE_ID(id)\
	static uint32_t StaticGetTypeId() {return static_cast<uint32_t>(id);}\
	uint32_t GetTypeId() const override {return StaticGetTypeId();}