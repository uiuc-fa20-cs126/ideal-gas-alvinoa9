#include "cinder/gl/gl.h"

using namespace std;

namespace idealgas {

class Particle {
    public:
        Particle();

        glm::vec2 getPosition();
        glm::vec2 getVelocity();
        double getRadius();
        void setPosition(glm::vec2 new_position);
        void setVelocity(glm::vec2 new_velocity);

    private:
        glm::vec2 position;
        glm::vec2 velocity;
        double radius;
};
class IdealGasSimulator {
    public:
        void Collision(Particle p1, Particle p2);

    private:
        glm::vec2 EvaluateVelocity(Particle p1, Particle p2);
        glm::vec2 EvaluatePosition(Particle p1);
};

}   //namespace idealgas