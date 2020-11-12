#include "../../include/core/ideal_gas_simulator.h"

namespace idealgas {

Particle::Particle() {
    glm::vec2 posTemp(0.0, 0.0);
    position = posTemp;
    glm::vec2 velTemp(-1.0, -1.0);
    velocity = velTemp;
    radius = 1.0;
    color = string("blue");
    mass = 1.0;
}

Particle::Particle(double m, double r, string c) {
    glm::vec2 posTemp(0.0, 0.0);
    position = posTemp;
    glm::vec2 velTemp(-1.0, -1.0);
    velocity = velTemp;
    mass = m;
    radius = r;
    color = c;
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

double Particle::GetMass() {
    return mass;
}

string Particle::GetColor() {
    return color;
}

void Particle::SetPosition(glm::vec2 new_position) {
    position = new_position;
}

void Particle::SetVelocity(glm::vec2 new_velocity) {
    velocity = new_velocity;
}

double Particle::GetSpeed() {
    return glm::length(velocity);
}

IdealGasSimulator::IdealGasSimulator() {
    // Blue particle
    for (int i = 0; i < 30; i++) {
        string pColor("blue");
        Particle temp(1.0, 1.0, pColor);
        particles.push_back(temp);
    }
    // Orange Particle
    for (int i = 0; i < 40; i++) {
        string pColor("orange");
        Particle temp(5.0, 50.0, pColor);
        particles.push_back(temp);
    }
    // Green Particle
    for (int i = 0; i < 20; i++) {
        string pColor("green");
        Particle temp(10.0, 30.0, pColor);
        particles.push_back(temp);
    }
}

IdealGasSimulator::IdealGasSimulator(glm::vec2 window_size) {
    window_size_ = window_size;
    // Blue particle
    for (int i = 0; i < 30; i++) {
        string pColor("blue");
        Particle temp(1.0, 1.0, pColor);
        particles.push_back(temp);
    }
    // Orange Particle
    for (int i = 0; i < 40; i++) {
        string pColor("orange");
        Particle temp(1.0, 1.0, pColor);
        particles.push_back(temp);
    }
    // Green Particle
    for (int i = 0; i < 20; i++) {
        string pColor("green");
        Particle temp(1.0, 1.0, pColor);
        particles.push_back(temp);
    }
}

void IdealGasSimulator::Move() {
    // Iterate through all particles
    for (Particle p1 : particles) {
        // Check will all other particles
        for (Particle p2 : particles) {
            if (&p1 != &p2) {
                // If collide with another particle
                if (glm::dot(p1.GetVelocity() - p2.GetVelocity(), p1.GetPosition() - p2.GetPosition()) < 0) {
                    Collision(p1, p2);
                }
                // If collide with corner
                else if ((EvaluatePosition(p1).x + p1.GetRadius() <= 0 ||
                         EvaluatePosition(p1).x + p1.GetRadius() <= window_size_.x) &&
                         (EvaluatePosition(p1).y + p1.GetRadius() <= 0 ||
                         EvaluatePosition(p1).y + p1.GetRadius() <= window_size_.y)){
                    p1.SetPosition(EvaluatePosition(p1));
                    glm::vec2 new_velocity(-1.0 * p1.GetVelocity().x, -1.0 * p1.GetVelocity().y);
                    p1.SetVelocity(new_velocity);
                }
                // Collide with vertical wall
                else if (EvaluatePosition(p1).x + p1.GetRadius() <= 0 ||
                        EvaluatePosition(p1).x + p1.GetRadius() <= window_size_.x) {
                    p1.SetPosition(EvaluatePosition(p1));
                    glm::vec2 new_velocity(-1.0 * p1.GetVelocity().x, p1.GetVelocity().y);
                    p1.SetVelocity(new_velocity);
                }
                // Collide with horizontal wall
                else if (EvaluatePosition(p1).y + p1.GetRadius() <= 0 ||
                        EvaluatePosition(p1).y + p1.GetRadius() <= window_size_.y) {
                    p1.SetPosition(EvaluatePosition(p1));
                    glm::vec2 new_velocity(p1.GetVelocity().x, -1.0 * p1.GetVelocity().y);
                    p1.SetVelocity(new_velocity);
                }
                // Does not collide
                else {
                    EvaluatePosition(p1);
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
    glm::vec2 temp = ((glm::dot(p1.GetVelocity() - p2.GetVelocity(), p1.GetPosition() - p2.GetPosition())) /
                      glm::length(p1.GetPosition() - p2.GetPosition())) * (p1.GetPosition() - p2.GetPosition());
    temp.x = temp.x * ((float)(2 * p2.GetMass()) / (float)(p1.GetMass() + p2.GetMass()));
    temp.y = temp.y * ((float)(2 * p2.GetMass()) / (float)(p1.GetMass() + p2.GetMass()));
    glm::vec2 new_velocity = p1.GetVelocity() - temp;
    return new_velocity;
}

}   //namespace idealgas