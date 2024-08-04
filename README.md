# Memory Manager

## Overview

The `MemoryManager` is a custom memory management system designed for efficient dynamic memory allocation and deallocation. This system offers control over memory management with custom allocation and deallocation strategies, making it suitable for various applications.

## Features

- **Custom Allocation**: Manage memory allocation and deallocation with a custom strategy.
- **Deallocation Tracking**: Ensures proper memory reuse and management.
- **Memory Pools**: Supports memory pooling for efficient allocation.

## Getting Started

### Installation

1. **Clone the Repository**

   ```bash
   git clone <repository-url>
   cd <repository-directory>



2. **Build the Project**

   ```bash
    mkdir build
    cd build
    cmake ..
    make



### Usage
1. **Include the Header**

Include MemoryManager.h in your project files:

	```cpp
    #include "MemoryManager.h"


2. **Create an Instance**

Instantiate the MemoryManager object:


	```cpp
    MemoryManager memoryManager;


3. **Allocate Memory**

Request memory allocation:

	```cpp
    void* ptr = memoryManager.allocate(sizeof(int));


4. **Deallocate Memory**

Return memory to the manager:

	```cpp
    memoryManager.deallocate(ptr);


5. **Handle Errors**

Check for null pointers or errors during allocation:

```cpp
if (ptr == nullptr) {
std::cerr << "Memory allocation failed!" << std::endl;
}
```


	
### Example

Here’s a simple usage example:


```cpp
#include "MemoryManager.h"
#include <iostream>

int main() {
MemoryManager memoryManager;

// Allocate memory
int* num = static_cast<int*>(memoryManager.allocate(sizeof(int)));
if (num == nullptr) {
	std::cerr << "Memory allocation failed!" << std::endl;
return 1;
}

// Use allocated memory
*num = 42;
std::cout << "Number: " << *num << std::endl;

// Deallocate memory
memoryManager.deallocate(num);

return 0;
}
```


**Implementation Details**
### Files

- MemoryManager.h: Contains the class declaration and method prototypes.
- MemoryManager.cpp: Implements the memory management logic.

### Design Considerations
- Custom Strategies: Implement different allocation strategies as needed.
- Thread Safety: Ensure the manager is thread-safe if used in multi-threaded environments.

**Extending the Memory Manager**
To extend or modify the MemoryManager:

- Add Allocation Strategies: Update MemoryManager.cpp with new strategies.
- Optimize Performance: Profile and improve the memory management logic.
- Handle Special Cases: Implement additional logic for special scenarios.

**Contribution**
Contributions are welcome! To contribute:

1. **Fork the Library**
2. **Create a Feature Branch**
3. **Commit Your Changes**
4. **Push to the Branch**
5. **Create a Pull Request**

### License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
