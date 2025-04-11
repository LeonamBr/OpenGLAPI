#ifndef EVENTS_H
#define EVENTS_H

struct MouseMovedEvent {
    float x;
    float y;
};

struct KeyPressedEvent {
    int keycode;
    bool repeat;
};

struct WindowResizeEvent {
    int width;
    int height;
};

#endif