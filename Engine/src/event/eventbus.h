#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <memory>

class EventBus {
public:
    template<typename EventType>
    using HandlerFunc = std::function<void(const EventType&)>;

    template<typename EventType>
    void Subscribe(HandlerFunc<EventType> handler) {
        auto wrapper = [handler](const void* e) {
            handler(*static_cast<const EventType*>(e));
        };
        handlers[typeid(EventType)].push_back(wrapper);
    }

    template<typename EventType>
    void Emit(const EventType& event) const {
        auto it = handlers.find(typeid(EventType));
        if (it != handlers.end()) {
            for (const auto& handler : it->second) {
                handler(&event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const void*)>>> handlers;
};

#endif