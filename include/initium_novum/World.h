//
// Created by rokner on 12/25/17.
//

#ifndef FGL_WORLD_H
#define FGL_WORLD_H


#include "GameHandler.h"
#include "Entity.h"

namespace in
{
    class World : public GameHandler {
    public:
        explicit World(sf::Rect<int> area);
        ~World();

        void update(const UpdateInfo &info) override;

        void draw(sf::RenderTarget &surface) override;

        void addEntity(Entity* entity);

    private:
        std::vector<Entity*> _entities;
        sf::Rect<int> _area;
    };
}


#endif //FGL_WORLD_H
