#include "MemoryManager.h"
#include "Allocator.cpp"
#include "PoolAllocator.h"

/**
 * @class MemoryManager
 * @brief A class responsible for managing memory allocation and deallocation.
 */
MemoryManager::MemoryManager()
    : defaultAllocator(new DefaultAllocator()),
      poolAllocator(new PoolAllocator(1024, 100)) // Example: 100 blocks of 1KB each
{}

/**
 * @class MemoryManager
 * @brief Manages memory allocation and deallocation.
 *
 * The MemoryManager class provides functionality for allocating and deallocating memory using different allocators.
 * It is a singleton class with a static method to get the instance.
 */
MemoryManager::~MemoryManager() {
    delete defaultAllocator;
    delete poolAllocator;
}

/**
 * @brief Get the instance of the MemoryManager class.
 *
 * This method returns the instance of the MemoryManager class. MemoryManager is implemented
 * as a singleton, so only one instance can exist, and it can be accessed globally by calling
 * this method.
 *
 * @return The instance of the MemoryManager class.
 */
MemoryManager& MemoryManager::getInstance() {
    static MemoryManager instance;
    return instance;
}

/**
 * @brief Allocates a block of memory of the given size from the default allocator.
 *
 * @param size The size of the memory block to allocate, in bytes.
 *
 * @return A pointer to the allocated memory block, or nullptr if the allocation fails.
 */
void* MemoryManager::allocate(size_t size) {
    return defaultAllocator->allocate(size);
}

/**
 * @brief Deallocates the memory pointed to by ptr.
 *
 * The deallocate method is used to release the memory previously allocated by the allocate method.
 *
 * @param ptr A pointer to the memory to be deallocated.
 */
void MemoryManager::deallocate(void* ptr) {
    defaultAllocator->deallocate(ptr);
}

/**
 * @brief Allocates a block of memory from the pool allocator with the specified size.
 *
 * @param size The size of the memory block to allocate.
 * @return The pointer to the allocated memory block.
 */
void* MemoryManager::allocatePool(size_t size) {
    return poolAllocator->allocate(size);
}

/**
 * @brief Deallocates a memory block from the pool allocator.
 *
 * This function is used to deallocate a memory block that was previously allocated
 * using the allocatePool() function. It calls the deallocate() function of the
 * pool allocator to deallocate the memory block.
 *
 * @param ptr A pointer to the memory block to deallocate.
 */
void MemoryManager::deallocatePool(void* ptr) {
    poolAllocator->deallocate(ptr);
}