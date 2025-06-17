#include "Precompiled.h"
#include "RigidBodyComponent.h"

#include "GameWorld.h"
#include "PhysicsService.h"
#include "TransformComponent.h"

using namespace SumEngine;

void RigidBodyComponent::Initialize()
{
	PhysicsService* ps = GetOwner().GetWorld().GetService<PhysicsService>();
	if (ps != nullptr)
	{
		TransformComponent* transformComponent = GetOwner().GetComponent<TransformComponent>();
		mRigidBody.Initialize(*transformComponent, mCollsionShape, mMass, false);
		ps->Register(this);
	}
}	 
	 
void RigidBodyComponent::Terminate()
{	
	PhysicsService* ps = GetOwner().GetWorld().GetService<PhysicsService>();
	if (ps != nullptr)
	{
		ps->Register(this);
	}

	mRigidBody.Terminate();
	mCollsionShape.Terminate();
} 
	 
void RigidBodyComponent::Deserialize(const rapidjson::Value& value)
{
	if (value.HasMember("Mass"))
	{
		mMass = value["Mass"].GetFloat();
	}

	if (value.HasMember("ColliderData"))
	{
		mCollsionShape.Terminate();
		auto colliderData = value["ColliderData"].GetObj();
		if (colliderData.HasMember("Shape"))
		{
			std::string shape = colliderData["Shape"].GetString();
			if (shape == "Empty")
			{
				mCollsionShape.InitializeEmpty();
			}
			else if (shape == "Box")
			{
				const auto halfExtents = colliderData["HalfExtents"].GetArray();
				const float x = halfExtents[0].GetFloat();
				const float y = halfExtents[1].GetFloat();
				const float z = halfExtents[2].GetFloat();
				mCollsionShape.InitializeBox({ x,y,z });
			}
			else if (shape == "Sphere")
			{
				const float radius = colliderData["Radius"].GetFloat();
				mCollsionShape.InitializeSphere(radius);
			}
			else if (shape == "Capsule")
			{
				const float height = colliderData["Height"].GetFloat();
				const float radius = colliderData["Radius"].GetFloat();
				mCollsionShape.InitializeCapsule(radius, height);
			}
			else if (shape == "Hull")
			{
				const auto halfExtents = colliderData["HalfExtents"].GetArray();
				const float hx = halfExtents[0].GetFloat();
				const float hy = halfExtents[1].GetFloat();
				const float hz = halfExtents[2].GetFloat();
				const auto origin = colliderData["Origin"].GetArray();
				const float ox = origin[0].GetFloat();
				const float oy = origin[1].GetFloat();
				const float oz = origin[2].GetFloat();

				mCollsionShape.InitializeHull({ hx,hy,hz }, { ox,oy,oz });
			}
			else
			{
				ASSERT(false, "RigidBodyComponent: Invalid Shape type %s", shape.c_str());
			}
		}
		else
		{
			ASSERT("RigidBodyComponent: requires shape data");
		}
	}
}	 
	 
void RigidBodyComponent::SetPosition(const Math::Vector3& position)
{
	mRigidBody.SetPosition(position);
}	 
	 
void RigidBodyComponent::SetVelocity(const Math::Vector3& velocity)
{
	mRigidBody.SetVelocity(velocity);
}
	 
void RigidBodyComponent::SetAngularVelocity(const Math::Vector3& velocity)
{
	mRigidBody.SetAngularVelocity(velocity);
}

Math::Vector3 SumEngine::RigidBodyComponent::GetVelocity()
{
	return mRigidBody.GetVelocity();
}
