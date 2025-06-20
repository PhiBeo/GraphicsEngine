#pragma once


#include "RigidBody.h"
#include "CollisionShape.h"

namespace SumEngine::Physics
{
    struct ParticleInfo
    {
        float lifeTime = 0.0f;
        Color startColor = Colors::White;
        Color endColor = Colors::White;
        Math::Vector3 startScale = Math::Vector3::One;
        Math::Vector3 endScale = Math::Vector3::One;
    };

    class Particle
    {
    public:
        void Initialize();
        void Terminate();
        void Activate(const ParticleInfo& info, const Math::Vector3& position, const Math::Vector3& velocity);
        void Update(float deltaTime);

        bool IsActive() const;
        const Graphics::Transform& GetTransform() const;
        Color GetColor() const;
        const Math::Vector3& GetPosition() const;
    private:
        Graphics::Transform mTransform;
        RigidBody mRigidBody;
        CollisionShape mCollisionShape;

        ParticleInfo mInfo;
        float mLifeTime = 0.0f;
    };
}