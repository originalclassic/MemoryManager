#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "MemoryManager.h"
#include "Level.h"
#include "Actor.h"

int main() {
    // Initialize the memory manager
    MemoryManager& MemManager = MemoryManager::getInstance();

    // Random number generator for testing
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Test parameters
    const std::size_t NumLevels = 5;
    const std::size_t NumActorsPerLevel = 20;
    const std::size_t PoolAllocSize = sizeof(Actor);

    // Create levels
    std::vector<Level*> Levels;
    for (std::size_t i = 0; i < NumLevels; ++i) {
        std::string LevelName = "Level_" + std::to_string(i + 1);
        Level* level = new Level(LevelName);
        Levels.push_back(level);
    }

    // Spawn actors
    for (Level* level : Levels) {
        for (std::size_t j = 0; j < NumActorsPerLevel; ++j) {
            std::string ActorName = "Actor_" + std::to_string(j + 1) + "_" + level->GetName();
            void* ptr = MemManager.allocatePool(PoolAllocSize);
            Actor* actor = new (ptr) Actor(ActorName); // Placement new
            level->AddActor(actor);
        }
    }

    // Perform random deallocations
    for (Level* level : Levels) {
        std::vector<Actor*>& actors = const_cast<std::vector<Actor*>&>(level->GetActors());
        std::size_t initialSize = actors.size();
        for (std::size_t j = 0; j < initialSize / 2; ++j) {
            if (!actors.empty()) {
                Actor* actor = actors.back();
                level->RemoveActor(actor);
                actor->~Actor();
                MemManager.deallocatePool(actor);
            }
        }
    }

    // Clean up levels and remaining actors
    for (Level* level : Levels) {
        std::vector<Actor*>& actors = const_cast<std::vector<Actor*>&>(level->GetActors());
        for (Actor* actor : actors) {
            actor->~Actor();
            MemManager.deallocatePool(actor);
        }
        delete level;
    }

    return 0;
}
