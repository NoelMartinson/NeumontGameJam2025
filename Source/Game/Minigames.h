#pragma once
#include "Resources/Resource.h"
#include "Renderer/Texture.h"
#include "Renderer/Renderer.h"

class Minigames {
public:
	enum class MinigameType {
		Captcha,
		Maze
	};
	enum class Captcha {
		CraigsList,
		GR528,
		ejujle,
		Wrans
	};
public:
	Minigames() = default;
	void StartMinigame(MinigameType type, whermst::Renderer& renderer);
	bool IsMinigameActive() { return _isMinigameActive; }
	void SetMinigameActive(bool active) { _isMinigameActive = active; }
	MinigameType GetCurrentMinigameType() const { return _currentMinigameType; }

	void Draw(whermst::Renderer& renderer);

private:
	MinigameType _currentMinigameType{ MinigameType::Captcha };
	bool _isMinigameActive{ false };
	std::shared_ptr<whermst::Texture> texture;
	whermst::Texture* texturep;
};
