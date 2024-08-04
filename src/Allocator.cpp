#include "Allocator.h"
#include <cstdlib>

/**
 * @class DefaultAllocator
 * @brief A default implementation of the Allocator interface.
 *
 * This class provides a basic allocator that uses std::malloc and std::free
 * functions to allocate and deallocate memory.
 *
 * @note For more advanced memory management, consider implementing a custom allocator.
 */
class DefaultAllocator : public Allocator {
    /**
     * @brief Allocates a block of memory with the specified size.
     *
     * @param size The size of the memory block to allocate.
     * @return A pointer to the allocated memory block.
     */
public:
    void* allocate(size_t size) override {
        return std::malloc(size);
    }

    /**
     * @brief Deallocates the memory pointed to by \p ptr.
     *
     * The deallocate method frees the memory block pointed to by the \p ptr parameter,
     * which was previously allocated by the allocate method of the Allocator class.
     *
     * @param ptr A pointer to the memory block to deallocate.
     * @return None.
     */
    void deallocate(void* ptr) override {
        std::free(ptr);
    }
};
