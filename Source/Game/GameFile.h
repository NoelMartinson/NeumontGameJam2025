#pragma once
#include "Folder.h"

class GameFile : public Folder{
public:
	GameFile() = default;
	~GameFile() = default;

	bool AddFolder(std::unique_ptr<Folder> addedFolder) override;

	void Draw(class whermst::Renderer& renderer) override;

private:

};