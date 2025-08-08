#include "Folder.h"
#include "Engine.h"
#include "Input/InputSystem.h"

void Folder::OnCollision(Actor* other)
{
	if (other->tag != this->tag) {
	 if (whermst::GetEngine().GetInput().GetMouseButtonPressed(whermst::InputSystem::MouseButton::Left)) {
		 
	 }
	}
}
