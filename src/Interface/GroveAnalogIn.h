#pragma once

#include <Arduino.h>

class GroveAnalogIn
{
private:
	uint8_t _Pin;

public:
	const int MAX_VALUE = 4095;

public:
	GroveAnalogIn(int pin)
	{
		_Pin = pin;
	}

	void Enable()
	{
		pinMode(_Pin, INPUT_ANALOG);
	}

	int Read()
	{
		return analogRead(_Pin);
	}

};
