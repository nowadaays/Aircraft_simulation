#ifndef PHYSICS_H
#define PHYSICS_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Physics {
public:
    static sf::Vector2f calculateAcceleration(float mass, float windSpeed, float windAngle);
    static sf::Vector2f calculateGravity(float mass);
    static sf::Vector2f calculateDrag(sf::Vector2f velocity, float dragCoefficient, float crossSectionalArea);
};
#endif