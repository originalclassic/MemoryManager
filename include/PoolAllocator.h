#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include "Allocator.h"
#include <vector>

/**
 * @brief Construct a new Pool Allocator object
 *
 * @param blockSize The size of each memory block in bytes
 * @param blockCount The number of memory blocks to allocate
 */
class PoolAllocator : public Allocator {
 /**
  * @brief Constructs a PoolAllocator object.
  *
  * The PoolAllocator class provides a pool-based memory allocator, which allocates fixed-size blocks of memory.
  *
  * @param blockSize The size of each memory block, in bytes.
  * @param blockCount The number of memory blocks in the pool.
  */
public:
    PoolAllocator(size_t blockSize, size_t blockCount);

 /**
  * @class PoolAllocator
  * @brief A memory allocator that allocates fixed-size blocks from a pre-allocated pool.
  *
  * The PoolAllocator class provides a way to efficiently allocate fixed-size blocks of memory from a pre-allocated pool.
  * It is a subclass of the Allocator base class and implements its allocate and deallocate methods.
  *
  * @note The PoolAllocator requires an initialization step before it can be used.
  *       This is done by calling the PoolAllocator constructor with the desired block size and block count.
  *
  * Example usage:
  * @code{.cpp}
  * PoolAllocator allocator(64, 1000);
  * void* ptr = allocator.allocate(64);
  * // use the allocated memory...
  * allocator.deallocate(ptr);
  * @endcode
  */
 ~PoolAllocator();

 /**
  * @brief Allocates a block of memory from the pool allocator.
  * @param size The size of the memory block to allocate.
  * @return A pointer to the allocated memory block, or nullptr if the pool is exhausted.
  */
 void* allocate(size_t size) override;

 /**
  * @brief Deallocates a previously allocated memory block.
  *
  * @param ptr The pointer to the memory block to deallocate.
  * @return void
  */
 void deallocate(void* ptr) override;

 /**
  * @brief The size of each memory block in the pool.
  *
  * The `blockSize` variable represents the size of each memory block in the pool. It is used by the `PoolAllocator` class to determine the size of memory blocks to allocate and deallocate.
  *
  * @details The `blockSize` value is set during the initialization of the `PoolAllocator` object. It should be a positive integer that represents the number of bytes in each memory block.
  *
  * @note The `blockSize` value must be greater than zero.
  */
private:
    size_t blockSize;
 /**
  * @var blockCount
  * The number of blocks in the PoolAllocator.
  *
  * This variable represents the number of blocks present in the PoolAllocator.
  * Each block is of size blockSize, and the total number of blocks can be
  * calculated by dividing the total allocated memory (blockSize * blockCount)
  * by the size of each block.
  *
  * @see PoolAllocator
  */
 size_t blockCount;
 /**
  * @brief A vector that holds pointers to free memory blocks.
  *
  * This vector stores pointers to free memory blocks that can be used for allocation.
  * It is used in the PoolAllocator class to manage the memory pool.
  */
 std::vector<void*> freeBlocks;
 /**
  * @brief Pointer to the memory pool used by the PoolAllocator class.
  *
  * This variable stores the starting address of the memory pool
  * managed by the PoolAllocator class. The memory pool is a block
  * of memory used for allocating and deallocating smaller blocks.
  *
  * @note This variable is defined in the PoolAllocator class.
  */
 void* pool;
};

#endif // POOL_ALLOCATOR_H