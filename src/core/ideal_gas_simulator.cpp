#include "../../include/core/ideal_gas_simulator.h"

namespace idealgas {

Particle::Particle() {
    radius = 1.0;
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
                // If collide with another particle
                if (glm::dot(p1.GetVelocity() - p2.GetVelocity(), p1.GetPosition(), p2.GetPosition()) < 0) {
                    Collision(p1, p2);
                }
                // If collide with corner
                else if ((p1.EvaluatePosition.x + p1.GetRadius() <= 0 ||
                         p1.EvaluatePosition.x p1.GetRadius() <= window_size_) &&
                         (p1.EvaluatePosition.y + p1.GetRadius() <= 0 ||
                         p1.EvaluatePosition.y + p1.GetRadius() <= window_size_)){
                    p1.SetPosition(p1.EvaluatePosition);
                    glm::vec2 new_velocity(-1.0 * p1.GetVelocity().x, -1.0 * p1.GetVelocity().y);
                    p1.SetVelocity(new_velocity);
                }
                // Collide with vertical wall
                else if (p1.EvaluatePosition.x + p1.GetRadius() <= 0 ||
                         p1.EvaluatePosition.x p1.GetRadius() <= window_size_) {
                    p1.SetPosition(p1.EvaluatePosition);
                    glm::vec2 new_velocity(-1.0 * p1.GetVelocity().x, p1.GetVelocity().y);
                    p1.SetVelocity(new_velocity);
                }
                // Collide with horizontal wall
                else if (p1.EvaluatePosition.y + p1.GetRadius() <= 0 ||
                         p1.EvaluatePosition.y + p1.GetRadius() <= window_size_) {
                    p1.SetPosition(p1.EvaluatePosition);
                    glm::vec2 new_velocity(p1.GetVelocity().x, -1.0 * p1.GetVelocity().y);
                    p1.SetVelocity(new_velocity);
                }
                // Does not collide
                else {
                    p1.EvaluatePosition();
                }
            }
        }
    }
}

void IdealGasSimulator::Collision(Particle p1, Particle p2) {
    // Update velocity of particles
    p1.SetVelocity(EvaluateVelocity(p1, p2));
    p2.SetVelocity(EvaluateVelocity(p2, p1));

    // Update position of particles
    p1.SetPosition(EvaluatePosition(p1));
    p2.SetPosition(EvaluatePosition(p2));
}

vector<Particle> IdealGasSimulator::GetParticles() {
    return particles;
}

glm::vec2 IdealGasSimulator::EvaluatePosition(Particle p1) {
    return p1.GetPosition() + p1.GetVelocity();
}

glm::vec2 IdealGasSimulator::EvaluateVelocity(Particle p1, Particle p2) {
    glm::vec2 new_velocity = p1.GetVelocity() - ((glm::dot(p1.GetVelocity() - p2.GetVelocity(),
                             p1.GetPosition() - p2.GetPosition())) / glm::length(p1.GetPosition() - p2.GetPosition()))
                             * (p1.GetPosition() - p2.GetPosition());
    return new_velocity;
}

}   //namespace idealgas