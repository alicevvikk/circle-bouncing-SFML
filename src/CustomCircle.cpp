#include "CustomCircle.hpp"
#include <iostream>

CustomCircle::CustomCircle(float r, int movable, float vel,  float x, float y ) { 
	setRadius(r); 
	this->r = r;
	this->vel = vel;
	this->x_vel = vel;
	this->y_vel = vel;
	this->movable = movable;
	setPosition(x, y);
};


void CustomCircle::handleImpacts() {
	float x = getPosition().x;
	float y = getPosition().y;

	if ( x + 2 * getRadius() > 800) {
		x_vel = -vel;
		setFillColor(sf::Color::Green);
		
	} else if ( x < 0) {
		x_vel = vel;
		setFillColor(sf::Color::Blue);
	}

	if ( y + 2 * getRadius() > 600 ) {
		y_vel = -vel;
		setFillColor(sf::Color::White);
	} else if ( y < 0) {
		y_vel = vel;
		setFillColor(sf::Color::Yellow);
	}	

	move(x_vel, y_vel);

}

void CustomCircle::setMovable() {
	movable = !movable;

}

void CustomCircle::move(float x_vel, float y_vel) {
	if (movable){
		float x = getPosition().x;
		float y = getPosition().y;
	
		sf::Vector2<float> newPos(x + x_vel, y + y_vel);
		setPosition(newPos);
	}	
}

