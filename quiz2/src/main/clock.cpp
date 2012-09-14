#include <iostream>
#include <chrono>
#include <thread>
#include "clock.h"
using namespace std;

simphys::Clock::Clock(float startTime)
{
	paused    = false;
	timeScale = 1.0f;
  freq      = 1000000;
  ticks     = (startTime > 0) ? secondsToTicks(startTime) : 0;
}

void simphys::Clock::update(float dt){
	if(!paused)
	{
		ticks += freq * dt * timeScale;
	}
}

long long simphys::Clock::secondsToTicks(float seconds) const {
	return (freq * seconds);
}

float simphys::Clock::ticksToSeconds(long long ticks) const {
	return (float)(ticks / freq);
}

void simphys::Clock::setFreq(float newFreq){
	freq = newFreq;
}

float simphys::Clock::getFreq() const {
	return freq;
}

void simphys::Clock::setScale(float newScale){
	timeScale = newScale;
}

float simphys::Clock::getScale() const{
	return timeScale;
}

void simphys::Clock::setPaused(bool isPaused){
	paused = isPaused;
}

bool simphys::Clock::getPaused() const{
	return paused;
}

long long simphys::Clock::getTicks() const{
	return ticks;
}

