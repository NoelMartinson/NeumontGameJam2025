#pragma once

#include "Core/File.h"
#include "Core/Logger.h"
#include "Folder.h"
#include "Engine.h"
#include "Framework/Scene.h"

class Level {
public:
	enum class level {
		ROOT = 0,
		LEVEL1,
		LEVEL2,
		LEVEL3
	};
public:
	Level() = default;

	void GoToLevel(whermst::Scene* scene, int levelNumber) {
		switch (static_cast<level>(levelNumber)) {
		case level::ROOT:
		{
			std::unique_ptr<Folder> folder;
			whermst::Transform transform{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.2f, whermst::GetEngine().GetRenderer().GetHeight() * 0.2f}, 0, 2 };
			folder = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "root");
			folder->tag = "File";
			Folder* folderPtr = folder.get();
			scene->AddActor(std::move(folder));
			whermst::Transform transform1{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.2f, whermst::GetEngine().GetRenderer().GetHeight() * 0.2f}, 0, 2 };
			std::unique_ptr<Folder> folder1 = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "test1");
			folder1->tag = "File";

			folderPtr->AddFolder(std::move(folder1));
		}
				break;
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
