#include <iostream>

#include "lua.hpp"
#include "actor.h"
#include "view.h"
#include "registry.h"

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
Position targetPosition = POSITION_NONE;
int wood = 0;
int neededWood = 300;
int wayPassed = 0;
State state = STATE_NONE;

Actor& actor = ActorsRegistry::getRegistry().createActor();

int process() {
    cout << "Place: " << actor.getPosition() << endl;
    cout << "Wood: " << wood << endl;
    cout << "Thisrty: " << actor.getWater() << endl;
    if (state == STATE_IN_ROUTE) {
        cout << "Passed: " << wayPassed << endl;
    }

    switch (state) {
        case STATE_NONE:
            state = STATE_IN_ROUTE;
            targetPosition = POSITION_FOREST;
            cout << "WTF?!" << endl;
            break;
        case STATE_IN_ROUTE:
            wayPassed++;
            cout << "In route" << endl;
            switch (actor.getPosition()) {
                case POSITION_HOME:
                    if (targetPosition == POSITION_FOREST && wayPassed == ticksToForest) {
                        cout << "Aaaah! Back to the forest!" << endl;
                        state = STATE_WOODCUTTING;
                        actor.setPosition(POSITION_FOREST);
                        wayPassed = 0;
                    }
                    else if (targetPosition == POSITION_WATER && wayPassed == ticksToWater) {
                        cout << "Oh well, it's well!" << endl;
                        state = STATE_DRINKING;
                        actor.setPosition(POSITION_WATER);
                        wayPassed = 0;
                    }
                    break;
                case POSITION_FOREST:
                    cout << "In forest, going home\n";
                    if (wayPassed == ticksToForest) {
                        actor.setPosition(POSITION_HOME);
                        targetPosition = POSITION_WATER;
                        wayPassed = 0;
                    }
                    break;
                case POSITION_WATER:
                    cout << "Near well, going home\n";
                    if (wayPassed == ticksToWater) {
                        actor.setPosition(POSITION_HOME);
                        targetPosition = POSITION_FOREST;
                        wayPassed = 0;
                    }
                default: break;
            }
            break;
        case STATE_WOODCUTTING:
            cout << "Cutting wood! I love wood! My wife is wood too!\n";
            wood++;
            if (actor.getWater() == 0) {
                state = STATE_THIRSTY;
            }
            if (wood == neededWood) {
                state = STATE_FINISHED;
            }
            break;
        case STATE_THIRSTY:
            cout << "I'm thirsty. Going drink something\n";
            targetPosition = POSITION_HOME;
            state = STATE_IN_ROUTE;
            wayPassed = 0;
            break;
        case STATE_DRINKING:
            cout << "Drinking. Hope here will be something except water.\n";
            actor.drink();
            state = STATE_IN_ROUTE;
            targetPosition = POSITION_HOME;
            wayPassed = 0;
            break;
        case STATE_FINISHED:
            cout << "Finished work. Fucking paty.\n";
            return 1;
    }

    actor.update();

    return 0;
}

int main(int argc, char* argv[]) {
    View& view = View::getView();
    while (process() == 0) {
        view.draw();
        SDL_Delay(100);
    }
    return 0;
}