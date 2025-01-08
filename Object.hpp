#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

class Object {
protected:
    float location_x; // x-coordinate of the location
    float location_y; // y-coordinate of the location
    float direction_x; // x-component of the direction
    float direction_y; // y-component of the direction

public:
    // Default Constructor
    Object() : location_x(0.0), location_y(0.0), direction_x(0.0), direction_y(0.0) {}

    // Constructor with initial values for location and direction
    Object(float loc_x, float loc_y, float dir_x, float dir_y)
        : location_x(loc_x), location_y(loc_y), direction_x(dir_x), direction_y(dir_y) {}

    // Method to set location
    void setLocation(float x, float y) {
        location_x = x;
        location_y = y;
    }

    // Method to set direction
    void setDirection(float dx, float dy) {
        direction_x = dx;
        direction_y = dy;
    }

    // Getter for location vectors
    const float& getLocationX() const { return location_x; }
    const float& getLocationY() const { return location_y; }

    // Getter for direction vectors
    const float& getDirectionX() const { return direction_x; }
    const float& getDirectionY() const { return direction_y; }

    //Method to update position
    void updatePosition() {
        location_x += direction_x;
        location_y += direction_y;
    }

    virtual void draw(sf::RenderWindow& window){}
};