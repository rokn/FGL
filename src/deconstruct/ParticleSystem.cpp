//
// Created by rokner on 2/18/18.
//

#include "deconstruct/ParticleSystem.h"
#include "deconstruct/ParticleBuilder.h"

ParticleSystem::ParticleSystem() {
    registerAsHandler(UPDATE_HANDLER);
    registerAsHandler(DRAW_HANDLER);
}

ParticleSystem::~ParticleSystem() {
    for(auto shapePair : _shapes) {
        delete shapePair.first;
    }
}

ParticleBuilder* ParticleSystem::getBuilder() {
    return new ParticleBuilder(this);
}

void ParticleSystem::update(const UpdateInfo &info) {
    for (auto& particle : _particles) {
        if(particle.active) {
            if(updateParticleTime(info.elapsedSeconds(), particle)) {
                updateParticle(particle, info.elapsedSeconds());
            }
        }
    }
}

bool ParticleSystem::updateParticleTime(float elapsedSeconds, Particle &particle) {
    if(particle.timed) {
        particle.timeLeft -= elapsedSeconds;
        if(particle.timeLeft <= 0) {
            particle.active = false;

            auto it = _shapes.find(particle.shape);
            if(it != _shapes.end()) {
                (*it).second--;
                if(!(*it).second) {
                    _shapes.erase(it);
                }
            }

            return false;
        }
    }

    return true;
}

void ParticleSystem::updateParticle(Particle &particle, float elapsedSeconds) {
    particle.position += particle.velocity * elapsedSeconds;
}

void ParticleSystem::draw(sf::RenderTarget &surface) {
    for (auto particle : _particles) {
        if(particle.active) {
            particle.shape->setPosition(particle.position);
            surface.draw(*particle.shape);
        }
    }
}

void ParticleSystem::addParticle(ParticleSystem::Particle particle) {
    _particles.push_back(particle);
    auto it = _shapes.find(particle.shape);
    if(it != _shapes.end()) {
        (*it).second++;
    } else {
        _shapes.insert({particle.shape, 1});
    }
}
