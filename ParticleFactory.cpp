#include "ParticleFactory.h"
#include <random>

Particle ParticleFactory::createParticle() {
    float posX = generateRandomFloat(-200.0f, 1920.0f);
    float posY = generateRandomFloat(-200.0f, 1080.0f);
    float velX = generateRandomFloat(0.1f, 0.6f);
    float velY = generateRandomFloat(0.1f, 0.6f);

    return Particle(posX, posY, velX, velY);
}

Particle ParticleFactory::createRain(){
    float posX = generateRandomFloat(0.0f, 1920.0f);
    float posY = generateRandomFloat(0.0f, 1080.0f);
    float velX = generateRandomFloat(0.0f, 0.0f);
    float velY = generateRandomFloat(3.0f, 3.4f);

    // would be better if we could include type here as well inside of the Particle constructor

    return Particle(posX, posY, velX, velY);
}

Particle ParticleFactory::createSnow(float positionX, float positionY, float velocityX, float velocityY, int stay){
    

    float posX = generateRandomFloat(0.0f, 1920.0f);
    float posY = generateRandomFloat(0.0f, 1080.0f);
    float velX = generateRandomFloat(0.0f, 0.0f);
    float velY = generateRandomFloat(0.2f, 0.3f);
    return Particle(posX, posY, velX, velY);

    // would be better if we could include type here as well inside of the Particle constructor

    
}

float ParticleFactory::generateRandomFloat(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}