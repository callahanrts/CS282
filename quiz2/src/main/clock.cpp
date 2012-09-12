#include <iostream>
#include <chrono>
#include <thread>
#include "clock.h"
using namespace std;

simphys::Clock::Clock(float startTime):paused{false}, timeScale{1.0f}{
	//TODO Not implemented yet
  freq      = 1000000;
  ticks     = secondsToTicks(startTime);

	/*std::cout << 
	"Start Time: " << startTime << endl << 
	"Frequency: "<< freq << endl <<
	"timeScale: " << timeScale << endl <<
	"Ticks: " << ticks << endl <<
	endl << endl << endl;*/
}

long long simphys::Clock::secondsToTicks(float seconds) const {
	return (long long)(freq * seconds);
}

float simphys::Clock::ticksToSeconds(long long ticks) const {
	return (float)(ticks / freq);
}

void simphys::Clock::update(float dt){
	//TODO Not implemented yet
	if(!paused)
	{
		ticks += secondsToTicks(dt * timeScale);

		//std::cout << "Ticks: "<< ticks << std::endl;
	}
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

