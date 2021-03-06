#ifndef DESIGN_PATTERN_CPP_SINGLETON_H
#define DESIGN_PATTERN_CPP_SINGLETON_H

namespace design_pattern::singleton {

    class Singleton {
    public:
        static Singleton &getSingleton() {
            //lazy initialization
            static Singleton INSTANCE;
            return INSTANCE;
        }

        ~Singleton() = default;

        Singleton(Singleton const &) = delete;

        void operator=(Singleton const &) = delete;

    private:
        Singleton() = default;
    };
}
#endif