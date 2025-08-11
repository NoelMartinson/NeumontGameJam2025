#include "Minigames.h"
#include "Core/Logger.h"
#include "Core/Random.h"
#include "Engine.h"
#include "Core/StringHelper.h"

bool Minigames::StartMinigame(whermst::Renderer& renderer)
{
	_currentMinigameType = whermst::random::getInt(0, 1);

	MinigameType type = static_cast<MinigameType>(_currentMinigameType);
	switch (type)
	{
	case MinigameType::Captcha:
	{
		std::string guess;
		int captcha = whermst::random::getInt(0, 3); // Randomly select a captcha
		
			switch (static_cast<Captcha>(captcha))
			{
			case Captcha::CraigsList:
			{// Start CraigsList captcha minigame
				Logger::Info("Starting CraigsList captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("CraigsList.png", whermst::GetEngine().GetRenderer());
				whermst::GetEngine().GetInput().StartTextInput(renderer);
				guess = whermst::GetEngine().GetInput().GetTextInput();
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("Cralsist")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("CraigsList captcha solved successfully");
						
					}
					else {
						return false;
					}

				}
			}
				break;
			case Captcha::GR528:
			{// Start GR528 captcha minigame
				Logger::Info("Starting GR528 captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("GR528.png", whermst::GetEngine().GetRenderer());
				whermst::GetEngine().GetInput().StartTextInput(renderer);
				guess = whermst::GetEngine().GetInput().GetTextInput();
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("gr528")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("GR528 captcha solved successfully");
						
					}
					else {
						return false;
					}
				}
				}
				break;
			case Captcha::ejujle:
			{// Start ejujle captcha minigame
				Logger::Info("Starting ejujle captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("ejujle.png", whermst::GetEngine().GetRenderer());
				whermst::GetEngine().GetInput().StartTextInput(renderer);
				guess = whermst::GetEngine().GetInput().GetTextInput();
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("ejujle")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("ejujle captcha solved successfully");
						
					}
					else {
						return false;
					}
				}
				}
				break;
			case Captcha::Wrans:

			{// Start Wrans captcha minigame
				Logger::Info("Starting Wrans captcha minigame");
				texture = whermst::Resources().Get<whermst::Texture>("Wrans.png", whermst::GetEngine().GetRenderer());
				whermst::GetEngine().GetInput().StartTextInput(renderer);
				guess = whermst::GetEngine().GetInput().GetTextInput();
				if (!guess.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
					if (whermst::tolower(guess) == whermst::tolower("wrans")) {
						whermst::GetEngine().GetInput().StopTextInput(renderer);
						Logger::Info("Wrans captcha solved successfully");
						
					}
					else {
						return false;
					}
				}
			}
				break;
			}
		}
	
		break;
	case MinigameType::Maze:
		// Start Maze minigame
		break;
	case MinigameType::Riddle:
	{
		texture = whermst::Resources().Get<whermst::Texture>("Cataracts.png", whermst::GetEngine().GetRenderer());
		whermst::GetEngine().GetInput().StartTextInput(renderer);
		std::string riddleAnswer;
		while (_isMinigameActive) {
			riddleAnswer = whermst::GetEngine().GetInput().GetTextInput();
			if (!riddleAnswer.empty() && whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_RETURN)) {
				if (whermst::tolower(riddleAnswer) == whermst::tolower("cataracts") || whermst::tolower(riddleAnswer) == whermst::tolower("darkness")) {
					whermst::GetEngine().GetInput().StopTextInput(renderer);
					Logger::Info("Riddle solved successfully");
					_isMinigameActive = false;
				}
			}

		}
	}
	break;
	default:
		Logger::Error("Unknown minigame type: {}", static_cast<int>(type));
		break;
	}
	Logger::Info("Started minigame of type: {}", static_cast<int>(type));
}

void Minigames::Draw(whermst::Renderer& renderer)
{
	renderer.DrawTexture(texture.get(), 0, 0);
}
