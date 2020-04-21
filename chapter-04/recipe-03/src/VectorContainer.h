// VectorContainer.h

#pragma once
#include "IContainer.h"
#include <vector>

class VectorContainer: public IContainer {
private:
    std::vector<size_t> items;

public:
    void add(size_t num) override {
        items.push_back(num);
    }

    size_t count() const override {
        return items.size();
    }

    void forEach(IteratorFuncT closure) const override {
        for(const size_t item: items) {
            closure(item);
        }
    }
};
