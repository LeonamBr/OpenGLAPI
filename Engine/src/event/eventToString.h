#ifndef EVENT_TO_STRING_H
#define EVENT_TO_STRING_H

#include <string>
#include <sstream>
#include "Event.h"

inline std::string ToString(const MouseMovedEvent& e) {
    std::stringstream ss;
    ss << "MouseMovedEvent(x=" << e.x << ", y=" << e.y << ")";
    return ss.str();
}

inline std::string ToString(const KeyPressedEvent& e) {
    std::stringstream ss;
    ss << "KeyPressedEvent(key=" << e.keycode << ", repeat=" << (e.repeat ? "true" : "false") << ")";
    return ss.str();
}

inline std::string ToString(const WindowResizeEvent& e) {
    std::stringstream ss;
    ss << "WindowResizeEvent(width=" << e.width << ", height=" << e.height << ")";
    return ss.str();
}

#endif