#include "FlyingObject.h"
#include "Physics.h"

FlyingObject::FlyingObject(float mass, float speed, sf::Vector2f position, float dragCoefficient, float crossSectionalArea)
    : mass(mass), velocity(speed, 0.0f), position(position), dragCoefficient(dragCoefficient), crossSectionalArea(crossSectionalArea) {}

void FlyingObject::update(float windSpeed, float windAngle, float deltaTime) {
    sf::Vector2f acceleration = Physics::calculateAcceleration(mass, windSpeed, windAngle);
    sf::Vector2f gravity = Physics::calculateGravity(mass);
    sf::Vector2f drag = Physics::calculateDrag(velocity, dragCoefficient, crossSectionalArea);
    velocity += (acceleration + gravity + drag) * deltaTime;
    position += velocity * deltaTime;
}

void FlyingObject::draw(sf::RenderWindow& window) const {
    sf::CircleShape shape(10.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
    window.draw(shape);
}

sf::Vector2f FlyingObject::getPosition() const {
    return position;
}

void FlyingObject::setDragCoefficient(float dragCoefficient) {
    this->dragCoefficient = dragCoefficient;
}

float FlyingObject::getDragCoefficient() const {
    return dragCoefficient;
}