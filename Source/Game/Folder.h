#pragma once
#include "Core/StringHelper.h"
#include "Framework/Actor.h"
#include <vector>


class Folder : public whermst::Actor{
public:
	Folder() = default;
	Folder(const whermst::Transform& transform, whermst::res_t<whermst::Texture> texture, std::string name = "Steve Jobs", bool isEncrypted = false) : Actor{transform, texture} {
		_name =  name;
		_encrypted = isEncrypted;
		_texture = texture;
	}

	bool AddFolder(Folder addedFolder) {
		bool yes = false;
		for (Folder folder : _folders) {
			if (folder._name == addedFolder._name) yes = true;
		}
		if (yes) {
			_folders.push_back(addedFolder);
		}
		return yes;
	}

	void OnCollision(Actor* other) override;

	void OpenFolder(const Folder& folder, Folder& workingFolder);

private:
	std::string _name;
	std::vector<Folder> _folders;
	bool _encrypted;

	

};