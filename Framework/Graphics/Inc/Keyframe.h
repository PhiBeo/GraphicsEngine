#pragma once

#include "Common.h"

namespace SumEngine::Graphics
{
    template<class T>
    struct Keyframe
    {
        Keyframe() = default;
        Keyframe(const T& k, float t)
            : key(k)
            , time(t)
        {

        }

        T key = T();
        float time = 0.0f;
    };

    template<class T>
    using Keyframes = std::vector<Keyframe<T>>;

    using AnimationCallback = std::function<void()>;

    using PositionKeys = Keyframes<Math::Vector3>;
    using RotationKeys = Keyframes<Math::Quaternion>;
    using ScaleKeys = Keyframes<Math::Vector3>;
    using EventKeys = Keyframes<AnimationCallback>;
}