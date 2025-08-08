#include "Folder.h"

void Folder::OnCollision(Actor* other)
{
	if (other->tag != this->tag) {
		
	}
}

void Folder::OpenFolder(const Folder& openedFolder, Folder& workingFolder)
{
	for (Folder& folder : _folders) {
		if (openedFolder._name == folder._name) {
			
		}
	}
}
