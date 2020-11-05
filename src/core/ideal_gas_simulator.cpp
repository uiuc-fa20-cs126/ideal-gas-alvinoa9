#include "../../include/core/ideal_gas_simulator.h"

namespace idealgas {

Particle::Particle() {
    position(0.0, 0.0);
    velocity(-1.0, -1.0);
}

glm::vec2 Particle::getPosition() {
    return position;
}

glm::vec2 Particle::getVelocity() {
    return velocity;
}

double Particle::getRadius() {
    return radius;
}

void Particle::setPosition(glm::vec2 new_position) {
    position = new_position;
}

void Particle::setVelocity(glm::vec2 new_velocity) {
    velocity = new_velocity;
}

void IdealGasSimulator::Collision(Particle p1, Particle p2) {
    // Update velocity of particles
    p1.setVelocity(EvaluateVelocity(p1, p2));
    p2.setVelocity(EvaluateVelocity(p2, p1));

    // Update position of particles
    p1.setPosition(EvaluatePosition(p1));
    p2.setPosition(EvaluatePosition(p2));
}

glm::vec2 IdealGasSimulator::EvaluatePosition(Particle p1) {
    return p1.getPosition() + p1.getVelocity();
}

glm::vec2 IdealGasSimulator::EvaluateVelocity(Particle p1, Particle p2) {
    glm::vec2 new_velocity = p1.getVelocity() - ((glm::dot(p1.getVelocity() - p2.getVelocity(),
                                                          p1.getPosition() - p2.getPosition())) / glm::length(p1.getPosition() - p2.getPosition()))
                                               * (p1.getPosition() - p2.getPosition());
    return new_velocity;
}

}   //namespace idealgas