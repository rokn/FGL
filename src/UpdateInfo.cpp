//
// Created by rokner on 12/23/17.
//

#include "UpdateInfo.h"

void UpdateInfo::setElapsedTime(float delta) {
    this->delta = delta;
}

float UpdateInfo::elapsedSeconds() const {
    return delta;
}
