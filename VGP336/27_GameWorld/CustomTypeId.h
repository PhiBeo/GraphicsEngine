#pragma once
#include <SumEngine/Inc/SumEngine.h>

enum class CustomComponentId
{
	CustomDebugDraw = static_cast<uint32_t>(SumEngine::ComponentId::Count)
};

enum class CustomServiceId
{
	CustomDebugDrawDisplay = static_cast<uint32_t>(SumEngine::ServiceId::Count)
};