#pragma once

class WindowContext {
	public:
		int width, height;
		WindowContext(int width, int height) {
			this->width = width;
			this->height = height;
		}
};