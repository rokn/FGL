//
// Created by rokner on 12/25/17.
//

#include <initium_novum/BasicFoodGenerator.h>
#include "initium_novum/World.h"
#include <algorithm>

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

    removeOldEntities();
    addNewEntities();
}

void in::World::addNewEntities() {
    for(auto entity : _toAdd) {
        _entities.push_back(entity);
    }

    _toAdd.clear();
}

void in::World::removeOldEntities() {
    for(auto entity : _toRemove) {
        auto pos = std::find(_entities.begin(), _entities.end(), entity);
        if(pos != _entities.end()) {
            _entities.erase(pos);
        }
    }

    _toRemove.clear();
}

void in::World::draw(sf::RenderTarget &surface) {
    for(auto entity : _entities) {
        surface.draw(*entity);
    }
}

void in::World::addEntity(in::Entity *entity) {
    _toAdd.push_back(entity);
}

in::World::~World() {
    for(auto entity : _entities) {
        delete entity;
    }
}

void in::World::removeEntity(in::Entity *entity) {
    _toRemove.push_back(entity);
}
