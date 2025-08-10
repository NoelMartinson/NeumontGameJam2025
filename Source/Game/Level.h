#pragma once

#include "Core/File.h"
#include "Core/Logger.h"

class Level {
public:
	enum class level {
		LEVEL1,
		LEVEL2,
		LEVEL3
	};
public:
	Level() = default;

	void GoToLevel(int levelNumber) {
		switch (static_cast<level>(levelNumber)) {
		case level::LEVEL1:
			// Load Level 1
			break;
		case level::LEVEL2:
			// Load Level 2
			break;
		case level::LEVEL3:
			// Load Level 3
			break;
		default:
			Logger::Error("Invalid level number: {}", levelNumber);
			break;
		}
	}

private:
	
};
