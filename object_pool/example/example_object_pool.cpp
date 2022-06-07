#include "../object_pool.h"

int main() {
    using design_pattern::object_pool::Reusable;
    using design_pattern::object_pool::ReusablePool;

    const auto pool_start_size = 3;
    ReusablePool pool(pool_start_size);

    std::array<std::shared_ptr<Reusable>, pool_start_size + 1> obj{};

    for (int i = 0; i < pool_start_size; ++i) {
        obj[i] = pool.GetReusable();
    }

    auto print_array = [&] {
        for (const auto &item: obj)
            std::cout << item->GetID() << "\n";
    };

    //release middle object
    pool.ReleaseReusable(*obj[1]);

    //reuse released object in other place
    obj[pool_start_size] = pool.GetReusable();

    //force creating new object
    obj[1] = pool.GetReusable();

    print_array();

    return 0;
}