#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include "FlyingObject.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flying Object Simulation");
    std::vector<FlyingObject> objects;
    objects.emplace_back(10.0f, 250.0f, sf::Vector2f(400.0f, 300.0f), 0.0f, 0.0f);  // Пример для самолета
    objects.emplace_back(5.0f, 150.0f, sf::Vector2f(200.0f, 100.0f), 0.0f, 0.0f);   // Пример для вертолета

    float windSpeed = 20.0f;
    float windAngle = 0.0f;

    sf::Font font;

    sf::Text windInfo;
    windInfo.setFont(font);
    windInfo.setCharacterSize(16);
    windInfo.setFillColor(sf::Color::Black);
    windInfo.setPosition(10.0f, 10.0f);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    windSpeed += 5.0f;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    windSpeed -= 5.0f;
                }
                if (event.key.code == sf::Keyboard::Left) {
                    windAngle -= 0.1f;
                }
                if (event.key.code == sf::Keyboard::Right) {
                    windAngle += 0.1f;
                }
                if (event.key.code == sf::Keyboard::A) {
                    objects[0].setDragCoefficient(objects[0].getDragCoefficient() - 0.1f); // Уменьшить коэффициент сопротивления первого объекта
                }
                if (event.key.code == sf::Keyboard::D) {
                    objects[0].setDragCoefficient(objects[0].getDragCoefficient() + 0.1f); // Увеличить коэффициент сопротивления первого объекта
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();
        for (auto& object : objects) {
            object.update(windSpeed, windAngle, deltaTime);
        }

        window.clear(sf::Color::White);
        for (const auto& object : objects) {
            object.draw(window);
        }

        std::ostringstream oss;
        oss << "Wind Speed: " << windSpeed << " m/s\nWind Angle: " << windAngle * 180 / 3.14159 << " degrees";
        windInfo.setString(oss.str());
        window.draw(windInfo);

        window.display();
    }

    return 0;
}