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
    int keycode;
};

struct WindowResizeEvent {
    int width;
    int height;
};

struct WindowCloseEvent {};

struct ScrollEvent {
    double xoffset;
    double yoffset;
};

#endif