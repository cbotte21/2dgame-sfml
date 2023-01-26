#pragma once

#include <string>

class PlayerContext {
	std::string token, texture;
	int x, y;
	public:
		PlayerContext(std::string token, std::string texture, int x, int y) {
			this->token = token;
			this->texture = texture;
			this->x = x;
			this->y = y;
		}
		std::string getToken() {
			return token;
		}
		std::string getTexture() {
			return texture;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
};
