//
// Created by rokner on 2/18/18.
//

#ifndef FGL_PARTICLEBUILDER_H
#define FGL_PARTICLEBUILDER_H

#include <SFML/Graphics.hpp>

class ParticleSystem;

class ParticleBuilder {
    friend ParticleSystem;
public:
    ParticleBuilder& setPosition(const sf::Vector2f& position);
    ParticleBuilder& setVelocity(const sf::Vector2f& velocity);
    ParticleBuilder& setTimed(bool timed);
    ParticleBuilder& setTime(float time);
    ParticleBuilder& setShape(sf::Shape* shape);

    void build();

private:
    explicit ParticleBuilder(ParticleSystem* system);

    ParticleSystem* _system;

    sf::Vector2f _position;
    sf::Vector2f _velocity;
    bool _timed;
    float _time;
    sf::Shape* _shape;
};


#endif //FGL_PARTICLEBUILDER_H
