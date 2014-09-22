#ifndef ACTOR_H
#define ACTOR_H

#include "state.h"

enum Position {
    POSITION_NONE,
    POSITION_HOME,
    POSITION_FOREST,
    POSITION_WATER
};

/*enum State {
    STATE_NONE,
    STATE_IN_ROUTE,
    STATE_WOODCUTTING,
    STATE_THIRSTY,
    STATE_DRINKING,
    STATE_FINISHED
};*/

class State;

class Actor {
    friend class Registry;
private:
    int id;
    int food = 90;
    int water = 60;

    Position position = POSITION_HOME;
    Position target = POSITION_NONE;
    int steps = 0;
    State* state = nullptr;
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

    Position getPosition() const {
        return position;
    }

    void setPosition(Position position) {
        this->position = position;
    }

    State* getState() {
        return state;
    }

    void setState(State* state);
    void setTargetPosition(Position position);
    void resetSteps() { steps = 0; }
    void updateSteps() { steps++; }
    Position getTargetPosition();
    int getSteps();
};

#endif