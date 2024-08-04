#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "Allocator.h"

#ifdef MEMORY_MANAGER_EXPORTS
#define MEMORY_MANAGER_API __declspec(dllexport)
#else
#define MEMORY_MANAGER_API __declspec(dllimport)
#endif

/**
 * @class MemoryManager
 * @brief The MemoryManager class is responsible for managing memory allocation and deallocation.
 */
class MEMORY_MANAGER_API MemoryManager {
 /**
  * @brief Returns the instance of the MemoryManager.
  *
  * The getInstance method returns a reference to the singleton instance of the MemoryManager class.
  * If an instance does not exist, it creates a new one and returns it.
  *
  * @return A reference to the MemoryManager instance.
  */
public:
    static MemoryManager& getInstance();

 /**
  * @brief Allocates a block of memory of the specified size.
  *
  * @param size the size of the memory block to allocate
  * @return a pointer to the allocated memory block
  */
 void* allocate(size_t size);

 /**
  * @brief Deallocates the memory pointed to by the given pointer.
  *
  * @param ptr A pointer to the memory to deallocate.
  *
  * @return None.
  */
 void deallocate(void* ptr);

 /**
  * @brief Allocates a memory pool of the specified size using the pool allocator.
  *
  * @param size The desired size of the memory pool.
  * @return A pointer to the allocated memory pool.
  */
 void* allocatePool(size_t size);

 /**
  * @brief Deallocates a memory block from the pool.
  *
  * This method deallocates the memory block pointed to by the given pointer from the pool.
  * The memory block is returned to the pool for reuse.
  *
  * @param ptr The pointer to the memory block to deallocate.
  */
 void deallocatePool(void* ptr);

 /**
  * @brief Constructs a MemoryManager object.
  *
  * The MemoryManager class manages memory by using different allocators.
  * This constructor initializes the defaultAllocator and poolAllocator members with their respective allocator objects.
  *
  * @return None.
  */
private:
    MemoryManager();

 /**
  * @brief Destructor for the MemoryManager class.
  * This destructor deletes the defaultAllocator and poolAllocator objects.
  */
 ~MemoryManager();

 /**
  * @class MemoryManager
  * @brief Manages memory allocation and deallocation.
  */
 MemoryManager(const MemoryManager&) = delete;

 /**
  * @brief Assignment operator is deleted. Cannot assign one MemoryManager object to another.
  *
  * @param other The other MemoryManager object to assign
  * @return MemoryManager& The reference to this MemoryManager object
  */
 MemoryManager& operator=(const MemoryManager&) = delete;

 /**
  * @brief The defaultAllocator variable.
  *
  * The defaultAllocator variable is a pointer to an Allocator object. It is used in the MemoryManager class to manage memory allocation and deallocation.
  *
  * @see MemoryManager class documentation for more information.
  */
 Allocator* defaultAllocator;
 /**
  * @class poolAllocator
  * @brief Allocator for managing memory pools.
  *
  * The poolAllocator class is responsible for allocating and deallocating memory blocks from a memory pool.
  * It is used by the MemoryManager class to allocate and deallocate memory when requested by the application.
  */
 Allocator* poolAllocator;
};

#endif // MEMORY_MANAGER_H