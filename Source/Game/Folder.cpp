#include "Folder.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Framework/Scene.h"
#include "Core/File.h"


Folder* Folder::_workingFolder = nullptr;

void Folder::OnCollision(Actor* other)
{
	if (whermst::tolower(other->tag) != whermst::tolower(tag)) {
		Logger::Info("Folder: {} collided with {}", this->name, other->name);
		std::string folderName = name;
	}
	if (whermst::tolower(other->tag) == "cursor") {
		if (whermst::GetEngine().GetInput().GetMouseButtonPressed(whermst::InputSystem::MouseButton::Left)) {
			OpenFolder(this, _workingFolder);
		}
	}
}

void Folder::OpenFolder(Folder* openedFolder, Folder*& workingFolder)
{
	Logger::Info("Folder: this folder is opening");
	if (openedFolder) {
		if (openedFolder->_encrypted) {
			// trigger mini-game later
			//return if mini-game is failed
		}	
		_workingFolder = openedFolder; // switch current view
			
		return;
	}
}



void Folder::Draw(whermst::Renderer& renderer) {
	if (this == _workingFolder) {
		float width = (float)renderer.GetWidth();
		float height = (float)renderer.GetHeight();
		whermst::vec2 position{ width * 0.2f, height * 0.2f };
		for (auto folder : _folders) {
			folder->transform.position = position;
			renderer.DrawTexture(folder->_texture.get(), folder->transform.position.x, folder->transform.position.y, folder->transform.rotation, folder->transform.scale);
			position.y += 100;
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
