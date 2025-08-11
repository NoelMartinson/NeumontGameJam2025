#pragma once

#include "Core/File.h"
#include "Core/Logger.h"
#include "Folder.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Framework/Actor.h"

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
			whermst::Transform transform{ whermst::vec2{ whermst::GetEngine().GetRenderer().GetWidth() * 0.2f, whermst::GetEngine().GetRenderer().GetHeight() * 0.2f}, 0, 2 };
			folder = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "root");
			folder->tag = "File";
			Folder* rootPtr = folder.get();
			scene->AddActor(std::move(folder));

			std::unique_ptr<Folder> level1 = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "Level1");
			std::unique_ptr<Folder> level2 = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "Level2");
			std::unique_ptr<Folder> level3 = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "Level3");
			level1->tag = "File";
			level2->tag = "File";
			level3->tag = "File";


			Folder* level1Ptr = level1.get();
			rootPtr->AddFolder(std::move(level1));
			rootPtr->AddFolder(std::move(level2));
			rootPtr->AddFolder(std::move(level3));


		}
				break;
		case level::LEVEL1:
		{
			whermst::Transform transform{ whermst::vec2{whermst::GetEngine().GetRenderer().GetWidth() * 0.2f, whermst::GetEngine().GetRenderer().GetHeight() * 0.2f}, 0, 2 };
			std::unique_ptr<Folder> Captcha = std::make_unique<Folder>(transform, whermst::Resources().Get<whermst::Texture>("Assets/Folder.png", whermst::GetEngine().GetRenderer()), "Captcha", true);
			Captcha->tag = "File";
			scene->AddActor(std::move(Captcha));
		}
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
