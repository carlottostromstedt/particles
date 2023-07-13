#ifndef PARTICLERENDERER_H
#define PARTICLERENDERER_H

#include <SFML/Graphics.hpp>
#include "Particle.h"

class ParticleRenderer {
private:
    sf::RenderWindow& window;

public:
    ParticleRenderer(sf::RenderWindow& targetWindow);
    void render(const std::vector<Particle>& particles, std::string particleType, int startIndex, int endIndex);
};

#endif
