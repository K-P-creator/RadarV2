#pragma once

#include <vector>
#include "Object.hpp"
#include <iostream>

class Radar {
private:
    float location_x; // x-coordinate of the location
    float location_y; // y-coordinate of the location
    float radius; // Radius of the radar

public:
    // Default Constructor
    Radar() : location_x(0.0), location_y(0.0), radius(0.0) {}

    // Constructor with initial values for location and radius
    Radar(float loc_x, float loc_y, float rad) : location_x(loc_x), location_y(loc_y), radius(rad) {}

    // Method to set location
    void setLocation(float x, float y) {
        location_x = x;
        location_y = y;
    }

    // Method to set the radius
    void setRadius(float rad) {
        radius = rad;
    }

    // Method to get the radius
    float getRadius() const {
        return radius;
    }

    //Method to get x
    float getX() const {
        return location_x;
    }

    //Method to get y
    float getY() const {
        return location_y;
    }

    //Method to check object within bounds
    bool checkObjectRadar(const Object* obj) const {
        float distSq = ((obj->getLocationX() - location_x) * (obj->getLocationX() - location_x)) +
            ((obj->getLocationY() - location_y) * (obj->getLocationY() - location_y));

        return distSq <= (radius * radius);
    }
};