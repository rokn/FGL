//
// Created by rokner on 12/25/17.
//

#include <initium_novum/BasicFoodGenerator.h>
#include "initium_novum/World.h"

in::World::World(sf::Rect<int> area):
_area(area)
{
    registerAsHandler(UPDATE_HANDLER);
    registerAsHandler(DRAW_HANDLER);
    BasicFoodGenerator *foodGenerator = new BasicFoodGenerator(area, 0.01f, 0.02f);
    foodGenerator->setWorld(this);
    addEntity(foodGenerator);
}

void in::World::update(const UpdateInfo &info) {
    for(auto entity : _entities) {
        entity->update(info);
    }
}

void in::World::draw(sf::RenderTarget &surface) {
    for(auto entity : _entities) {
        surface.draw(*entity);
    }
}

void in::World::addEntity(in::Entity *entity) {
    _entities.push_back(entity);
}

in::World::~World() {
    for(auto entity : _entities) {
        delete entity;
    }
}
