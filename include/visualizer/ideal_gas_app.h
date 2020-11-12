#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "simulation.h"
#include <core/ideal_gas_simulator.h>
#include <algorithm>
#include <math.h>

namespace idealgas {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class IdealGasApp : public ci::app::App {
public:
    IdealGasApp();

    void draw() override;

    void DrawHistogram();
    //void keyDown(ci::app::KeyEvent event) override;

    const size_t kWindowSize = 700;
    const size_t kWindowWidth = 1200;
    const size_t kWindowHeight = 850;
    const size_t kMargin = 50;
    const ci::Font kUiFont = ci::Font("Arial", 22);
    const int kHistogramInterval = 20;
private:
    Simulation simulation_;
    IdealGasSimulator gas_simulator = IdealGasSimulator(glm::vec2(kMargin, kMargin));// = IdealGasSimulator(glm::vec2(kMargin, kMargin));
    //vector<Particle> particles = gas_simulator.GetParticles();
};

}  // namespace visualizer

}  // namespace idealgas
