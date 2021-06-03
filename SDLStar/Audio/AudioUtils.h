#pragma once

#include <cmath>

int FreqToNote(float frequence, float Hz) {
	return (sqrt(frequence / (Hz / 32)) * 12.0) + 9;
}

float noteToFreq(int note, float Hz) {
    return (Hz / 32) * pow(2, ((note - 9) / 12.0));
}