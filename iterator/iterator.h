#ifndef DESIGN_PATTERN_CPP_ITERATOR_H
#define DESIGN_PATTERN_CPP_ITERATOR_H

#include <memory>
#include <vector>

namespace design_pattern::iterator {

    template<class T>
    class Iterator;

    template<class T>
    class Aggregate {
    public:
        virtual ~Aggregate() = default;

        virtual std::unique_ptr<Iterator<T>> CreateIterator() = 0;
    };

    template<class T>
    class ConcreteAggregate : public Aggregate<T> {
    public:
        explicit ConcreteAggregate(const std::size_t size) {
            elements_.resize(size);
        }

        ~ConcreteAggregate() override = default;

        std::unique_ptr<Iterator<T>> CreateIterator() override;

        std::size_t Size() {
            return elements_.size();
        }

        T &operator[](std::size_t index) {
            return elements_.at(index);
        }


    private:
        std::vector<T> elements_;
    };


    template<class T>
    class Iterator {
    public:
        virtual ~Iterator() = default;

        virtual void First() = 0;

        virtual void Next() = 0;

        virtual bool IsDone() = 0;

        virtual T &CurrentItem() = 0;
    };


    template<class T>
    class ConcreteIterator : public Iterator<T> {
    public:
        explicit ConcreteIterator(ConcreteAggregate<T> &aggregate) : aggregate_(aggregate), index_(0U) {}

        ~ConcreteIterator() override = default;

        void First() override {
            index_ = 0;
        }

        void Next() override {
            ++index_;
        }

        bool IsDone() override {
            return index_ >= aggregate_.Size();
        }

        T &CurrentItem() override {
            if (IsDone()) {
                throw std::out_of_range::exception();
            }
            return aggregate_[index_];
        }

    private:
        ConcreteAggregate<T> &aggregate_;
        std::size_t index_;
    };

    template<class T>
    std::unique_ptr<Iterator<T>> ConcreteAggregate<T>::CreateIterator() {
        return std::make_unique<ConcreteIterator<T>>(*this);
    }
}
#endif