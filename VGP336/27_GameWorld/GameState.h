#pragma once

#include <SumEngine/Inc/SumEngine.h>

class GameState : public SumEngine::AppState
{
public:
	~GameState() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(const float deltaTime) override;
	void Render() override;
	void DebugUI() override;

private:

	SumEngine::GameWorld mGameWorld;
};