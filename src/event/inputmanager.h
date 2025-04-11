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
            OnMouseMoved(e);
        });

        bus.Subscribe<KeyPressedEvent>([this](const KeyPressedEvent& e) {
            OnKeyPressed(e);
        });
    }

    void OnMouseMoved(const MouseMovedEvent& e) {
        LOG_INFO("{0}", ToString(e));
    }

    void OnKeyPressed(const KeyPressedEvent& e) {
        LOG_INFO("Tecla pressionada: {0}", KeyCodeToString(e.keycode));
        LOG_INFO("{0}", ToString(e));
    }
};

#endif