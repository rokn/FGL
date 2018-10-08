//
// Created by rokner on 2/18/18.
//

#ifndef FGL_PARTICLESYSTEM_H
#define FGL_PARTICLESYSTEM_H

#include <SFML/Graphics.hpp>
#include <GameHandler.h>

class ParticleBuilder;

class ParticleSystem : public GameHandler {
    friend ParticleBuilder;

public:
    ParticleSystem();
    ~ParticleSystem();

    ParticleBuilder* getBuilder();

    void update(const UpdateInfo &info) override;

    void draw(sf::RenderTarget &surface) override;

private:
    struct Particle {
        sf::Vector2f position;
        sf::Vector2f velocity;
        bool active;
        bool timed;
        float timeLeft;
        sf::Shape* shape;
    };

    void addParticle(Particle particle);

    std::vector<Particle> _particles;
    std::map<sf::Shape*, int> _shapes;

    bool updateParticleTime(float elapsedSeconds, Particle &particle);

    void updateParticle(Particle &particle, float elapsedSeconds);
};


#endif //FGL_PARTICLESYSTEM_H
