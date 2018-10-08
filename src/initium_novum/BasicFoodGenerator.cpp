//
// Created by rokner on 12/25/17.
//

#include <iostream>
#include "MathHelpers.h"
#include "initium_novum/BasicFood.h"
#include "initium_novum/BasicFoodGenerator.h"
#include "initium_novum/World.h"

in::BasicFoodGenerator::BasicFoodGenerator(sf::Rect<int> area, float minTime, float maxTime):
_area(area), _minTime(minTime), _maxTime(maxTime), _world(nullptr)
{
    reset();
    sf::Shape::update();
}

size_t in::BasicFoodGenerator::getPointCount() const {
    return 0;
}

sf::Vector2f in::BasicFoodGenerator::getPoint(std::size_t index) const {
    return {0, 0};
}

void in::BasicFoodGenerator::update(const UpdateInfo &timeInfo) {
    float elapsedSeconds = timeInfo.elapsedSeconds();
    while(elapsedSeconds > 0) {
        if(_currTime < elapsedSeconds) {
            elapsedSeconds -= _currTime;
            reset();
            generate();
        } else {
            _currTime -= elapsedSeconds;
            break;
        }
    }
}

void in::BasicFoodGenerator::reset() {
    _currTime = MathHelpers::lerp(_minTime, _maxTime, rand()/RAND_MAX);
}

void in::BasicFoodGenerator::generate() {
    if(_world != nullptr) {
        float amount = MathHelpers::lerp(BasicFood::MIN_AMOUNT, BasicFood::MAX_AMOUNT, (float)rand()/RAND_MAX);
        auto *food = new BasicFood(amount);
        int x = rand() % _area.width + _area.left;
        int y = rand() % _area.height + _area.top;
        food->setPosition(x, y);
        _world->addEntity(food);
    }
}

void in::BasicFoodGenerator::setWorld(in::World *world) {
    _world = world;
}
