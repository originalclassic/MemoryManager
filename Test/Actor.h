#ifndef ACTOR_H
#define ACTOR_H

#include <string>

class Actor {
public:
    Actor(const std::string& name);
    ~Actor();

    const std::string& GetName() const;
    void SetName(const std::string& name);

private:
    std::string Name;
};

#endif // ACTOR_H