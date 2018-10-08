//
// Created by rokner on 12/23/17.
//

#include <iostream>
#include "Application.h"

Application::Application(const Config &config):
    _clearColor(sf::Color(100, 149, 237)) //Cornflower Blue
//    _clearColor(sf::Color(50,50,50)) //Cornflower Blue
//    _clearColor(sf::Color::Transparent) //Cornflower Blue
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = config.antialiasLevel;
    _renderWindow = std::make_shared<sf::RenderWindow>(
                            sf::VideoMode(config.windowWidth, config.windowHeight),
                            config.appName,
                            sf::Style::Default,
                            settings);
    _renderWindow->setVerticalSyncEnabled(true);
}

int Application::run() {
    _isRunning = true;

    sf::Clock elapsedClock;
    float accumulator = 0.0f;
    float deltaTime = 0.016;
    float currentTime;
    float fps;

    while(_renderWindow->isOpen() && _isRunning) {
        handleEvents();
        currentTime = elapsedClock.restart().asSeconds();
        accumulator += currentTime;
        fps = 1.f / currentTime;


        while(accumulator >= deltaTime) {
            update(deltaTime);
            accumulator -= deltaTime;
        }

        draw();
    }
    return 0;
}

void Application::draw(){
    _renderWindow->clear(_clearColor);

    for(auto handler : _drawHandlers) {
        handler->draw(*_renderWindow);
    }

    _renderWindow->display();
}

void Application::handleEvents() {
    bool eventConsumed;
    sf::Event event;
    while(_renderWindow->pollEvent(event)) {
            eventConsumed = false;

            for(auto handler : _eventHandlers) {
                eventConsumed = handler->handle_event(event);

                if(eventConsumed) {
                    break;
                }
            }

            if(!eventConsumed) {
                internalEventHandle(event);
            }
        }
}

void Application::internalEventHandle(const sf::Event &event) {
    switch(event.type) {
        case sf::Event::Closed:
            exit();
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Escape) {
                exit();
            }
            break;
        default:break;
    }
}

void Application::exit() {
    _isRunning = false;
}

void Application::update(float delta) {
    UpdateInfo info;
    info.setElapsedTime(delta);
    for(auto handler : _updateHandlers) {
        handler->update(info);
    }
}

void Application::registerHandler(GameHandler *handler) {
    int type = handler->getType();

    if(type & EVENT_HANDLER) {
        _eventHandlers.push_back(handler);
    }

    if(type & UPDATE_HANDLER) {
        _updateHandlers.push_back(handler);
    }

    if(type & DRAW_HANDLER) {
        _drawHandlers.push_back(handler);
    }
}
