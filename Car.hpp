#pragma once
#include "Object.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Car : public Object {
private:
    
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void draw(sf::RenderWindow& window);

    Car(float loc_x, float loc_y, float dir_x, float dir_y) {
        this->location_x = loc_x;
        this->location_y = loc_y;
        this->direction_x = dir_x;
        this->direction_y = dir_y;

        //load the textures 
        if (!texture.loadFromFile("resources/Car_Sprite.png")) {
            std::cout << "No Car texture found\n";
        }
        sprite.setTexture(texture);
    }

    //default copy constuctor
    Car(const Car&) = default;
    Car& operator=(const Car&) = default;

};

//passed a window, loads texture and displays
void Car::draw(sf::RenderWindow& window) {

    sprite.setPosition(this->location_x, this->location_y);

    window.draw(sprite);
}