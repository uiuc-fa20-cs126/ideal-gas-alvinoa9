#include "../../include/visualizer/ideal_gas_app.h"

namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
        : gas_simulator(glm::vec2(kMargin, kMargin)),
          simulation_(glm::vec2(kMargin, kMargin), kWindowSize, kWindowSize,
                      gas_simulator.GetParticles()) {
    ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
}

void IdealGasApp::draw() {
    ci::Color background_color("grey");
    ci::gl::clear(background_color);

    glm::vec2 temp(kMargin, kMargin);
    ci::gl::color(ci::Color::black());
    ci::gl::drawSolidRect(ci::Rectf(temp, temp + ci::vec2(kWindowSize, kWindowSize)));
    //simulation_.Draw();
    //gas_simulator.Move();
    DrawHistogram();
}

void IdealGasApp::DrawHistogram() {
    ci::gl::color(ci::Color::white());

    //Create bins
    glm::vec2 temp(kMargin + 850, kMargin);
    ci::gl::drawSolidRect(ci::Rectf(temp, temp + ci::vec2(250, 200)));
    ci::gl::drawStringCentered("Speed", temp + ci::vec2(125, 210), ci::Color("white"), kUiFont);


    glm::vec2 temp2(kMargin + 850, kMargin + 270);
    ci::gl::drawSolidRect(ci::Rectf(temp2, temp2 + ci::vec2(250, 200)));
    ci::gl::drawStringCentered("Speed", temp2 + ci::vec2(125, 210), ci::Color("white"), kUiFont);


    glm::vec2 temp3(kMargin + 850, kMargin + 540);
    ci::gl::drawSolidRect(ci::Rectf(temp3, temp3 + ci::vec2(250, 200)));
    ci::gl::drawStringCentered("Speed", temp3 + ci::vec2(125, 210), ci::Color("white"), kUiFont);

    //Seperate particles
    vector<Particle> particles = gas_simulator.GetParticles();
    vector<double> blue;
    vector<double> orange;
    vector<double> green;

    for (size_t i = 0; i < particles.size(); i++) {
        if (particles[i].GetColor().compare("blue") == 0) {
            blue.push_back(particles[i].GetSpeed());
        }
        else if (particles[i].GetColor().compare("orange") == 0) {
            orange.push_back(particles[i].GetSpeed());
        }
        else if (particles[i].GetColor().compare("green") == 0) {
            green.push_back(particles[i].GetSpeed());
        }
    }

    // Calculate rounded max and min or each particle type
    double max_blue = ceil(*max_element(blue.begin(), blue.end()));
    double min_blue = floor(*max_element(blue.begin(), blue.end()));
    double blue_interval = (max_blue - min_blue) / kHistogramInterval;

    double max_orange = ceil(*max_element(orange.begin(), orange.end()));
    double min_orange = floor(*min_element(orange.begin(), orange.end()));
    double orange_interval = (max_orange - min_orange) / kHistogramInterval;

    double max_green = ceil(*max_element(green.begin(), green.end()));
    double min_green = floor(*min_element(green.begin(), green.end()));
    double green_interval = (max_green - min_green) / kHistogramInterval;

    //Blue histogram
    glm::vec2 blue_temp(kMargin + 850, kMargin + 200);
    for (int i = 0; i < kHistogramInterval - 1; i++) {
        int count = 0;
        for (size_t j = 0; i < blue.size(); i++) {
            if (blue[j] >= min_blue + blue_interval * i && blue[j] < min_blue + blue_interval * (i+1)) {
                count++;
            }
        }
        blue_temp += ci::vec2(12.5, -1 * (count * 10));
        ci::Color("blue");
        ci::gl::drawSolidRect(ci::Rectf(temp, blue_temp));
        ci::gl::drawStringCentered(to_string(min_blue + i * blue_interval),
                                   blue_temp + ci::vec2(0, 10), ci::Color("white"), kUiFont);
    }

    glm::vec2 green_temp(kMargin + 850, kMargin + 470);
    for (int i = 0; i < kHistogramInterval - 1; i++) {
        int count = 0;
        for (size_t j = 0; i < green.size(); i++) {
            if (green[j] >= min_green + green_interval * i && green[j] < min_green + green_interval * (i+1)) {
                count++;
            }
        }
        green_temp += ci::vec2(12.5, -1 * (count * 10));
        ci::Color("green");
        ci::gl::drawSolidRect(ci::Rectf(temp, green_temp));
        ci::gl::drawStringCentered(to_string(min_green + i * green_interval),
                                   green_temp + ci::vec2(0, 10), ci::Color("white"), kUiFont);
    }

    glm::vec2 orange_temp(kMargin + 850, kMargin + 740);
    for (int i = 0; i < kHistogramInterval - 1; i++) {
        int count = 0;
        for (size_t j = 0; i < orange.size(); i++) {
            if (orange[j] >= min_orange + orange_interval * i && orange[j] < min_orange + orange_interval * (i+1)) {
                count++;
            }
        }
        orange_temp += ci::vec2(12.5, -1 * (count * 10));
        ci::Color("orange");
        ci::gl::drawSolidRect(ci::Rectf(temp, orange_temp));
        ci::gl::drawStringCentered(to_string(min_orange + i * orange_interval),
                                   orange_temp + ci::vec2(0, 10), ci::Color("white"), kUiFont);
    }
}

/*void IdealGasApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_UP:
            scale *= 0.5;
            break;

        case ci::app::KeyEvent::KEY_DOWN:
            break;
    }
}*/


}  // namespace visualizer

}  // namespace naivebayes