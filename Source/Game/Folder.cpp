#include "Folder.h"
#include "Engine.h"
#include "Input/InputSystem.h"

void Folder::OnCollision(Actor* other)
{
	if (whermst::tolower(other->tag) != whermst::tolower(tag)) {
		Logger::Info("Folder: {} collided with {}", this->_name, other->name);
	}
}

void Folder::OpenFolder(const Folder& openedFolder, Folder& workingFolder)
{
	for (Folder& folder : _folders) {
		if (openedFolder._name == folder._name) {
			
		}
	}
}
