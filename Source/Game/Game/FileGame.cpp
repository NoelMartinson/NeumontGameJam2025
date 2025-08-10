#include "FileGame.h"  
#include "Framework/Scene.h"  
#include "../Folder.h"  
#include "Core/Logger.h"  
#include "Framework/Actor.h"  
#include "Core/StringHelper.h"  
#include "Engine.h"  
#include "../Cursor.h"
#include "Renderer/Text.h"
#include "../Level.h"

bool FileGame::Initialize()  
{ 
	_scene = std::make_unique<whermst::Scene>(this); 
	Level level = Level();
	level.GoToLevel(_scene.get(), 0); // Initialize the root folder
	
	_namesText = std::make_unique<whermst::Text>(whermst::Resources().Get<whermst::Font>("Assets/FileName.ttf", 40));


	whermst::Transform cursorTransform{ whermst::GetEngine().GetInput().GetMousePosition(), 0, .2f };
	auto cursor = std::make_unique<Cursor>(cursorTransform, whermst::Resources().Get<whermst::Texture>("Assets/emptyFolder.png", whermst::GetEngine().GetRenderer()));
	cursor->name = "Cursor";
	cursor->tag = "Cursor";
	_scene->AddActor(std::move(cursor));
	
	
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
	{
		if (whermst::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_BACKSPACE)) {
			Folder::GoBack();
		}
	}
		break;  
	case GameState::Game:  
		// Main game logic  
		break;  
	case GameState::GameOver:  
		// Game over logic  
		break;  
	}
	_scene->Update(dt, 1.0f);
}  

void FileGame::Shutdown()  
{  
}  

void FileGame::Draw(class whermst::Renderer& renderer) { 
	if (_minigames->IsMinigameActive()) {
		_minigames->Draw(renderer);
	}
		_scene->Draw(renderer);
	_namesText->Create(renderer, Folder::getWorkingFolder()->name, { 0, 0, 0 });
	_namesText->Draw(renderer, 20, 20);
}
