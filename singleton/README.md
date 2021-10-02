# Singleton

## Intent

There can be only one!

## When to use

When you need to ensure that there is always only one and the same instance of a class.

## Implementation tricks

### Lazy Initializing

There is no need to keep a private static member variable to hold the instance with lazy initializing.

```c++
static Singleton& getSingleton()
{
    //lazy initialization
    static Singleton INSTANCE;
    return INSTANCE;
}
```
