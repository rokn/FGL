//
// Created by rokner on 12/23/17.
//

#include "FloatingNetwork.h"

FloatingNetwork::FloatingNetwork(const sf::Rect<sf::Uint32> &area, float proximity, uint objectCount):
        _area(area), _proximity(proximity*proximity)
{
    generateObjects(objectCount);
    registerAsHandler(UPDATE_HANDLER);
    registerAsHandler(DRAW_HANDLER);
    _area.left -= proximity;
    _area.top -= proximity;
    _area.width += 2*proximity;
    _area.height += 2*proximity;
}

void FloatingNetwork::update(const UpdateInfo &info) {
    for(auto obj : _objects) {
        obj->update(info, _area);
    }

    _lines.clear();

    for (auto it = _objects.begin(); it != (_objects.end() - 1); it++) {
        for (auto ot = it; ot != _objects.end(); ot++) {
            auto from = (*it)->getShape().getPosition();
            auto to = (*ot)->getShape().getPosition();
            float distSqr = getDistance(from, to);

            if(distSqr < _proximity) {
                Line line;
                line.setFrom(from);
                line.setTo(to);
                line.setIntensity(1 - (distSqr / _proximity));
                _lines.push_back(line);
            }
        }
    }

}

void FloatingNetwork::draw(sf::RenderTarget &surface) {
    sf::VertexArray buffer(sf::Lines, _lines.size()*2);
    for (int i = 0; i < _lines.size(); ++i) {
        sf::Color color(255, 255, 255, (sf::Uint8) (255 * _lines[i].getIntensity()));

        buffer[i*2].position = _lines[i].getFrom();
        buffer[i*2].color = color;

        buffer[i*2+1].position = _lines[i].getTo();
        buffer[i*2+1].color = color;
    }

    surface.draw(buffer);

    for(auto obj : _objects) {
        surface.draw(obj->getShape());
    }
}

void FloatingNetwork::generateObjects(uint count) {
    for (int i = 0; i < count; ++i) {
        _objects.push_back(new NetworkObject(_area));
    }
}

FloatingNetwork::~FloatingNetwork() {
    for(auto obj : _objects) {
        delete obj;
    }
}

float FloatingNetwork::getDistance(const sf::Vector2f &from, const sf::Vector2f &to) {
    float diffX = to.x - from.x;
    float diffY = to.y - from.y;
    return (diffX*diffX + diffY*diffY);
}

NetworkObject::NetworkObject(const sf::Rect<sf::Uint32> &area) {
    float radius = 8;
    shape = new sf::CircleShape(radius);
    shape->setFillColor(sf::Color::White);
    shape->setOutlineThickness(0);
    shape->setOrigin(radius, radius);
    int x = rand() % area.width + area.left;
    int y = rand() % area.height + area.top;
    shape->setPosition(x, y);
    generateVelocity();
}

void NetworkObject::generateVelocity() {
    float angle = (float) ((rand() / (float)RAND_MAX) * 2.0f * M_PI);
    float speed = rand() % 40 + 20;
    velocity.x = (float) (cos(angle) * speed);
    velocity.y = (float) (sin(angle) * speed);
}

NetworkObject::~NetworkObject() {
    delete shape;
}

void NetworkObject::update(const UpdateInfo &info, const sf::Rect<sf::Uint32> &area) {
    shape->move(velocity * info.elapsedSeconds());

    if(!area.intersects(sf::Rect<sf::Uint32>(shape->getGlobalBounds()))) {
        reset(area);
    }
}

void NetworkObject::reset(const sf::Rect<sf::Uint32> &area) {
    float x,y;
    if(rand()%2) {
        if(rand()%2) {
            x = area.left - shape->getGlobalBounds().width/2;
        } else {
            x = area.left + area.width + shape->getGlobalBounds().width/2;
        }
        y = rand() % area.height + area.top;
    } else {
        if(rand()%2) {
            y = area.top - shape->getGlobalBounds().height/2;
        } else {
            y = area.top + area.height + shape->getGlobalBounds().height/2;
        }
        x = rand() % area.width + area.left;
    }

    shape->setPosition(x, y);
    generateVelocity();
}

const sf::Shape &NetworkObject::getShape() const {
    return *shape;
}

const sf::Vector2f &Line::getFrom() const {
    return from;
}

void Line::setFrom(const sf::Vector2f &from) {
    Line::from = from;
}

const sf::Vector2f &Line::getTo() const {
    return to;
}

void Line::setTo(const sf::Vector2f &to) {
    Line::to = to;
}

float Line::getIntensity() const {
    return intensity;
}

void Line::setIntensity(float intensity) {
    Line::intensity = intensity;
}
