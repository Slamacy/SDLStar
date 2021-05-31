#pragma once

class SP_AudioDevice {
	private:
		int index;
		const char* deviceName;
	
	public:
		int getIndex();
	
		const char* getName();
	
		SP_AudioDevice(int idx, const char* name);
};