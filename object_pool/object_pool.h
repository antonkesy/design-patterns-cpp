#include <iostream>
#include <vector>
#include <map>

namespace design_pattern::object_pool
{
#ifndef DESIGN_PATTERN_CPP_OBJECT_POOL_H
#define DESIGN_PATTERN_CPP_OBJECT_POOL_H

    class Reusable
    {
    public:
        explicit Reusable(size_t id) : _id(id)
        {}

        ~Reusable() = default;

        size_t GetID() const
        {
            return _id;
        }

        bool operator==(const Reusable& other) const
        {
            return _id == other.GetID();
        }

    private:
        const size_t _id;
    };

    class ReusablePool
    {
    public:
        explicit ReusablePool(size_t pool_start_size)
        {
            for (size_t i = 0U; i < pool_start_size; ++i)
            {
                _pool.push_back(GetNewReusable(i));
            }
        }

        ~ReusablePool()
        {
            for (const auto& item: _pool)
            {
                delete item.second;
            }
        }

        Reusable* GetReusable()
        {
            //check if there is any available reusable
            for (auto& it: _pool)
            {
                if (it.first)
                {
                    it.first = false;
                    return it.second;
                }
            }
            //if none available
            auto new_pair = GetNewReusable(_pool.size());
            new_pair.first = false;
            _pool.push_back(new_pair);
            return new_pair.second;
        }

        void ReleaseReusable(Reusable* reusable)
        {
            for (auto& it: _pool)
            {
                if (it.second == reusable)
                {
                    it.first = true;
                    break;
                }
            }
        }

    private:
        std::vector<std::pair<bool, Reusable*>> _pool{}; //bool == isAvailable

        static std::pair<bool, Reusable*> GetNewReusable(size_t id)
        {
            return std::make_pair<bool, Reusable*>(true, new Reusable(id));
        }
    };

#endif
}