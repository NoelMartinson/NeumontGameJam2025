#pragma once
#include "Core/StringHelper.h"
#include "Framework/Actor.h"
#include <vector>
#include <iostream>


class Folder : public whermst::Actor{
public:
	Folder() = default;
	Folder(const whermst::Transform& transform, whermst::res_t<whermst::Texture> texture, std::string name, bool isEncrypted = false) : Actor{transform, texture} {
		this->name =  name;
		_encrypted = isEncrypted;
		_texture = texture;
		if (_workingFolder == nullptr) _workingFolder = this;

		return;
	}

	void Update(float dt) override {
		// Update logic for the folder, if any
		Actor::Update(dt);
	}

	bool AddFolder(std::unique_ptr<Folder> addedFolder);

	void OnCollision(Actor* other) override;

	void Draw(class whermst::Renderer& renderer) override;

	void OpenFolder(Folder* folder, Folder*& workingFolder);

	static void Initialize() { _workingFolder = nullptr; }

	static const Folder* getWorkingFolder() {
		return _workingFolder;
	}

private:
	
	std::vector<Folder*> _folders;
	bool _encrypted;

	Folder* _parentFolder = nullptr;

	static Folder* _workingFolder;

};