#include <iostream>
#include <utility>
#include <vector>
#include <memory>

namespace design_pattern::composite_design_pattern {
#ifndef DESIGN_PATTERN_CPP_COMPOSITE_H
#define DESIGN_PATTERN_CPP_COMPOSITE_H

    class Component {
    public:
        ~Component() = default;

        virtual void Operation() = 0;

        virtual void Add(Component *new_child) { throw std::invalid_argument(""); };

        virtual void Remove(Component *child_to_remove) { throw std::invalid_argument(""); };

        virtual Component *GetChild(int index) { throw std::invalid_argument(""); };

    };

    class Composite : public Component {
    public:

        virtual  ~Composite() = default;

        void Operation() override {
            for (const auto &item: _children) {
                item->Operation();
            }
        }

        void Add(Component *new_child) override {
            _children.push_back(new_child);
        }

        void Remove(Component *child_to_remove) override {
            //iterate over vector until found child_to_remove and then removes
            for (auto it = std::begin(_children); it != std::end(_children); ++it) {
                if (*it == child_to_remove) {
                    _children.erase(it);
                    break;
                }
            }
        }

        Component *GetChild(int index) override {
            return _children.at(index);
        }

    private:
        std::vector<Component *> _children;
    };

    class Leaf : public Component {
    public:

        explicit Leaf(std::string message) : _message(std::move(message)) {}

        virtual  ~Leaf() = default;

        void Operation() override {
            std::cout << _message << std::endl;
        }

    private:
        std::string _message;
    };

#endif
}