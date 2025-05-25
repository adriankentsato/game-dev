#ifndef __BASE_CLASS_H__
#define __BASE_CLASS_H__

#include <string>
#include <unordered_map>

class BaseClass {
    template <typename T>
    std::unordered_map<std::string, T>& getContainer();

    template <typename T>
    const std::unordered_map<std::string, T>& getContainer() const;

public:
    template <typename T>
    void addComponent(const std::string& className, T& cls);
    template <typename T>
    T& getComponent(const std::string& className);
};

#endif