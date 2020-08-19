#pragma once
#include <SDL.h>
class BTimer
{
public:
	//Init variables
	BTimer();

	//Clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Get the timer's time
	Uint32 getTicks();

	//Check status of timer
	bool isStarted();
	bool isPaused();

private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;
};