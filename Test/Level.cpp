#include "Level.h"
#include <algorithm>
#include <iostream>

Level::Level(const std::string& name) : Name(name) {
    std::cout << "Level " << Name << " created." << std::endl;
}

Level::~Level() {
    std::cout << "Level " << Name << " destroyed." << std::endl;
    for (Actor* actor : Actors) {
        std::cout << "Deleting actor " << actor->GetName() << " from level " << Name << std::endl;
        delete actor;
    }
}

const std::string& Level::GetName() const {
    return Name;
}

void Level::AddActor(Actor* actor) {
    Actors.push_back(actor);
    std::cout << "Actor " << actor->GetName() << " added to Level " << Name << "." << std::endl;
}

void Level::RemoveActor(Actor* actor) {
    auto it = std::find(Actors.begin(), Actors.end(), actor);
    if (it != Actors.end()) {
        std::cout << "Actor " << actor->GetName() << " removed from Level " << Name << "." << std::endl;
        Actors.erase(it);
    }
}

const std::vector<Actor*>& Level::GetActors() const {
    return Actors;
}
