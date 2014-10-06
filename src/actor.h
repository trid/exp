#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "message_manager.h"

class State;

using std::string;

enum Position {
    POSITION_NONE,
    POSITION_HOME,
    POSITION_FOREST,
    POSITION_WATER
};

class Actor {
    friend class ActorsRegistry;
private:
    int id;
    int food = 90;
    int water = 60;

    string position = "";
    string target = "";
    State* state = nullptr;
    string name;
    int inventory = 0;
    int inventoryLimit = 20;
public:
    void update();
    void eat();
    void drink();

    int getFood() const { return food; }
    int getWater() const { return water; }
    int getID() const { return id; }
    const string& getPosition() const { return position; }
    void setPosition(const string& position) { this->position = position; }
    State* getState() { return state; }
    void setState(State* state);
    void setTargetPosition(const string& position);
    const string& getTargetPosition();
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Actor::name = name;
    }

    int getInventory() const {
        return inventory;
    }

    void setInventory(int inventory) {
        Actor::inventory = inventory;
    }

    void say(const string &message);
    void processMessage(Message &message);
    void addItem();
    void unloadWood();
    void unloadFood();

    int getInventoryLimit();
};

#endif