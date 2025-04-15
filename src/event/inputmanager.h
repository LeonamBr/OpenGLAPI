#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "EventBus.h"
#include "Event.h"
#include "eventToString.h"
#include <iostream>
#include <log.h>
#include <keycodeUtils.h>

class InputManager {
public:
    void Register(EventBus& bus) {
        bus.Subscribe<MouseMovedEvent>([this](const MouseMovedEvent& e) {
            
        });

        bus.Subscribe<KeyPressedEvent>([this](const KeyPressedEvent& e) {
            
        });
    }

};

#endif