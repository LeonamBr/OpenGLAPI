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

struct KeyReleasedEvent {
    int key;
};

struct WindowResizeEvent {
    int width;
    int height;
};

struct ScrollEvent {
    double xoffset;
    double yoffset;
};

#endif