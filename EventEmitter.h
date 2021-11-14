#include <any>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

class EventEmitter
{
public:
    void emitSync(const std::string& event);

    template <typename T>
    void emitSync(const std::string& event, const T& args);

    void on(const std::string& event, std::function<void()> listener);

    template <typename T>
    void on(const std::string& event, std::function<void(const T&)> listener);

private:
    std::unordered_map<std::string, std::vector<std::any>> listeners;
};

void EventEmitter::emitSync(const std::string& event)
{
    for(auto& callback : listeners[event])
        std::any_cast<std::function<void()>>(callback)();
}

template <typename T>
void EventEmitter::emitSync(const std::string& event, const T& args)
{
    for(auto& callback : listeners[event])
        std::any_cast<std::function<void(const T&)>>(callback)(args);
}

void EventEmitter::on(const std::string& event, std::function<void()> listener)
{
    listeners[event].emplace_back(listener);
}

template <typename T>
void EventEmitter::on(const std::string& event, std::function<const T&> listener)
{
    listeners[event].emplace_back(listener);
}