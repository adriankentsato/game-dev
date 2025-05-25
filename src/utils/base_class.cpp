#include "base_class.h"
#include <unordered_map>
#include <utility>

template <typename T>
std::unordered_map<std::string, T>& BaseClass::getContainer()
{
    static std::unordered_map<std::string, T> container;

    return container;
};

template <typename T>
const std::unordered_map<std::string, T>& BaseClass::getContainer() const
{
    static const std::unordered_map<std::string, T> container;

    return container;
};

template <typename T>
void BaseClass::addComponent(const std::string& className, T& cls)
{
    auto& container = getContainer<T>();

    getContainer<T>()[className] = std::forward<T>(cls);
};

template <typename T>
T& BaseClass::getComponent(const std::string &className)
{
    auto& container = getContainer<T>();

    return container.at(className);
};
