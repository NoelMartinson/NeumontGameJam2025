#pragma once
#include "Renderer/Model.h"
#include "Framework/Actor.h"


class Cursor : public whermst::Actor {
public:
	Cursor() = default;
	~Cursor() = default;
private:
	std::vector<whermst::vec2> cursor{ {0,0} };
	whermst::Model model = whermst::Model(cursor);
};