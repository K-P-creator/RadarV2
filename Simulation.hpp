#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include "Object.hpp"
#include "Radar.hpp"
#include "Car.hpp"

#include <vector>

#include <windows.h>

class Simulation {
private:
    int y; // Height of the simulation area
    int x;  // Width of the simulation area
    std::vector<Object*> objects; // List of objects in the simulation
                                  //use pointer to avoid object slicing
    std::vector<Radar> radars;    // List of radars in the simulation


public:
    // Constructor
    Simulation(int x, int y) : x(x), y(y) {}

    // Method to add an object
    void addObject(Object* obj) {
        objects.push_back(obj);
    }

    // Method to delete an object by index
    void deleteObject(size_t index) {
        if (index < objects.size()) {
            objects.erase(objects.begin() + index);
        }
    }

    // Method to add a radar
    void addRadar(const Radar& radar) {
        radars.push_back(radar);
    }

    // Method to delete a radar by index
    void deleteRadar(size_t index) {
        if (index < radars.size()) {
            radars.erase(radars.begin() + index);
        }
    }

    //Method to display simulation window
    void runSimulation() {
        // Create the window
        sf::RenderWindow window(sf::VideoMode(x, y), "Radar Simulation V2.0");

        // Main loop
        while (window.isOpen()) {
            // Process events
            sf::Event event;
            while (window.pollEvent(event)) {
                // Close window if close event is triggered
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Clear the window with black color
            window.clear(sf::Color::Black);

            //Initialize a rectangle to draw as objects
            // 
            // old draw mechanic
            //sf::RectangleShape point(sf::Vector2f(5, 5));
            //point.setFillColor(sf::Color::Red);
            
            

            for (auto obj : objects) {
                if (this->checkObject(obj)) {
                    obj->draw(window);
                }
            }

            // Draw radars
            for (const auto& radar : radars) {
                sf::CircleShape radarShape(radar.getRadius()); 
                radarShape.setPosition(radar.getX() - radar.getRadius(), radar.getY() - radar.getRadius());
                radarShape.setFillColor(sf::Color(0, 255, 0, 20)); // Semi-transparent green
                radarShape.setOutlineThickness(1);
                radarShape.setOutlineColor(sf::Color::Green);
                window.draw(radarShape);
            }

            // Display the window's contents
            window.display();
            this->updateObjects();

        }
    }

    //Method to check an object agains all radars
    bool checkObject(const Object* obj) {
        for (const Radar& radar : radars) {
            if (radar.checkObjectRadar(obj)) {
                return true; // Object detected
            }
        }
        return false; // Object not detected by any radar
        
    }

    //Method to update all object positions
    void updateObjects() {
        for (auto& obj : objects) {
            obj->updatePosition();
        }
    }
};
