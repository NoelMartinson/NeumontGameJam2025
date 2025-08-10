#include "Minigames.h"
#include "Core/Logger.h"
#include "Core/Random.h"
#include "Engine.h"
#include "Core/StringHelper.h"

void Minigames::StartMinigame(MinigameType type, whermst::Renderer& renderer)
{
	_currentMinigameType = type;
	switch (type)
	{
	case MinigameType::Captcha:
	{
		std::string guess;
		int captcha = whermst::random::getInt(0, 3); // Randomly select a captcha
		while (_isMinigameActive) {
			switch (static_cast<Captcha>(captcha))
			{
			case Captcha::CraigsList:
				// Start CraigsList captcha minigame
				Logger::Info("Starting CraigsList captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("Assets/CraigsList.png", whermst::GetEngine().GetRenderer());
				//texturep = whermst::Texture(whermst::Resources().Get<whermst::Texture>("Assets/CraigsList.png", whermst::GetEngine().GetRenderer()));
				whermst::GetEngine().GetInput().StartTextInput(renderer);
				guess = whermst::GetEngine().GetInput().GetTextInput();
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("Cralsist")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("CraigsList captcha solved successfully");
						_isMinigameActive = false;
					}
				}
				break;
			case Captcha::GR528:
				// Start GR528 captcha minigame
				Logger::Info("Starting GR528 captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("Assets/GR528.png", whermst::GetEngine().GetRenderer());
				whermst::GetEngine().GetInput().StartTextInput(renderer);
				guess = whermst::GetEngine().GetInput().GetTextInput();
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("gr528")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("GR528 captcha solved successfully");
						_isMinigameActive = false;
					}
				}
				break;
			case Captcha::ejujle:
				// Start ejujle captcha minigame
				Logger::Info("Starting ejujle captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("Assets/ejujle.png", whermst::GetEngine().GetRenderer());
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("ejujle")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("ejujle captcha solved successfully");
						_isMinigameActive = false;
					}
				}
				break;
			case Captcha::Wrans:
				// Start Wrans captcha minigame
				Logger::Info("Starting Wrans captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("Assets/Wrans.png", whermst::GetEngine().GetRenderer());
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("wrans")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("Wrans captcha solved successfully");
						_isMinigameActive = false;
					}
				}
				break;
			}
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

void Minigames::Draw(whermst::Renderer& renderer)
{
	if (_isMinigameActive)
	{
		renderer.DrawTexture(texture.get(), 0, 0);
	}
}
