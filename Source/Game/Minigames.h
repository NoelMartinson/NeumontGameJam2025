#pragma once

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
	void StartMinigame(MinigameType type);
	bool IsMinigameActive() const;
	MinigameType GetCurrentMinigameType() const { return _currentMinigameType; };

private:
	MinigameType _currentMinigameType{ MinigameType::Captcha };
};
