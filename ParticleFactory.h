#ifndef PARTICLE_FACTORY_H
#define PARTICLE_FACTORY_H

#include "Particle.h"

class ParticleFactory {
public:
    Particle createParticle();
    Particle createRain();
    Particle createSnow(float positionX, float positionY, float velocityX, float velocityY, int stay);
    
private:
    float generateRandomFloat(float min, float max);
};

#endif
