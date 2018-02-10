//
// Created by rokner on 12/25/17.
//

#ifndef FGL_ENTITY_H
#define FGL_ENTITY_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <UpdateInfo.h>

namespace in
{
    class World;

    class Entity : public sf::Shape {
        friend class World;
    protected:
        virtual void update(const UpdateInfo& timeInfo) = 0;
    };
}


#endif //FGL_ENTITY_H
