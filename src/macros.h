#ifndef ENGINE_EVENT_MACROS_H
#define ENGINE_EVENT_MACROS_H

#include <eventbus.h>

#define REGISTER_EVENT(fn) [](const auto& e) { fn(e); }

#define LOG_EVENT_AS_STRING() [](const auto& e) { LOG_INFO("Evento: {}", ToString(e)); }

#define BIND_EVENT(bus, type, handler) \
    bus.Subscribe<type>([&](const type& e) { handler(e); })

#endif
