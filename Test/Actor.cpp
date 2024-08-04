#include "Actor.h"
#include <iostream>

Actor::Actor(const std::string& name) : Name(name) {
    std::cout << "Actor " << Name << " created." << std::endl;
}

Actor::~Actor() {
    std::cout << "Actor " << Name << " destroyed." << std::endl;
}

const std::string& Actor::GetName() const {
    return Name;
}

void Actor::SetName(const std::string& name) {
    Name = name;
}
