#include "cinder/gl/gl.h"
#include <vector>
using namespace std;

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
         * Setter for particle position
         * @param new_position updated position
         */
        void SetPosition(glm::vec2 new_position);

        /**
         * Setter for particle velocity
         * @param new_velocity updated velocity
         */
        void SetVelocity(glm::vec2 new_velocity);

    private:
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
         * Default constructor
         */
        IdealGasSimulator(double window_size);

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

    private:
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

        vector<Particle> particles;

        double window_size_;
};

}   //namespace idealgas