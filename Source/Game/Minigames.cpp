#include "Minigames.h"
#include "Core/Logger.h"
#include "Core/Random.h"

void Minigames::StartMinigame(MinigameType type)
{
	_currentMinigameType = type;
	switch (type)
	{
	case MinigameType::Captcha:
	{
		int captcha = whermst::random::getInt(0, 3); // Randomly select a captcha
		switch (static_cast<Captcha>(captcha))
		{
		case Captcha::CraigsList:
			// Start CraigsList captcha minigame
			Logger::Info("Starting CraigsList captcha minigame");
			break;
		case Captcha::GR528:
			// Start GR528 captcha minigame
			Logger::Info("Starting GR528 captcha minigame");
			break;
		case Captcha::ejujle:
			// Start ejujle captcha minigame
			Logger::Info("Starting ejujle captcha minigame");
			break;
		case Captcha::Wrans:
			// Start Wrans captcha minigame
			Logger::Info("Starting Wrans captcha minigame");
			break;
		}
	}
		break;
	case MinigameType::Maze:
		// Start Maze minigame
		break;
	default:
		Logger::Error("Unknown minigame type: {}", static_cast<int>(type));
		break;
	}
	Logger::Info("Started minigame of type: {}", static_cast<int>(type));
}

bool Minigames::IsMinigameActive() const
{
	return false;
}

