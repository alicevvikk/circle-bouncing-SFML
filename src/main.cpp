#include "Game.hpp"
#include "CustomCircle.hpp"


int main(){
	CustomCircle circle(50.f, true, 5, 200, 330);
	CustomCircle circle2(50.f, true, 7, 300, 200);
	CustomCircle circle3(20.f, true, 5, 600, 440);
	CustomCircle circle4(20.f, true, 11,500);

	circle.setFillColor(sf::Color::Green);
	circle2.setFillColor(sf::Color::Blue);
	circle3.setFillColor(sf::Color::Red);
	
	Game game;

	game.addCircle(circle);
	game.addCircle(circle2);
	game.addCircle(circle3);
	game.addCircle(circle4);
	game.run();

}
