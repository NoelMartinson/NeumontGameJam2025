#include "FileGame.h"

bool FileGame::Initialize()
{
	return false;
}

void FileGame::Update(float dt)
{
	switch (gameState)
	{
	case GameState::Initialize:
		// Initialization logic
		break;
	case GameState::Title:
		// Title screen logic
		break;
	case GameState::Game:
		// Main game logic
		break;
	case GameState::GameOver:
		// Game over logic
		break;
	}
}

void FileGame::Shutdown()
{
}
void FileGame::Draw(class whermst::Renderer& renderer) {

}
