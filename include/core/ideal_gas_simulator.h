#include "cinder/gl/gl.h"
#include <vector>
using namespace std;
#pragma once
namespace idealgas {

/**
 * Class that contains a particle's information
 */
class Particle {
    public:
        /**
         * Default constructor
         */
        Particle();

        /**
         * Class constructor
         * @param m mass of particle
         * @param r radius of particle
         * @param c color of particle
         */
        Particle(double m, double r, string c);

        /**
         * Getter for particle's position
         * @return particle position
         */
        glm::vec2 GetPosition();

        /**
         * Getter for particle's velocity
         * @return particle velocity
         */
        glm::vec2 GetVelocity();

        /**
         * Getter for particle's radius
         * @return particle radius
         */
        double GetRadius();

        /**
         * Getter for particle's mass
         * @return mass of particle
         */
        double GetMass();

        /**
         * Getter for particle's color
         * @return color of particle
         */
        string GetColor();

        /**
         * Setter for particle position
         * @param new_position updated position
         */
        void SetPosition(glm::vec2 new_position);

        /**
         * Setter for particle velocity
         * @param new_velocity updated velocity
         */
        void SetVelocity(glm::vec2 new_velocity);

        /**
         * Getter for particle's speed
         * @return speed of particle
         */
        double GetSpeed();

    private:
        double mass;
        string color;
        glm::vec2 position;
        glm::vec2 velocity;
        double radius;
};

/**
 * This class controls the movements of particles
 */
class IdealGasSimulator {
    public:
        /**
         * Default Constructor
         */
        IdealGasSimulator();

        /**
         * Class constructor
         * @param window_size size of window
         */
        IdealGasSimulator(glm::vec2 window_size);

        /**
         * Determine a particle's behaviour
         */
        void Move();

        /**
         * Update velocity and position of particle during collision
         * @param p1 first particle
         * @param p2 second particle
         */
        void Collision(Particle p1, Particle p2);

        /**
         * Getter for vector of particles
         * @return
         */
        vector<Particle> GetParticles();

        /**
         * Calculate velocity of particles during collision
         * @param p1 second particle
         * @param p2 first particle
         * @return new velocity
         */
        glm::vec2 EvaluateVelocity(Particle p1, Particle p2);

        /**
         * Calculate new position of particle
         * @param p1 particle
         * @return new position
         */
        glm::vec2 EvaluatePosition(Particle p1);

    private:
        vector<Particle> particles;

        glm::vec2 window_size_;
};

}   //namespace idealgas