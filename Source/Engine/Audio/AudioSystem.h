#pragma once
#include "Resources/Resource.h"
#include <fmod.hpp>
#include <string>
#include <map>

namespace whermst {
	class AudioSystem : public Resource {
	public:
		AudioSystem() = default;

		bool Initialize();
		void Close();

		void Update();

		bool Load(const std::string& filename, const std::string& name = "filename");

		bool PlaySound(const std::string& name/*, const int volume*/);

	private:
		bool CheckFmodResult(FMOD_RESULT result);

	private:
		FMOD::System* _system = nullptr;
		std::map<std::string, FMOD::Sound*> _sounds;
	};
}
