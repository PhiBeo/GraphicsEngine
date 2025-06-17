#pragma once

#include "PhysicsObject.h"

namespace SumEngine::Physics
{
    class CollisionShape;

    class RigidBody final : public PhysicsObject
    {
    public:
        RigidBody() = default;
        ~RigidBody() override;

        void Initialize(SumEngine::Graphics::Transform& graphicsTransform, const CollisionShape& shape, float mass = 0.0f, bool addToWorld = true);
        void Terminate();

        void SetPosition(const SumEngine::Math::Vector3& position);
        void SetVelocity(const SumEngine::Math::Vector3& velocity);
        void SetAngularVelocity(const SumEngine::Math::Vector3& velocity);
        const Math::Vector3 GetVelocity() const;

        void Activate();
        void Deactivate();

        bool IsDynamic() const;

    private:
        void SyncWithGraphics() override;
        btRigidBody* GetRigidBody() override;

        btRigidBody* mRigidBody = nullptr;
        btDefaultMotionState* mMotionState = nullptr;
        float mMass = 0.0f;

        SumEngine::Graphics::Transform* mGraphicsTransform = nullptr;
    };
}