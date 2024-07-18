#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include <SFML/Graphics.hpp>

class FlyingObject {
public:
    FlyingObject(float mass, float speed, sf::Vector2f position, float dragCoefficient, float crossSectionalArea);
    void update(float windSpeed, float windAngle, float deltaTime);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
    void setDragCoefficient(float dragCoefficient);
    float getDragCoefficient() const;

private:
    float mass;
    sf::Vector2f velocity;
    sf::Vector2f position;
    float dragCoefficient;
    float crossSectionalArea;
};
#endif 