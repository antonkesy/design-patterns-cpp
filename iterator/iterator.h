namespace design_pattern::iterator
{
#ifndef DESIGN_PATTERN_CPP_ITERATOR_H
#define DESIGN_PATTERN_CPP_ITERATOR_H

    template<class T>
    class Iterator;

    template<class T>
    class Aggregate
    {
    public:
        virtual ~Aggregate() = default;

        virtual Iterator<T>* CreateIterator() = 0;
    };

    template<class T>
    class ConcreteAggregate : public Aggregate<T>
    {
    public:
        explicit ConcreteAggregate(const std::size_t size)
        {
            _elements = new int[size]();
            _size = size;
        }

        ~ConcreteAggregate() override
        {
            delete[] _elements;
        }

        Iterator<T>* CreateIterator() override;

        std::size_t Size()
        {
            return _size;
        }

        T& operator[](std::size_t index)
        {
            return _elements[index];
        }


    private:
        T* _elements;
        std::size_t _size;
    };


    template<class T>
    class Iterator
    {
    public:
        virtual ~Iterator() = default;

        virtual void First() = 0;

        virtual void Next() = 0;

        virtual bool IsDone() = 0;

        virtual T& CurrentItem() = 0;
    };


    template<class T>
    class ConcreteIterator : public Iterator<T>
    {
    public:
        explicit ConcreteIterator(ConcreteAggregate<T>* aggregate) : _aggregate(aggregate), _index(0U)
        {}

        ~ConcreteIterator() override = default;

        void First() override
        {
            _index = 0;
        }

        void Next() override
        {
            ++_index;
        }

        bool IsDone() override
        {
            return _index >= _aggregate->Size();
        }

        T& CurrentItem() override
        {
            if (IsDone())
            {
                throw std::out_of_range::exception();
            }
            return _aggregate->operator[](_index);
        }

    private:
        ConcreteAggregate<T>* _aggregate;
        std::size_t _index;
    };

    template<class T>
    Iterator<T>* ConcreteAggregate<T>::CreateIterator()
    {
        return new ConcreteIterator<T>(this);
    }

#endif
}