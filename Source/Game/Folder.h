#pragma once
#include "Core/StringHelper.h"
#include "Framework/Actor.h"
#include <vector>
#include <iostream>


class Folder : public whermst::Actor{
public:
	Folder() = default;
	Folder(const whermst::Transform& transform, whermst::res_t<whermst::Texture> texture, std::string name = "Steve Jobs", bool isEncrypted = false) : Actor{transform, texture} {
		_name =  name;
		_encrypted = isEncrypted;
		_texture = texture;
	}

	void Update(float dt) override {
		// Update logic for the folder, if any
		Actor::Update(dt);
	}

	bool AddFolder(Folder* addedFolder) {
		for (Folder* folder : _folders) {
			if (folder->_name == addedFolder->_name) return false;
		}
		_folders.push_back(addedFolder);
		addedFolder->_parentFolder = this;

		
		return true;
	}

	void OnCollision(Actor* other) override;

	void Draw(class whermst::Renderer& renderer);

	void OpenFolder(const Folder& folder, Folder& workingFolder);

private:
	std::string _name;
	std::vector<Folder*> _folders;
	bool _encrypted;

	Folder* _parentFolder = nullptr;

};