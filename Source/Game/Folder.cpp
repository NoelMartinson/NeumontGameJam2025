#include "Folder.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Core/File.h"

void Folder::OnCollision(Actor* other)
{
	if (whermst::tolower(other->tag) != whermst::tolower(tag)) {
		Logger::Info("Folder: {} collided with {}", this->_name, other->name);
		std::string folderName = name;

		if (whermst::file::Exists(folderName)) {
			Logger::Info("Folder: {} exists", folderName);
		}
		else {
			Logger::Warning("Folder: {} does not exist", folderName);
		}
	}
}

void Folder::OpenFolder(const Folder* openedFolder, Folder*& workingFolder)
{
	for (Folder* folder : _folders) {
		if (openedFolder && openedFolder->_name == folder->_name) {
			if (folder->_encrypted) {
				// trigger mini-game later
			}
			else {
				workingFolder = folder; // switch current view
			}
			return;
		}
	}
}

void Folder::Draw(whermst::Renderer& renderer) {
	float width = (float)renderer.GetWidth();
	float height = (float)renderer.GetHeight();
	whermst::vec2 position{ width * 0.2f, height * 0.2f };
	for (auto folder : _folders) {
		folder->transform.position = position;
		renderer.DrawTexture(folder->_texture.get(), folder->transform.position.x, folder->transform.position.y, folder->transform.rotation, folder->transform.scale);
		position.y += 100;
	}
}


bool Folder::AddFolder(Folder* addedFolder) {
	for (Folder* folder : _folders) {
		if (folder->_name == addedFolder->_name) return false;
	}
	_folders.push_back(addedFolder);
	addedFolder->_parentFolder = this;


	return true;
}
