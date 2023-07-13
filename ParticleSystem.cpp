#include "ParticleSystem.h"
#include <iostream> 
using namespace std;
#include <cmath>
#include <unordered_map>

ParticleSystem::ParticleSystem() : isRunning(false) {}

std::unordered_map<float, int> positionXCounts;
std::vector<Particle> particles;



void ParticleSystem::start() {
    isRunning = true;
}

void ParticleSystem::stop() {
    isRunning = false;
}

void ParticleSystem::update(float deltaTime, std::string type) {
    if (!isRunning) return;

    windowWidth = 1920;
    windowHeight = 1080;
    float positionX;

    std::vector<Particle> newParticles;  // Temporary vector to hold new particles

    // Update dynamic particles
    for (auto& particle : particles) {
        if (particle.isStatic()) {
            continue;  // Skip updating static particles
        }
        positionX = particle.update(deltaTime, windowWidth, windowHeight, type);
        if (positionX > 1.0f && positionX < 1920.0f) {
            if (positionXCounts.find(positionX) != positionXCounts.end()) {
                float newPositionY = 4.0f * positionXCounts[positionX];
                Particle particleNew = Particle(positionX, (1070.0f - newPositionY), 0.0f, 0.0f);
                particleNew.setStatic();
                newParticles.push_back(particleNew);
                positionXCounts[positionX] += 1;
            } else {
                Particle particleNew = Particle(positionX, 1070.0f, 0.0f, 0.0f);
                particleNew.setStatic();
                newParticles.push_back(particleNew);
                positionXCounts[positionX] += 1;
            }
        }
    }
    particles.insert(particles.end(), newParticles.begin(), newParticles.end());
}


void ParticleSystem::render() {
    for (const auto& particle : particles) {
        particle.render();
    }
}

void ParticleSystem::addParticle(const Particle& particle) {
    particles.push_back(particle);
}

const std::vector<Particle>& ParticleSystem::getParticles() const {
    return particles;
}

void ParticleSystem::removeParticle(const Particle& particle) {
    std::cout << "pop";
    particles.pop_back();
}