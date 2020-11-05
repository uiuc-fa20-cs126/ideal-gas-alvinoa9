#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "simulation.h"
#include <core/ideal_gas_simulator.h>

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
    //void update() override;

    //void mouseDown(ci::app::MouseEvent event) override;
    //void mouseDrag(ci::app::MouseEvent event) override;
    //void keyDown(ci::app::KeyEvent event) override;

    const double kWindowSize = 875;
    const double kMargin = 100;
    const size_t kImageDimension = 28;

private:
    Simulation simulation_;
    //const std::string kFile = "";
    IdealGasSimulator gas_simulator(kWindowSize);

};

}  // namespace visualizer

}  // namespace idealgas
