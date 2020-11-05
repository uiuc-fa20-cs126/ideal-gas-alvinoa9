#include "../../include/visualizer/ideal_gas_app.h"

namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
        : simulation_(glm::vec2(kMargin, kMargin), kImageDimension,
                     kWindowSize - 2 * kMargin) {
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

    //std::ifstream read_file;
    //read_file.open(kFile);
    //gas_simulator.LoadSimulation();
    //read_file.close();
}

void IdealGasApp::draw() {
    ci::gl::color background_color("black");
    ci::gl::clear(background_color);

    simulation_.Draw();
}


/*void IdealGasApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_RETURN:
            GetPrediction();
            break;

        case ci::app::KeyEvent::KEY_DELETE:
            sketchpad_.Clear();
            break;
    }
}*/


}  // namespace visualizer

}  // namespace naivebayes