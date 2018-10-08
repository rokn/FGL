//
// Created by rokner on 12/25/17.
//

#include "MathHelpers.h"
#include "initium_novum/BasicFood.h"

float in::BasicFood::MIN_AMOUNT = 5;
float in::BasicFood::MAX_AMOUNT = 15;

float in::BasicFood::MIN_RADIUS = 3;
float in::BasicFood::MAX_RADIUS = 8;

in::BasicFood::BasicFood(float amount) :
shape(getRadius(amount)){
    setFillColor(sf::Color::Green);
    sf::Shape::update();
}

size_t in::BasicFood::getPointCount() const {
    return shape.getPointCount();
}

sf::Vector2f in::BasicFood::getPoint(std::size_t index) const {
    return shape.getPoint(index);
}

void in::BasicFood::update(const UpdateInfo &timeInfo) {
}

float in::BasicFood::getRadius(float amount) {
    float mod = (amount - MIN_AMOUNT) / (MAX_AMOUNT - MIN_AMOUNT);
    return MathHelpers::lerp(MIN_RADIUS, MAX_RADIUS, mod);
}
