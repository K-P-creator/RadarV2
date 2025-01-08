#pragma once

#include "Object.hpp"
#include "Radar.hpp"
#include "Simulation.hpp"
#include "Car.hpp"
#include "Plane.hpp"

int main() {
    const int simX = 3000;
    const int simY = 1500;

    //initialize simulation
    Simulation simulation(simX, simY);

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random generator

    //initialize radars

    for (int i = 0; i < 10; i++) {
        float x = std::rand() % simX;
        float y = std::rand() % simY;
        float rad = std::rand() % 500;

        simulation.addRadar(Radar(x, y, rad));
    }

    //initialize objects


    for (int i = 0; i < 50; ++i) {
        float x = std::rand() % simX;
        float y = std::rand() % simY;
        
        float vx = std::rand() % 20 * (std::rand() % 2 == 0 ? 1 : -1); // Random negative or positive
        float vy = std::rand() % 20 * (std::rand() % 2 == 0 ? 1 : -1); // Random negative or positive

        simulation.addObject(new Car(x, y, vx, vy));
    }

    for (int i = 0; i < 50; ++i) {
        float x = std::rand() % simX;
        float y = std::rand() % simY;

        float vx = std::rand() % 20 * (std::rand() % 2 == 0 ? 1 : -1); // Random negative or positive
        float vy = std::rand() % 20 * (std::rand() % 2 == 0 ? 1 : -1); // Random negative or positive

        simulation.addObject(new Plane(x, y, vx, vy));
    }

    simulation.runSimulation();

    return 0;
}