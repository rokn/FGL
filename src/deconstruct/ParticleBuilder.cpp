//
// Created by rokner on 2/18/18.
//

#include <deconstruct/ParticleSystem.h>
#include "deconstruct/ParticleBuilder.h"

ParticleBuilder::ParticleBuilder(ParticleSystem *system)
:_system(system) { }

void ParticleBuilder::build() {
    ParticleSystem::Particle particle;
    particle.active = true;
    particle.timed = _timed;
    particle.position = _position;
    particle.velocity = _velocity;
    particle.timeLeft = _time;
    particle.shape = _shape;

    _system->addParticle(particle);
}

ParticleBuilder &ParticleBuilder::setPosition(const sf::Vector2f &position) {
    _position = position;
    return *this;
}

ParticleBuilder &ParticleBuilder::setVelocity(const sf::Vector2f &velocity) {
    _velocity = velocity;
    return *this;
}

ParticleBuilder &ParticleBuilder::setTimed(bool timed) {
    _timed = timed;
    return *this;
}

ParticleBuilder &ParticleBuilder::setTime(float time) {
    _time = time;
    return *this;
}

ParticleBuilder &ParticleBuilder::setShape(sf::Shape* shape) {
    _shape = shape;
    return *this;
}
