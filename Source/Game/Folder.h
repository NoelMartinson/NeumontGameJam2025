#pragma once
#include "Core/StringHelper.h"
#include <vector>
#include <memory>

class Folder {
public:
	Folder() = default;
	Folder(std::string name, bool isEncrypted) {
		_name =  name;
		_encrypted = isEncrypted;
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

	

private:
	std::string _name;
	std::vector<Folder> _folders;

	bool _encrypted;

	

};