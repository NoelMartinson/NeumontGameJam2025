#pragma once
#include "Renderer/Model.h"
#include "Framework/Actor.h"
#include "Core/Logger.h"



class Cursor : public whermst::Actor {
public:
	Cursor() = default;
	Cursor(const whermst::Transform& transform, whermst::res_t<whermst::Texture> texture) : Actor{ transform, texture } {}
	~Cursor() = default;

	void Update(float dt) override {
		// Update cursor position based on input

		Actor::Update(dt);
	}

	void OnCollision(Actor* other) override {
		Logger::Info("Cursor: {} collided with {}", this->name, other->name);
		if (other->tag == "File") {
			//dynamic_cast<Folder*>(other)->OpenFolder(*dynamic_cast<Folder*>(other), FileGame::GetWorkingFolder());
		}
	}
private:
	std::vector<whermst::vec2> cursor{ {0,0} };
	whermst::Model model = whermst::Model(cursor);
	
};