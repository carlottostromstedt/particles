#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "ParticleFactory.h"
#include "ParticleSystem.h"
#include "ParticleRenderer.h"
#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Please provide the particle type as a command line argument.\n";
        return 1;
    } else if (argc > 3) {
        std::cout << "We dont have that many arguments.\n";
        return 1;
    }

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Particle System");

    // Create particle factory and renderer
    ParticleFactory particleFactory;
    ParticleRenderer particleRenderer(window);

    // Create particle system
    ParticleSystem particleSystem;
    particleSystem.start();

    std::string particleType = argv[1];
    int particleAmount = stoi(argv[2]);

    // Generate and add particles to the particle system
    for (int i = 0; i < particleAmount; ++i) {
        if (particleType == "rain") {
            Particle particle = particleFactory.createRain();
            particleSystem.addParticle(particle);

        } else if (particleType == "bouncy") {
            Particle particle = particleFactory.createParticle();
            particleSystem.addParticle(particle);

        } else if (particleType == "snow"){
            Particle particle = particleFactory.createSnow(0.0f, 0.0f, 0.0f, 0.0f, 0);
            particleSystem.addParticle(particle);
        }
        else {
            std::cout << "Invalid particle type. Please specify 'rain', 'snow' or 'bouncy'.\n";
            return 1;
        }
    }

    // Game loop
    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update particle system
        float deltaTime = 4.0f; // Adjust the delta time as needed
        
        particleSystem.update(deltaTime, particleType);

        // Clear the window
        window.clear();

        // Render particles
        particleRenderer.render(particleSystem.getParticles(), particleType);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
