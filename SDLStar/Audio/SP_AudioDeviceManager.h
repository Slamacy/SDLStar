#pragma once

#include "SP_AudioDevice.h"

#include <vector>

class SP_AudioDeviceManager {
	private:
		int capturing;
		std::vector<SP_AudioDevice*>* devices;

	public:
	
		/*
		* Refresh the Audio Devices
		* returns false on error, otherwise true.
		*/
		bool refreshAudioDevices();
	
		/*
		* Get a vector of the Audio Devices.
		*/
		std::vector<SP_AudioDevice*>* getAudioDevices();
	
	
		/*
		* Create a new Audio Device Manager. Set to zero for playback devices (default). For recording devices set to > 0.
		*/
		SP_AudioDeviceManager();
		SP_AudioDeviceManager(int capturing);
	
		~SP_AudioDeviceManager();
};

