#include <iostream>

#include "lua.hpp"
#include "actor.h"
#include "view.h"

using namespace std;

int print(lua_State* state) {
    char const *str = lua_tostring(state, 1);
    cout << "LUA: " << str;
    return 0;
}

void lua_test() {
    lua_State* state = luaL_newstate();
    lua_register(state, "print", print);
    int ret = luaL_dofile(state, "scripts/hello.lua");
    if (state) lua_close(state);
}

enum Position {
    POSITION_NONE,
    POSITION_HOME,
    POSITION_FOREST,
    POSITION_WATER
};

enum State {
    STATE_NONE,
    STATE_IN_ROUTE,
    STATE_WOODCUTTING,
    STATE_THIRSTY,
    STATE_DRINKING,
    STATE_FINISHED
};

int ticksToForest = 3;
int ticksToWater = 5;
Position currentPosition = POSITION_HOME;
Position targetPosition = POSITION_NONE;
int wood = 0;
int neededWood = 300;
int wayPassed = 0;
State state = STATE_NONE;

Actor actor;

int process() {
    cout << "Place: " << currentPosition << endl;
    cout << "Wood: " << wood << endl;
    cout << "Thisrty: " << actor.getWater() << endl;

    switch (state) {
        case STATE_NONE:
            state = STATE_IN_ROUTE;
            targetPosition = POSITION_FOREST;
            break;
        case STATE_IN_ROUTE:
            wayPassed++;
            switch (currentPosition) {
                case POSITION_HOME:
                    if (targetPosition == POSITION_FOREST && wayPassed == ticksToForest) {
                        state = STATE_WOODCUTTING;
                        currentPosition = POSITION_FOREST;
                        wayPassed = 0;
                    }
                    else if (targetPosition == POSITION_WATER && wayPassed == ticksToWater) {
                        state = STATE_DRINKING;
                        currentPosition = POSITION_WATER;
                        wayPassed = 0;
                    }
                    break;
                case POSITION_FOREST:
                    if (wayPassed == ticksToForest) {
                        currentPosition = POSITION_HOME;
                        targetPosition = POSITION_WATER;
                        wayPassed = 0;
                    }
                    break;
                case POSITION_WATER:
                    if (wayPassed == ticksToWater) {
                        currentPosition = POSITION_HOME;
                        targetPosition = POSITION_FOREST;
                        wayPassed = 0;
                    }
                default: break;
            }
            break;
        case STATE_WOODCUTTING:
            wood++;
            if (actor.getWater() == 0) {
                state = STATE_THIRSTY;
            }
            if (wood == neededWood) {
                state = STATE_FINISHED;
            }
            break;
        case STATE_THIRSTY:
            targetPosition = POSITION_HOME;
            state = STATE_IN_ROUTE;
            wayPassed = 0;
            break;
        case STATE_DRINKING:
            actor.drink();
            state = STATE_IN_ROUTE;
            targetPosition = POSITION_HOME;
            wayPassed = 0;
            break;
        case STATE_FINISHED:
            return 1;
    }

    actor.update();

    return 0;
}

int main(int argc, char* argv[]) {
    View& view = View::getView();
    while (process() == 0) {
        view.draw();
    }
    return 0;
}