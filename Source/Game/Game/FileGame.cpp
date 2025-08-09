#include "FileGame.h"  
#include "Framework/Scene.h"  
#include "../Folder.h"  
#include "Core/Logger.h"  
#include "Framework/Actor.h"  
#include "Core/StringHelper.h"  
#include "Engine.h"  
#include "../Cursor.h"

bool FileGame::Initialize()  
{  
	_scene = std::make_unique<whermst::Scene>(this);  
	whermst::Transform transform{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.2f, whermst::GetEngine().GetRenderer().GetHeight() * 0.2f}, 0, 2 };
	auto folder = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()));
	folder->tag = "File";
	_scene->AddActor(std::move(folder));
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
		whermst::Transform cursorTransform{ whermst::GetEngine().GetInput().GetMousePosition(), 0, .2f };
		auto cursor = std::make_unique<Cursor>(cursorTransform, whermst::Resources().Get<whermst::Texture>("Assets/emptyFolder.png", whermst::GetEngine().GetRenderer()));
		cursor->name = "Cursor";
		cursor->tag = "Cursor";
		_scene->AddActor(std::move(cursor));
	}
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
	if(_scene->GetActorByName<Cursor>("Cursor")) {
		_scene->RemoveRecentActors();
	}
}
