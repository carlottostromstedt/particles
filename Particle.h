#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream> 
using namespace std;

class Particle {
private:
    float positionX;
    float positionY;
    float velocityX;
    float velocityY;
    bool staticness;

public:
    Particle(float posX, float posY, float velX, float velY);

    float update(float deltaTime, float windowWidth, float windowHeight, std::string types);
    void render() const;

    // Add getters for position if needed
    float getPositionX() const { return positionX; }
    bool isStatic() const { return staticness; }
    void setStatic() { staticness = true; }
    float getPositionY() const { return positionY; }
};

#endif
