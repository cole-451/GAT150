#include "AudioSys.h"
#include "Core/Logger.h"
#include <iostream>
#include <fmod_errors.h>
#include <string>

bool parabellum::audiosys::checkFMODResult(FMOD_RESULT result) {
	if (result != FMOD_OK) {
		return false;
		 Logger::Error("Fmod error issue!");
	}
	return true;
}

bool parabellum::audiosys::init() {


	FMOD_RESULT result = FMOD::System_Create(&system);
	if (!checkFMODResult(result)) return false;

	void* extradriverdata = nullptr;
	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata); //inits channels
	if (!checkFMODResult(result)) return false;


	return true;
}

void parabellum::audiosys::GTFO() {
	checkFMODResult(system->release());
}

void parabellum::audiosys::update() {
	checkFMODResult(system->update());
}

bool parabellum::audiosys::addSound(const std::string& filename, const std::string& name)
{
	std::string key = (name.empty()) ? filename : name;
	
	// defaults to lowercase so the system can read it
	for (char& c : key) {
		c = std::tolower(c);
	}

	if (soundmap.find(key) != soundmap.end()) {
		Logger::Error("key already exists.");
		return false;
	}
	FMOD::Sound* sound = nullptr;
	system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound); 

	soundmap[key] = sound;

	return true;
}

bool parabellum::audiosys::playSound(const std::string& name)
{
	std::string key = name;

	//check if sound exists
	if (soundmap.find(key) == soundmap.end()) {
		Logger::Error("sound name doesnt exist");
		return false;
	}

	system->playSound(soundmap[key], 0, false, nullptr);
	return true;
}

