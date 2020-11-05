#include "../../include/visualizer/simulation.h"

namespace idealgas {

namespace visualizer {

using glm::vec2;

Simulation::Simulation(const vec2& top_left_corner, double particle_radius,
                       string particle_color, vector<Particle> particles)
    : top_left_corner_(top_left_corner),
      particle_radius_(particle_radius),
      particle_color_(particle_color),
      particles_(particles) {}

void Simulation::Draw() const {
    for (p : particles_) {
        ci::gl::color(particle_color_);
        ci::gl::drawSolidCircle(p.GetPosition(), particle_radius_)
    }
}

}  // namespace visualizer

}  // namespace idealgas