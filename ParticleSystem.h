#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "Particle.h"
#include <vector>
#include <iostream> 
using namespace std;


class ParticleSystem {
private:
    std::vector<Particle> particles;
    bool isRunning;
    float windowWidth;
    float windowHeight;

public:
    ParticleSystem();

    void start();
    void stop();
    void update(float deltaTime, std::string type);
    void render();
    void addParticle(const Particle& particle);
    void removeParticle(const Particle& particle);
    const std::vector<Particle>& getParticles() const; // Added method declaration
    
};

#endif
