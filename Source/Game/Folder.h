#pragma once
#include "Core/StringHelper.h"

class Folder {
public:
	Folder() = default;
	Folder(std::string name) {
		_name =  name;
	}


private:
	std::string _name;
};