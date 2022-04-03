#ifndef GAME_TEMPLATE_H
#define GAME_TEMPLATE_H

#include <SFML/Graphics.hpp>
#include "CustomCircle.hpp"

extern const int DEFAULT_SCREEN_WIDTH;
extern const int DEFAULT_SCREEN_HEIGHT;

class Game {
	private:
		int screen_width;
		int screen_height;
		void setScreenWidth(int width);
		void setScreenHeight(int height);

	public:
		Game(int width, int height);
		Game();
		
		void run();
		void handleUserEvents(sf::RenderWindow &);
		void addCircle(CustomCircle &circle);
		void handleCollision(float, float);
         	std::vector<CustomCircle> circles;    

};

#endif
