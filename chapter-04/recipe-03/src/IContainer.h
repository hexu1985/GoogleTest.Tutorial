#pragma once
#include <functional>

typedef std::function<void (const size_t num)> IteratorFuncT;

class IContainer {
public:
    virtual void add(size_t num) = 0;
    virtual size_t count() const = 0;
    virtual void forEach(IteratorFuncT closure) const = 0;
};
