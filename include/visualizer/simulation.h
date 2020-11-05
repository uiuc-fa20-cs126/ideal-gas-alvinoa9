#pragma once

#include "cinder/gl/gl.h"
#include <string>
#include <core/ideal_gas_simulator.h>

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
     * Creates a simulation
     *
     * @param top_left_corner    screen coordinates of top left corner of simulator
     * @param particle_radius
     * @param particle_color
     * @param particles
     */
    Simulation(const vec2& top_left_corner, double particle_radius,
               string particle_color, vector<Particle> particles);

    /**
     * Displays the current state of the simulation in the Cinder application.
     */
    void Draw() const;


private:
    glm::vec2 top_left_corner_;

    double particle_radius_;

    string particle_color_;

    vector<Particle> particles_;

};

}  // namespace visualizer

}  // namespace idealgas