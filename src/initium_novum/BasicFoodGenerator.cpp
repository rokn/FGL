//
// Created by rokner on 12/25/17.
//

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
    _currTime -= timeInfo.elapsedSeconds();

    if(_currTime <= 0) {
        reset();
        generate();
    }
}

void in::BasicFoodGenerator::reset() {
    _currTime = MathHelpers::lerp(_minTime, _maxTime, rand()/RAND_MAX);
}

void in::BasicFoodGenerator::generate() {
    if(_world != nullptr) {
        float amount = MathHelpers::lerp(BasicFood::MIN_AMOUNT, BasicFood::MAX_AMOUNT, rand()/RAND_MAX);
        auto *food = new BasicFood(amount);
        int x = rand() % _area.width + _area.left;
        int y = rand() % _area.height + _area.top;
        food->setPosition(x, y);
        _world->addEntity(food);
    }
}

void in::BasicFoodGenerator::setWorld(in::World *world) {
    _world = world;
    for (int i = 0; i < 3; ++i) {
        generate();
    }
}
