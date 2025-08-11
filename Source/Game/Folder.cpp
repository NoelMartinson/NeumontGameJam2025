#include "Folder.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Framework/Scene.h"
#include "Core/File.h"
#include "Level.h"


Folder* Folder::_workingFolder = nullptr;
Level level = Level();

void Folder::OnCollision(Actor* other)
{
	if (whermst::tolower(other->tag) != whermst::tolower(tag)) {
		Logger::Info("Folder: {} collided with {}", this->name, other->name);
		std::string folderName = name;
	}
	if (whermst::tolower(other->tag) == "cursor") {
		if (whermst::GetEngine().GetInput().GetMouseButtonPressed(whermst::InputSystem::MouseButton::Left)) {
			OpenFolder(this, _workingFolder, goesTo);
			
		}
	}
}

void Folder::OpenFolder(Folder* openedFolder, Folder*& workingFolder, int levelNumber)  
{  
    Logger::Info("Folder: this folder is opening");  
    if (openedFolder) {  
		if (levelNumber != -1) {
			level.GoToLevel(openedFolder->_scene, levelNumber);
		}
        if (openedFolder->_encrypted) {  
            // trigger mini-game later  
            // return if mini-game is failed  
        }  
        _workingFolder = openedFolder; // switch current view  
        return;  
    }  
}



void Folder::Draw(whermst::Renderer& renderer) {
	if (this == _workingFolder) {
		if (_fileNameText == nullptr) {
			_fileNameText = std::make_unique<whermst::Text>(whermst::Resources().Get<whermst::Font>("Assets/FileName.ttf", 40));
			
		}
		float width = (float)renderer.GetWidth();
		float height = (float)renderer.GetHeight();
		whermst::vec2 position{ width * 0.5f, height * 0.2f + 100};
		for (auto folder : _folders) {
			folder->transform.position = position;
			renderer.DrawTexture(folder->_texture.get(), folder->transform.position.x, folder->transform.position.y, folder->transform.rotation, folder->transform.scale);
			_fileNameText->Create(renderer, folder -> name, { 0, 0, 0 });
			_fileNameText->Draw(renderer, position.x + 80, position.y, 1.0f);
			position.y += 150;
		}
	}
}


bool Folder::AddFolder(std::unique_ptr<Folder> addedFolder) {
	
	for (Folder* folder : _folders) {
		if (folder->name == addedFolder->name) return false;
	}
	_folders.push_back(addedFolder.get());
	addedFolder->_parentFolder = this;
	_scene->AddActor(std::move(addedFolder));


	return true;
}
