#include <core/ideal_gas_simulator.h>
#include <catch2/catch.hpp>
#include "cinder/gl/gl.h"

using namespace idealgas;

TEST_CASE("Test particle collision") {
    IdealGasSimulator test(100.0);

    Particle p1;
    Particle p2;

    SECTION("Particle collision") {
        glm::vec2 p1_position(20, 20);
        p1.SetPosition(p1_position);
        glm::vec2 p1_velocity(0.1, 0);
        p1.SetPosition(p1_velocity);

        // Second Frame
        glm::vec2 p2_position(21.4, 21.4);
        p2.SetPosition(p2_position);
        glm::vec2 p2_velocity(-0.1, 0);
        p2.SetPosition(p2_velocity);

        test.Collision(p1, p2);

        // Third frame
        glm::vec2 p1_new_position(20, 19.9);
        glm::vec2 p1_new_velocity(0, -0.1);
        glm::vec2 p2_new_position(21.4, 21.5);
        glm::vec2 p2_new_velocity(0, 0.1);

        REQUIRE(p1.position == p1_new_position);
        REQUIRE(p2.position == p2_new_position);
        REQUIRE(p1.velocity == p1_new_velocity);
        REQUIRE(p2.velocity == p2_new_velocity);
    }

    SECTION("Collision with vertical wall")  {
        glm::vec2 p1_position(5, 10);
        glm::vec2 p1_velocity(-5, 0);
        p1.SetPosition(p1_position);
        p1.SetVelocity(p1_velocity);

        // First frame
        glm::vec2 p1_new_position(0, 10);
        glm::vec2 p1_new_velocity(-5, 0);

        // Second Frame
        glm::vec2 p1_second_position(5, 10);
        glm::vec2 p1_second_velocity(5, 0);
    }

    SECTION("Collision with horizontal wall")  {
        glm::vec2 p1_new_position(10, 5);
        glm::vec2 p1_new_velocity(0, -5);
        p1.SetPosition(p1_new_position);
        p1.SetVelocity(p1_new_velocity);

        // First frame
        glm::vec2 p1_new_position(10, 0);
        glm::vec2 p1_new_velocity(0, -5);

        // Second Frame
        glm::vec2 p1_second_position(10, 5);
        glm::vec2 p1_second_velocity(0, 5);
    }

    SECTION("Collision with corner wall")  {
        glm::vec2 p1_new_position(5, 5);
        glm::vec2 p1_new_velocity(-5, -5);
        p1.SetPosition(p1_new_position);
        p1.SetVelocity(p1_new_velocity);
    }
}