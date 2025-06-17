#pragma once

#include <SumEngine/Inc/SumEngine.h>

class EditTemplateState : public SumEngine::AppState
{
public:
	~EditTemplateState() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(const float deltaTime) override;
	void Render() override;
	void DebugUI() override;

private:

	SumEngine::GameWorld mGameWorld;
};