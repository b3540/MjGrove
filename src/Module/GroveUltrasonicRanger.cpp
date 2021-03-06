#include "GroveUltrasonicRanger.h"
#include <Arduino.h>

unsigned long GroveUltrasonicRanger::MicrosDiff(unsigned long begin, unsigned long end)
{
	return end - begin;
}

unsigned long GroveUltrasonicRanger::PulseIn(bool state, unsigned long timeout)
{
	auto begin = micros();

	// wait for any previous pulse to end
	while (_Pin->Read() == state) if (MicrosDiff(begin, micros()) >= timeout) return 0;

	// wait for the pulse to start
	while (_Pin->Read() != state) if (MicrosDiff(begin, micros()) >= timeout) return 0;
	auto pulseBegin = micros();

	// wait for the pulse to stop
	while (_Pin->Read() == state) if (MicrosDiff(begin, micros()) >= timeout) return 0;
	auto pulseEnd = micros();

	return MicrosDiff(pulseBegin, pulseEnd);
}

void GroveUltrasonicRanger::Init()
{
	_Pin->SetMode(GroveGpio::MODE_INPUT);
}

void GroveUltrasonicRanger::Read()
{
	_Pin->SetMode(GroveGpio::MODE_OUTPUT);
	_Pin->Write(true);
	delayMicroseconds(10);

	_Pin->Write(false);
	_Pin->SetMode(GroveGpio::MODE_INPUT);

	auto duration = PulseIn(true);
	if (duration == 0)
	{
		Distance = 0;
		return;
	}

	Distance = (float)duration * 0.34f / 2.0f;
}
