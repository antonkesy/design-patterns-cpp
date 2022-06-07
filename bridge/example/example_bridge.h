#ifndef DESIGN_PATTERN_CPP_EXAMPLE_BRIDGE_H
#define DESIGN_PATTERN_CPP_EXAMPLE_BRIDGE_H

#include <list>
#include <vector>

template<class T>
class ListImplementor {
public:
    virtual ~ListImplementor() = default;

    virtual void AddElement(T &element) = 0;

    virtual void RemoveElement(T &element) = 0;

    virtual T &operator[](size_t index) = 0;
};

template<class T>
class List : public ListImplementor<T> {
public:
    virtual ~List() = default;

    void AddElement(T &element) override {
        _list.push_back(element);
    }

    void RemoveElement(T &element) override {
        _list.remove(element);
    }

    T &operator[](size_t index) override {
        auto list_it = _list.begin();
        std::advance(list_it, index);
        return *list_it;
    }

private:
    std::list<T> _list;
};

template<class T>
class Vector : public ListImplementor<T> {
public:
    virtual ~Vector() = default;

    void AddElement(T &element) override {
        _vector.push_back(element);
    }

    void RemoveElement(T &element) override {
        auto vector_it = _vector.begin();
        while (vector_it++ != _vector.end()) {
            if (*vector_it == element) {
                _vector.erase(vector_it);
                break;
            }
        }
    }

    T &operator[](size_t index) override {
        return _vector.at(index);
    }

private:
    std::vector<T> _vector;
};

template<class T>
class ListHolder {
public:
    explicit ListHolder(unsigned int listSize) {
        if (listSize > 50) {
            list_ = std::make_unique<List<T>>();
        } else {
            list_ = std::make_unique<Vector<T>>();
        }
    }

    ~ListHolder() = default;

    void AddElement(T &element) {
        list_->AddElement(element);
    }

    void RemoveElement(T &element) {
        list_->RemoveElement(element);
    }

    T &operator[](int index) {
        return list_->operator[](index);
    }

private:
    std::unique_ptr<ListImplementor<T>> list_;
};

#endif //DESIGN_PATTERN_CPP_EXAMPLE_BRIDGE_H
