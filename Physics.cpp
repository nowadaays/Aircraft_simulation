#include "Physics.h"

const float AIR_DENSITY = 1.225f; // плотность воздуха в кг/м^3

sf::Vector2f Physics::calculateAcceleration(float mass, float windSpeed, float windAngle) {
    // расчеты ускорения ветра
    return sf::Vector2f(windSpeed * std::cos(windAngle) / mass, windSpeed * std::sin(windAngle) / mass);
}

sf::Vector2f Physics::calculateGravity(float mass) {
    const float GRAVITY = 9.81f;
    return sf::Vector2f(0.0f, GRAVITY * mass);
}

sf::Vector2f Physics::calculateDrag(sf::Vector2f velocity, float dragCoefficient, float crossSectionalArea) {
    float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    float dragForce = 0.5f * AIR_DENSITY * speed * speed * dragCoefficient * crossSectionalArea;
    return sf::Vector2f(-dragForce * velocity.x / speed, -dragForce * velocity.y / speed);
}