#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Actor.h"

class Level {
public:
    Level(const std::string& name);
    ~Level();

    const std::string& GetName() const;
    void AddActor(Actor* actor);
    void RemoveActor(Actor* actor);
    const std::vector<Actor*>& GetActors() const;

private:
    std::string Name;
    std::vector<Actor*> Actors;
};

#endif // LEVEL_H