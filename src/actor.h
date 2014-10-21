#ifndef ACTOR_H
#define ACTOR_H

#include <set>
#include <string>
#include <unordered_map>
#include "message_manager.h"

using std::set;
using std::string;
using std::unordered_map;

class State;

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
    //Pixels per second
    double speed = 120;
    //Actor position
    double x, y;
    bool stateBreackable = true;
    string executingState;
    set <string> globalStates;
    unordered_map <string, State*> globalStateReactors;
public:
    void update();
    void eat();
    void drink();

    int getFood() const { return food; }
    int getWater() const { return water; }
    int getID() const { return id; }
    const string& getPosition() const { return position; }
    void setPosition(const string& position);
    State* getState() { return state; }
    void setState(State* state);
    void setTargetPosition(const string& position);
    const string& getTargetPosition();
    const string &getName() const { return name; }
    void setName(const string &name) { Actor::name = name; }
    int getInventory() const { return inventory; }
    void setInventory(int inventory) { Actor::inventory = inventory; }

    void say(const string &message);
    void processMessage(Message &message);
    void addItem();
    void unloadWood();
    void unloadFood();

    int getInventoryLimit();

    int updatePosition(double dx, double dy) { x += dx; y += dy; }
    int getX() const { return x; }
    void setX(int x) { Actor::x = x; }
    int getY() const { return y; }
    void setY(int y) { Actor::y = y; }
    double getSpeed() { return speed; }
    bool isStateBreackable() const { return stateBreackable; }
    void setStateBreackable(bool stateBreackable) { Actor::stateBreackable = stateBreackable; }
    void addGlobalState(const string& stateName);
    void setReactor(const string& stateName, State* reactionState);

    void removeGlobalState(string const &stateName);
};

#endif