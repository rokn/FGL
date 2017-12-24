//
// Created by rokner on 12/23/17.
//

#ifndef FGL_FLOATINGNETWORK_H
#define FGL_FLOATINGNETWORK_H


#include "GameHandler.h"

class NetworkObject {
public:
    NetworkObject(const sf::Rect<int> &area);
    ~NetworkObject();
    void update(const UpdateInfo &info, const sf::Rect<int> &area);
    const sf::Shape& getShape() const;
private:
    sf::Shape* shape;
    sf::Vector2f velocity;

    void reset(const sf::Rect<int> &area);

    void generateVelocity();
};

class Line {
public:
    const sf::Vector2f &getFrom() const;

    void setFrom(const sf::Vector2f &from);

    const sf::Vector2f &getTo() const;

    void setTo(const sf::Vector2f &to);

    float getIntensity() const;

    void setIntensity(float intensity);

private:
    sf::Vector2f from;
    sf::Vector2f to;
    float intensity;
};

class FloatingNetwork : public GameHandler {
public:
    FloatingNetwork(const sf::Rect<int>& area, float proximity, uint objectCount);
    ~FloatingNetwork();
    void update(const UpdateInfo &info) override;
    void draw(sf::RenderTarget &surface) override;
private:
    sf::Rect<int> _area;
    float _proximity;
    std::vector<NetworkObject*> _objects;
    std::vector<Line> _lines;

    void generateObjects(uint count);

    float getDistance(const sf::Vector2f &from, const sf::Vector2f &to);
};


#endif //FGL_FLOATINGNETWORK_H
