#include "../../include/visualizer/simulation.h"

namespace idealgas {

namespace visualizer {

using glm::vec2;

Simulation::Simulation(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double particle_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side),
      particle_radius_(particle_radius) {}

void Simulation::Draw() const {
    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            // Currently, this will draw a quarter circle centered at the top-left
            // corner with a radius of 20
            glm::vec2 temp(row, col);

            //


            vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                          row * pixel_side_length_);

            vec2 pixel_bottom_right =
                    pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
            ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

            ci::gl::drawSolidRect(pixel_bounding_box);

            ci::gl::color(ci::Color("black"));
            ci::gl::drawStrokedRect(pixel_bounding_box);
        }
    }
}

void Sketchpad::HandleBrush(const vec2& brush_screen_coords) {
    vec2 brush_sketchpad_coords =
            (brush_screen_coords - top_left_corner_) / (float)pixel_side_length_;

    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            vec2 pixel_center = {col + 0.5, row + 0.5};

            if (glm::distance(brush_sketchpad_coords, pixel_center) <=
                brush_radius_) {
                glm::vec2 temp(row, col);
                shaded_.push_back(temp);
            }
        }
    }
}

void Sketchpad::Clear() {
    shaded_.clear();
}

std::string Sketchpad::ImportSketchpad() {
    std::string sketchpad = "";

    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            glm::vec2 temp(row, col);

            if (std::find(shaded_.begin(), shaded_.end(), temp) != shaded_.end()) {
                sketchpad.append(reinterpret_cast<const char* const>('#'));
            }
            else {
                sketchpad.append(reinterpret_cast<const char* const>(' '));
            }
        }
        sketchpad.append(reinterpret_cast<const char* const>('\n'));
    }

    return sketchpad;
}

}  // namespace visualizer

}  // namespace idealgas