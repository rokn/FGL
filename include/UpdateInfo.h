//
// Created by rokner on 12/23/17.
//

#ifndef FGL_UPDATEINFO_H
#define FGL_UPDATEINFO_H


#include <SFML/System.hpp>

class UpdateInfo {
public:
    float elapsedSeconds() const;
    void setElapsedTime(float delta);

private:
    float delta;
};


#endif //FGL_UPDATEINFO_H
