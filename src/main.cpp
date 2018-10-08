#include "FloatingNetwork.h"
#include "FractalGen.h"
#include "initium_novum/World.h"
#include "deconstruct/ParticleSystem.h"
#include "deconstruct/ParticleBuilder.h"
#include "Application.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Config config;
    config.windowWidth = 800;
    config.windowHeight = 600;
    config.appName = "FGL";
    config.antialiasLevel = 4;

    auto *application = new Application(config);

    sf::Rect<sf::Uint32> area(0, 0, config.windowWidth, config.windowHeight);
//    auto *network = new FloatingNetwork(area, 100, 70);

//    application->registerHandler(network);

//    auto *world = new in::World(area);

//    application->registerHandler(world);

//    auto *fractal = new FractalGen(area);

//    application->registerHandler(fractal);

    auto *particleSystem = new ParticleSystem();

    auto *circle = new sf::CircleShape(2);

    auto builder = particleSystem->getBuilder();
    builder->setPosition({50,50})
            .setVelocity({30,30})
            .setTimed(false)
            .setShape(circle)
            .build();

    application->registerHandler(particleSystem);

    int exitCode = application->run();

//    delete world;
//    delete network;
//    delete fractal;
    delete application;

    return exitCode;
}
