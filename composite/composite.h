#ifndef DESIGN_PATTERN_CPP_COMPOSITE_H
#define DESIGN_PATTERN_CPP_COMPOSITE_H

#include <iostream>
#include <utility>
#include <vector>
#include <memory>

namespace design_pattern::composite {

    class Component {
    public:
        virtual ~Component() = default;

        virtual void Operation() = 0;

        virtual void Add(std::shared_ptr<Component> new_child) { throw std::invalid_argument(""); };

        virtual void Remove(std::shared_ptr<Component> child_to_remove) { throw std::invalid_argument(""); };

        virtual std::shared_ptr<Component> GetChild(int index) { throw std::invalid_argument(""); };

    };

    class Composite : public Component {
    public:

        ~Composite() override = default;

        void Operation() override {
            for (const auto &item: children_) {
                item->Operation();
            }
        }

        void Add(std::shared_ptr<Component> new_child) override {
            children_.push_back(new_child);
        }

        void Remove(std::shared_ptr<Component> child_to_remove) override {
            for (auto it = std::begin(children_); it != std::end(children_); ++it) {
                if (*it == child_to_remove) {
                    children_.erase(it);
                    return;
                }
            }
        }

        std::shared_ptr<Component> GetChild(int index) override {
            return children_.at(index);
        }

    private:
        std::vector<std::shared_ptr<Component> > children_;
    };

    class Leaf : public Component {
    public:

        explicit Leaf(std::string message) : message_(std::move(message)) {}

        ~Leaf() override = default;

        void Operation() override {
            std::cout << message_ << "\n";
        }

    private:
        std::string message_;
    };

}
#endif