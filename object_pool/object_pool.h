#ifndef DESIGN_PATTERN_CPP_OBJECT_POOL_H
#define DESIGN_PATTERN_CPP_OBJECT_POOL_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>

namespace design_pattern::object_pool {

    class Reusable {
    public:
        explicit Reusable(size_t id) : id_(id) {}

        ~Reusable() = default;

        [[nodiscard]] size_t GetID() const {
            return id_;
        }

        bool operator==(const Reusable &other) const {
            return id_ == other.GetID();
        }

    private:
        const size_t id_;
    };

    class ReusablePool {
    public:
        explicit ReusablePool(size_t pool_start_size) {
            for (size_t i = 0U; i < pool_start_size; ++i) {
                pool_.push_back(GetNewReusable(i));
            }
        }

        ~ReusablePool() = default;

        std::shared_ptr<Reusable> GetReusable() {
            //check if there is any available reusable
            for (auto &it: pool_) {
                if (it.first) {
                    it.first = false;
                    return it.second;
                }
            }
            //if none available
            auto new_pair = GetNewReusable(pool_.size());
            new_pair.first = false;
            pool_.push_back(new_pair);
            return new_pair.second;
        }

        void ReleaseReusable(Reusable &reusable) {
            for (auto &it: pool_) {
                if (*it.second == reusable) {
                    it.first = true;
                    return;
                }
            }
        }

    private:
        std::vector<std::pair<bool, std::shared_ptr<Reusable >>> pool_{}; //bool == isAvailable

        static std::pair<bool, std::shared_ptr<Reusable >> GetNewReusable(size_t id) {
            return {true, std::make_shared<Reusable>(id)};
        }
    };

#endif
}