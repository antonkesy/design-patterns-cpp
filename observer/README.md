# Observer

## Intent

One-to-many dependency between objects so that when the objects change, all dependents are notified.

## When to use

- abstract objects depend on each other
- changing one object should also change an unknown amount of objects
- objects need to notify other objects without specifically know them