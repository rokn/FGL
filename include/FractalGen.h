//
// Created by rokner on 2/17/18.
//

#ifndef FGL_FRACTALGEN_H
#define FGL_FRACTALGEN_H


#include "GameHandler.h"
#include "Complex.h"

class FractalGen : public GameHandler {
public:
    FractalGen(const sf::Rect<sf::Uint32>& area);

    bool handle_event(const sf::Event &event) override;

    void update(const UpdateInfo &info) override;

    void draw(sf::RenderTarget &surface) override;

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Uint8* _pixels;
    sf::Rect<sf::Uint32> _area;
    double _magnification;
    sf::Uint8 _zoom;
    Complex<double> _center;

    bool allocatePixels(sf::Uint32 size);

    void setPixel(sf::Uint32 x, sf::Uint32 y, const sf::Color color);

    void generateMandelbrot(sf::Uint32 maxIterations);

    sf::Uint32 getIterations(Complex<double> c, sf::Uint32 MAX_ITERATIONS, sf::Uint32 threshold) const;

    Complex<double> mapToComplex(sf::Uint32 x, sf::Uint32 y);

    void updateMandelbrot();
};


#endif //FGL_FRACTALGEN_H
