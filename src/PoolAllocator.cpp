#include "PoolAllocator.h"
#include <cassert>
#include <cstring>

/**
 * @brief Constructs a PoolAllocator object with the given block size and block count.
 *
 * @param blockSize The size of each block in bytes.
 * @param blockCount The number of blocks that can be allocated.
 */
PoolAllocator::PoolAllocator(size_t blockSize, size_t blockCount)
    : blockSize(blockSize), blockCount(blockCount) {
    pool = std::malloc(blockSize * blockCount);
    for (size_t i = 0; i < blockCount; ++i) {
        freeBlocks.push_back(static_cast<char*>(pool) + i * blockSize);
    }
}

/**
 * @class PoolAllocator
 * @brief A pool allocator that manages memory blocks of fixed size in a pre-allocated pool
 * @inherits Allocator
 */
PoolAllocator::~PoolAllocator() {
    std::free(pool);
}

/**
 * @brief Allocates a block of memory from the pool.
 *
 * This method allocates a block of memory from the pool allocator. The size of the block must be less than or equal to the block size specified during construction.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block, or nullptr if the pool is exhausted.
 */
void* PoolAllocator::allocate(size_t size) {
    assert(size <= blockSize && "Requested size exceeds block size");
    if (freeBlocks.empty()) {
        return nullptr; // Pool exhausted
    }
    void* ptr = freeBlocks.back();
    freeBlocks.pop_back();
    return ptr;
}

/**
 * @brief Deallocates a previously allocated block of memory.
 *
 * This method adds the provided pointer to the list of free blocks.
 *
 * @param ptr A pointer to the block of memory to deallocate.
 */
void PoolAllocator::deallocate(void* ptr) {
    freeBlocks.push_back(ptr);
}