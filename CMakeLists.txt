cmake_minimum_required(VERSION 3.28)
project(MemoryManager)

set(CMAKE_CXX_STANDARD 17)

# Define the shared library
add_library(MemoryManager SHARED
        src/MemoryManager.cpp
        src/Allocator.cpp
        src/PoolAllocator.cpp
)

target_include_directories(MemoryManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (WIN32)
    target_compile_definitions(MemoryManager PRIVATE MEMORY_MANAGER_EXPORTS)
endif()

# Define the test executable
add_executable(TestMemoryManager Test/main.cpp test/Level.cpp test/Actor.cpp)
target_link_libraries(TestMemoryManager PRIVATE MemoryManager)
target_include_directories(TestMemoryManager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)