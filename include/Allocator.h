// Copyright B Engine by Datanet Group Corporation. All Rights Reserved

#include <cstddef> // Include the necessary header for size_t

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

/**
 * @brief Virtual destructor.
 *
 * The destructor of the Allocator class.
 */
class Allocator {
 /**
  * @class Allocator
  * @brief The Allocator class is an abstract class that provides an interface
  * for allocating and deallocating memory.
  *
  * The Allocator class defines a virtual destructor and two pure virtual
  * functions, `allocate()` and `deallocate()`. Concrete classes derived from
  * Allocator must implement these functions to provide memory allocation and
  * deallocation functionality.
  */
public:
    virtual ~Allocator() = default;

 /**
  * @brief Allocates a block of memory of given size.
  *
  * This method is a pure virtual method declared in the `Allocator` class. It is meant to be overridden by derived classes to implement memory allocation.
  *
  * @param size The size of the memory block to allocate.
  *
  * @return A void pointer to the allocated memory block.
  */
 virtual void* allocate(size_t size) = 0;

 /**
  * @brief Deallocates a previously allocated memory block.
  *
  * This method is used to deallocate a memory block that was previously allocated
  * using the allocate method.
  *
  * @param ptr A pointer to the memory block to deallocate.
  *
  * @note The behavior is undefined if the pointer was not previously allocated by the allocator.
  *
  * @see allocate
  */
 virtual void deallocate(void* ptr) = 0;
};

#endif // ALLOCATOR_H