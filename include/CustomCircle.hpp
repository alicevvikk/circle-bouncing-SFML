#ifndef CUSTOM_CIRCLE
#define CUSTOM_CIRCLE

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

class CustomCircle: public sf::CircleShape {
	public:
		CustomCircle(float r, int movable, float vel, 
			     float x = 0, float y = 0);
		void freeFall(const int height);
		void push();
		void move(float , float );
		void handleImpacts();
		void setMovable();
	private:
		float r;
		float vel;
		float x_vel;
		float y_vel;
		int movable;				
		
}; 

#endif

