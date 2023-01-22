#pragma once

class Clock {
	long tick;
	int seconds;
	int* fps;
	void calculate() {
		seconds = tick / *fps;
	}
	public:
		Clock(int* fps) {
			tick = 0;
			seconds = 0;
			this->fps = fps;
		}
		void onTick() {
			tick++;
			calculate();
		}
		int getSeconds() {
			return seconds;
		}
		long getTicks() {
			return tick;
		}
};
