#include "Particle.h"
#include "ParticleSystem.h"
#include "ParticleFactory.h"
#include <iostream> 
using namespace std;

Particle::Particle(float posX, float posY, float velX, float velY)
    : positionX(posX), positionY(posY), velocityX(velX), velocityY(velY), staticness(false) {}

float Particle::update(float deltaTime, float windowWidth, float windowHeight, std::string type) {
    positionX += velocityX * deltaTime;
    positionY += velocityY * deltaTime;
    // std::cout << type;

    if(type == "bouncy"){
    std::cout << "bounce off wall";
    // Check if the particle has hit the window boundaries
    if (positionX < 0 || positionX > windowWidth) {
        // Reverse the horizontal velocity to bounce back
        velocityX = -velocityX;
    }
    if (positionY < 0 || positionY > windowHeight) {
        // Reverse the vertical velocity to bounce back
        velocityY = -velocityY;
    }
    } else if (type == "snow"){
        if (positionY > windowHeight) {
            // positionY = -1.0f;
            positionY = -10.0f;
            return positionX;
        }
    } else {
        if (positionY > windowHeight) {
            positionY = -10.0f;
        }
    }
}

void Particle::render() const {
    std::cout << "Particle at (" << positionX << ", " << positionY << ")\n";
}
