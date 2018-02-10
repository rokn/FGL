//
// Created by rokner on 12/25/17.
//

#ifndef FGL_BASICFOODGENERATOR_H
#define FGL_BASICFOODGENERATOR_H


#include <functional>
#include "Entity.h"

namespace in
{
    class BasicFoodGenerator : public Entity {

    public:
        explicit BasicFoodGenerator(sf::Rect<int> area, float minTime, float maxTime);

        size_t getPointCount() const override;
        sf::Vector2f getPoint(std::size_t index) const override;

        void setWorld(World *world);

    protected:
        void update(const UpdateInfo &timeInfo) override;

    private:
        sf::Rect<int> _area;
        float _minTime;
        float _maxTime;
        float _currTime;
        World *_world;

        void reset();
        void generate();

    };
}


#endif //FGL_BASICFOODGENERATOR_H
