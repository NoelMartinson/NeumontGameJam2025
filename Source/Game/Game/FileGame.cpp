#include "FileGame.h"
#include "Framework/Scene.h"
#include "../Folder.h"

bool FileGame::Initialize()
{
	_scene = std::make_unique<whermst::Scene>(this);
	return true;
}

void FileGame::Update(float dt)
{
	switch (gameState)
	{
	case GameState::Initialize:
		gameState = GameState::Title;
		break;
	case GameState::Title:
		auto folder = std::make_shared<Folder>("Player", false);
		_scene->AddActor(folder);
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
	_scene->Draw(renderer);
}
