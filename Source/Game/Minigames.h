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
	bool StartMinigame(whermst::Renderer& renderer);
	MinigameType GetCurrentMinigameType() const { return static_cast<MinigameType>(_currentMinigameType); }

	void Draw(whermst::Renderer& renderer);

private:
	int _currentMinigameType;
	
	std::shared_ptr<whermst::Texture> texture;
};
