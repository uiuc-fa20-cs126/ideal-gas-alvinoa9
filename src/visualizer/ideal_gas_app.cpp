#include "../../include/visualizer/ideal_gas_app.h"

namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
        : simulation_(glm::vec2(kMargin, kMargin), kImageDimension,
                     kWindowSize - 2 * kMargin) {
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

    //std::ifstream read_file;
    //read_file.open(kFile);
    gas_simulator.LoadSimulation();
    //read_file.close();
}

void NaiveBayesApp::draw() {
    ci::Color8u background_color(255, 246, 148);  // light yellow
    ci::gl::clear(background_color);

    sketchpad_.Draw();

    ci::gl::drawStringCentered(
            "Press Delete to clear the sketchpad. Press Enter to make a prediction.",
            glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));

    ci::gl::drawStringCentered(
            "Prediction: " + std::to_string(current_prediction_),
            glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("blue"));
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
    sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
    sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_RETURN:
            GetPrediction();
            break;

        case ci::app::KeyEvent::KEY_DELETE:
            sketchpad_.Clear();
            break;
    }
}

void NaiveBayesApp::GetPrediction() {
    std::string image = sketchpad_.ImportSketchpad();
    std::stringstream  temp(image);
    NaiveBayesModel model;

    temp >> model;

    current_prediction_ = naive_classifier.Prediction(model);
}

}  // namespace visualizer

}  // namespace naivebayes