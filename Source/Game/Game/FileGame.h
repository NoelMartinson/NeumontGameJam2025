#pragma once
#include "Framework/Game.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Audio/AudioSystem.h"

class FileGame : public whermst::Game {
public:
	enum class GameState {
		Initialize,

	};

public:
	FileGame() = default;

	bool Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;
	void Draw(class whermst::Renderer& renderer);

private:
	GameState gameState = GameState::Initialize;
};