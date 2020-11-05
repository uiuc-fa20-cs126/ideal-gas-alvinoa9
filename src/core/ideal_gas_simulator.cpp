#include "../../include/core/ideal_gas_simulator.h"

namespace idealgas {

Particle::Particle() {
    position(0.0, 0.0);
    velocity(-1.0, -1.0);
}

glm::vec2 Particle::GetPosition() {
    return position;
}

glm::vec2 Particle::GetVelocity() {
    return velocity;
}

double Particle::GetRadius() {
    return radius;
}

void Particle::SetPosition(glm::vec2 new_position) {
    position = new_position;
}

void Particle::SetVelocity(glm::vec2 new_velocity) {
    velocity = new_velocity;
}

IdealGasSimulator::IdealGasSimulator(double window_size) {
    window_size_ = window_size;
    for (int i = 0; i < 30; i++) {
        particles.push_back(new Particle());
    }
}

void IdealGasSimulator::Move() {
    // Iterate through all particles
    for (p1 : particles) {
        // Check will all other particles
        for (p2 : particles) {
            if (&p1 != &p2) {
                // If collide
                if (glm::dot(p1.GetVelocity() - p2.GetVelocity(), p1.GetPosition(), p2.GetPosition()) < 0) {
                    Collision(p1, p2);
                }
                else if (p1.EvaluatePosition.x <= 0 || p1.EvaluatePosition.x <= window_size_ ||
                         p1.EvaluatePosition.y <= 0 || p1.EvaluatePosition.y <= window_size_) {

                }
                else {
                    p1.EvaluatePosition();
                }
            }
        }
    }
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