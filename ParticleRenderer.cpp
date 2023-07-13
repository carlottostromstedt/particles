#include "ParticleRenderer.h"
#include <iostream> 
using namespace std;

ParticleRenderer::ParticleRenderer(sf::RenderWindow& targetWindow) : window(targetWindow) {}

void ParticleRenderer::render(const std::vector<Particle>& particles, std::string particleType, int startIndex, int endIndex) {
    int x = 0;
    for (int i = startIndex; i < endIndex; ++i) {
    const auto& particle = particles[i];
        if (particleType == "bouncy"){
            sf::CircleShape shape(4.0f);
            shape.setPosition(particle.getPositionX(), particle.getPositionY());
            if (x % 2 == 0){
                shape.setFillColor(sf::Color::Green);
            } else {
                shape.setFillColor(sf::Color::Red);
            }
        window.draw(shape);
        x = x + 1;
        } else if (particleType == "rain"){
            sf::RectangleShape shape(sf::Vector2f(10, 2));
            shape.rotate(90);
            shape.setPosition(particle.getPositionX(), particle.getPositionY());
            if (x % 2 == 0){
                shape.setFillColor(sf::Color{ 3, 207, 255, 255 });
            } else {
                shape.setFillColor(sf::Color{ 3, 207, 255, 255 });
            }
            window.draw(shape);
            x = x + 1;
        } else if (particleType == "snow"){
            sf::CircleShape shape(4.0f);
            shape.setPosition(particle.getPositionX(), particle.getPositionY());
            if (x % 2 == 0){
                shape.setFillColor(sf::Color{ 255, 255, 255, 255 });
            } else {
                shape.setFillColor(sf::Color{ 255, 255, 255, 255 });
            }
            window.draw(shape);
            x = x + 1;
        }
    }
}
