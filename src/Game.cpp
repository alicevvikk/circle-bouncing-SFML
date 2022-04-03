#include "Game.hpp"
#include <iostream>

const int DEFAULT_SCREEN_WIDTH = 800;
const int DEFAULT_SCREEN_HEIGHT = 600;

Game::Game() {
	setScreenWidth(DEFAULT_SCREEN_WIDTH);
	setScreenHeight(DEFAULT_SCREEN_HEIGHT);
	
}

Game::Game(int width, int height) {
	setScreenWidth(width);
	setScreenHeight(height);
}

void Game::addCircle(CustomCircle &circle) {	
	circles.push_back(circle);
}

void Game::setScreenWidth(int width) {
	screen_width = width;
}

void Game::setScreenHeight(int height) {
	screen_height = height;
}

void Game::handleUserEvents(sf::RenderWindow &window) {
	
	sf::Event event;

	while (window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed){
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				float mouse_x = event.mouseButton.x;
				float mouse_y = event.mouseButton.y;
				handleCollision(mouse_x, mouse_y);
			}
		}
		if (event.type == sf::Event::MouseButtonReleased) {
		}
	}

}


void Game::handleCollision(float mouse_x, float mouse_y) {
	int len = this->circles.size();
	float circle_x, circle_y;

	for (int i =0; i < len; ++i) {
		CustomCircle circle = circles[i];
		circle_x = circle.getPosition().x;
	        circle_y = circle.getPosition().y;
		
		if ( mouse_x < circle_x + 2 * circle.getRadius() && 
 		     mouse_x > circle_x && 
		     mouse_y < circle_y + 2 * circle.getRadius() && 
		     mouse_y > circle_y) {
			std::cout << "Collision with " << i << ". circle\n";
			circles[i].setMovable();	
		}
	}
}


void Game::run() {
	sf::RenderWindow window(sf::VideoMode(screen_width, 
					      screen_height), 
					      "Game Template");

	window.setFramerateLimit(60);
	while (window.isOpen()) 
	{
		
		handleUserEvents(window);
		
		window.clear(sf::Color::Black);
		
		for (int i = 0; i < circles.size(); ++i) {
			circles[i].handleImpacts();
			window.draw(circles[i]);
		}

		window.display();
	}
}


