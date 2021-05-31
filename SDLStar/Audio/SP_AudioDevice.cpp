#include "SP_AudioDevice.h"

#include "SDL.h"

#include <cstdio>
#include <iostream>
		
int SP_AudioDevice::getIndex() {
	return this->index;
}

const char* SP_AudioDevice::getName() {
	return this->deviceName;
}
	
SP_AudioDevice::SP_AudioDevice(int idx, const char* name) {
	index = idx;
	deviceName = name;

	SDL_LogDebug(0, "New Audio Device: (%d, %s) \n", index, deviceName);
}