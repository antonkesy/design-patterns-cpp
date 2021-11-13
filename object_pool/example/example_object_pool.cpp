#include "../object_pool.h"

namespace design_pattern::object_pool
{
#define EXAMPLE_POOL_START_SIZE 3

    void PrintArrayContent(Reusable* arr[], size_t len)
    {
        for (size_t i = 0U; i < len; ++i)
        {
            std::cout << arr[i]->GetID() << std::endl;
        }
        std::cout << std::endl;
    }

    int example_usage()
    {
        ReusablePool pool(EXAMPLE_POOL_START_SIZE);

        Reusable* obj[EXAMPLE_POOL_START_SIZE + 1];

        for (int i = 0; i < EXAMPLE_POOL_START_SIZE; ++i)
        {
            obj[i] = pool.GetReusable();
        }
        PrintArrayContent(obj, EXAMPLE_POOL_START_SIZE);

        //release middle object
        pool.ReleaseReusable(obj[1]);

        //reuse released object in other place
        obj[EXAMPLE_POOL_START_SIZE] = pool.GetReusable();

        //force creating new object
        obj[1] = pool.GetReusable();

        PrintArrayContent(obj, EXAMPLE_POOL_START_SIZE + 1);
        return 0;
    }

}

int main()
{
    return design_pattern::object_pool::example_usage();
}


