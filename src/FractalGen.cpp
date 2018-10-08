//
// Created by rokner on 2/17/18.
//

#include <iostream>
#include <Complex.h>
#include "FractalGen.h"
#include <omp.h>

FractalGen::FractalGen(const sf::Rect<sf::Uint32> &area)
: _area(area),
  _center(-0.5, 0),
  _magnification(1),
  _zoom(1)
{
    registerAsHandler(EVENT_HANDLER);
    registerAsHandler(UPDATE_HANDLER);
    registerAsHandler(DRAW_HANDLER);

    if(!allocatePixels(area.width * area.height * 4)) {
        std::cerr << "Couldn't allocate memory" << std::endl;
    } else {
        generateMandelbrot(50);
    }


    _texture.create(area.width, area.height);
    _texture.update(_pixels);
    _sprite.setTexture(_texture);
}

bool FractalGen::handle_event(const sf::Event &event) {
    switch(event.type) {
        case sf::Event::MouseButtonPressed:
            if(event.mouseButton.button == sf::Mouse::Left) {
                _magnification /= 2.0;
            } else if(event.mouseButton.button == sf::Mouse::Right) {
                _magnification *= 2.0;
            }
            _center = mapToComplex(static_cast<sf::Uint32>(event.mouseButton.x), static_cast<sf::Uint32>(event.mouseButton.y));
            updateMandelbrot();
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Space) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                    _zoom -= 5;
                } else {
                    _zoom += 5;
                }
                updateMandelbrot();
            }
            if(event.key.code == sf::Keyboard::S) {
                _texture.copyToImage().saveToFile("/home/rokner/Wallpapers/fractalwp.png");
            }
            break;
        default:break;
    }
}

void FractalGen::updateMandelbrot() {
    generateMandelbrot(60 + _zoom);
    _texture.update(_pixels);
}

void FractalGen::update(const UpdateInfo &info) {
}

void FractalGen::draw(sf::RenderTarget &surface) {
    surface.draw(_sprite);
}

bool FractalGen::allocatePixels(sf::Uint32 size) {
    _pixels = new (std::nothrow) sf::Uint8[size];

    return _pixels != nullptr;
}

void FractalGen::setPixel(sf::Uint32 x, sf::Uint32 y, const sf::Color color) {
    _pixels[(y*_area.width + x)*4 + 0] = color.r;
    _pixels[(y*_area.width + x)*4 + 1] = color.g;
    _pixels[(y*_area.width + x)*4 + 2] = color.b;
    _pixels[(y*_area.width + x)*4 + 3] = color.a;
}

void FractalGen::generateMandelbrot(sf::Uint32 maxIterations) {
    const sf::Uint32 THRESHOLD = 4;
#pragma omp parallel
    for (sf::Uint32 y = 0; y < _area.height; ++y) {
        for (sf::Uint32 x = 0; x < _area.width; ++x) {
            auto iter = getIterations(mapToComplex(x, y), maxIterations, THRESHOLD);
            auto intensity = (double)iter/maxIterations;
            if(iter==maxIterations) {
                intensity = 0;
            }
            sf::Color color(0, static_cast<sf::Uint8>(255 * intensity), 0);
            setPixel(x,y,color);
        }
    }
}

sf::Uint32 FractalGen::getIterations(Complex<double> c, sf::Uint32 maxIterations, sf::Uint32 threshold) const {
    sf::Uint32 iter = 0;
    Complex<double> z(0,0);
    for (;iter < maxIterations; ++iter) {
        if((z.re()*z.re() + z.im()*z.im()) >= threshold) {
            break;
        }
        z = z*z + c;
    }

    return iter;
}

Complex<double> FractalGen::mapToComplex(sf::Uint32 x, sf::Uint32 y) {
    const double REAL_RANGE =  1.5;
    const double IM_RANGE =  1;

    double realMax = _center.re() + REAL_RANGE*_magnification;
    double realMin = _center.re() - REAL_RANGE*_magnification;
    double imMax = _center.im() + IM_RANGE*_magnification;
    double imMin = _center.im() - IM_RANGE*_magnification;

    double real = (double)x/_area.width;
    real = real*(realMax-realMin) + realMin;

    double im = (double)y/_area.height;
    im = im*(imMax-imMin) + imMin;

    return {real, im};
}
