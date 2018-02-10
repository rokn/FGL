//
// Created by rokner on 12/25/17.
//

#ifndef FGL_BASICFOOD_H
#define FGL_BASICFOOD_H


#include "Entity.h"

namespace in
{
    class BasicFood : public Entity {
    public:
        BasicFood(float amount);

        size_t getPointCount() const override;

        sf::Vector2f getPoint(std::size_t index) const override;

        static float MIN_AMOUNT;
        static float MAX_AMOUNT;

    protected:
        void update(const UpdateInfo &timeInfo) override;

    private:
        sf::CircleShape shape;
        static float MIN_RADIUS;
        static float MAX_RADIUS;

        float getRadius(float amount);
    };
}


#endif //FGL_BASICFOOD_H
