#pragma once
#include "Object.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>


class Plane : public Object {
private:
    //attributes for loading textures
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void draw(sf::RenderWindow& window);

    Plane(float loc_x, float loc_y, float dir_x, float dir_y) {
        this->location_x = loc_x;
        this->location_y = loc_y;
        this->direction_x = dir_x;
        this->direction_y = dir_y;

        //load the textures 
        if (!texture.loadFromFile("resources/Plane_Sprite.png")) {
            std::cout << "No Plane texture found\n";
        }
        else {
            std::cout << "Plane texture loaded succesfully\n";
        }
        sprite.setTexture(texture);
    }

    //default copy constuctor
    Plane(const Plane&) = default;
    Plane& operator=(const Plane&) = default;

};

//passed a window, loads texture and displays
void Plane::draw(sf::RenderWindow& window) {

    sprite.setPosition(this->location_x, this->location_y);

    window.draw(sprite);
}