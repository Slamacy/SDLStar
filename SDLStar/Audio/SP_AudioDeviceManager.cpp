#include "SP_AudioDeviceManager.h"
#include "SDL.h"
#include <iostream>

bool SP_AudioDeviceManager::refreshAudioDevices() {
	const int count = SDL_GetNumAudioDevices(capturing);
	for (int i = 0; i < count; i++) {
		devices->push_back(new SP_AudioDevice(i, SDL_GetAudioDeviceName(i, capturing)));
	}
	return true;
}
	
std::vector<SP_AudioDevice*>* SP_AudioDeviceManager::getAudioDevices() {
	if (devices->size() < 1) {
		this->refreshAudioDevices();
	}
	return devices;
}
	
SP_AudioDeviceManager::SP_AudioDeviceManager() {
	SP_AudioDeviceManager(0);
}
	
SP_AudioDeviceManager::SP_AudioDeviceManager(int capturing) {
	SDL_LogDebug(0, "Registering new AudioDeviceManager. Capturing? %s \n", (capturing > 0 ? "Yes." : "No"));
	this->capturing = capturing;
	this->devices = new std::vector<SP_AudioDevice*>();
	if (!refreshAudioDevices()) {
		SDL_LogError(0, "Failed to initialize Audio Device Manager. refreshAudioDevices() returned false \n");
	}
}
	
SP_AudioDeviceManager::~SP_AudioDeviceManager() {
		delete this->devices;
}