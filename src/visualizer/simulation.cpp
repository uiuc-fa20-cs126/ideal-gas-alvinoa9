#include "../../include/visualizer/simulation.h"

namespace idealgas {

namespace visualizer {

using glm::vec2;

Simulation::Simulation(const glm::vec2& top_left_corner,
                       size_t pixels_x,
                        size_t pixels_y,
                       vector<Particle> particles)
    : top_left_corner_(top_left_corner),
      pixels_x_(pixels_x),
      pixels_y_(pixels_y),
      particles_(particles) {}

void Simulation::Draw() const {
    ci::gl::color(ci::Color::black());
    ci::gl::drawSolidRect(ci::Rectf(top_left_corner_, top_left_corner_ + ci::vec2(pixels_x_, pixels_y_)));

    for (Particle p : particles_) {
        ci::gl::color(ci::Color::white());
        ci::gl::drawSolidCircle(p.GetPosition(), (float)p.GetRadius());
    }
}

}  // namespace visualizer

}  // namespace idealgas