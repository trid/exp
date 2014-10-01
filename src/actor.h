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
    int steps = 0;
    State* state = nullptr;
    string name;
public:
    void update();
    void eat();
    void drink();

    int getFood() const {
        return food;
    }

    int getWater() const {
        return water;
    }

    int getID() const {
        return id;
    }

    const string& getPosition() const {
        return position;
    }

    void setPosition(const string& position) {
        this->position = position;
    }

    State* getState() {
        return state;
    }

    void setState(State* state);
    void setTargetPosition(const string& position);
    void resetSteps() { steps = 0; }
    void updateSteps() { steps++; }
    const string& getTargetPosition();
    int getSteps();
    void processMessage(Message &message);

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Actor::name = name;
    }
};

#endif