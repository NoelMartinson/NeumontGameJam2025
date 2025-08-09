#include "Folder.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

void Folder::OnCollision(Actor* other)
{
	if (other->tag != this->tag) {
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

void Folder::Draw(whermst::Renderer& renderer) {
	float width = (float)renderer.GetWidth();
	float height = (float)renderer.GetHeight();
	whermst::vec2 position{ width * 0.2f, height * 0.2f };
	for (auto folder : _folders) {
		folder.transform.position = position;
		renderer.DrawTexture(folder._texture.get(), folder.transform.position.x, folder.transform.position.y, folder.transform.rotation, folder.transform.scale);
		folder.transform.position.y -= 100;
	}
}
