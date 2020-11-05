#pragma once

#include "cinder/gl/gl.h"

namespace idealgas {

namespace visualizer {

/**
* A sketchpad which will be displayed in the Cinder application and respond to
* mouse events. Furthermore, the sketchpad can output its current state in the
* same format as the Naive Bayes image data files.
*/
class Simulation {
public:
    /**
     * Creates a simulation.
     * (Note that simulation pixels are larger than screen pixels.)
     *
     * @param top_left_corner     the screen coordinates of the top left corner of
     *                            the simulation
     * @param num_pixels_per_side the number of simulation pixels in one row/column
     *                            of the sketchpad
     * @param simulation_size     the side length of the simulation, measured in
     *                            screen pixels
     */
    Simulation(const glm::vec2& top_left_corner, size_t num_pixels_per_side,
              double simulation_size, double particle_radius = 1.0);

    /**
     * Displays the current state of the simulation in the Cinder application.
     */
    void Draw() const;

    /**
     * Shades in the simulation pixels whose centers are within brush_radius units
     * of the brush's location. (One unit is equal to the length of one sketchpad
     * pixel.)
     *
     * @param brush_screen_coords the screen coordinates at which the brush is
     *           located
     */
    //void HandleBrush(const glm::vec2& brush_screen_coords);

    /**
     * Clear
     */
    //void Clear();


private:
    glm::vec2 top_left_corner_;

    size_t num_pixels_per_side_;

    /** Number of screen pixels in the width/height of one sketchpad pixel */
    double pixel_side_length_;

    double particle_radius_;

    //std::vector<glm::vec2> shaded_;
};

}  // namespace visualizer

}  // namespace idealgas