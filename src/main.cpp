#include <iostream>

#include "lua.hpp"
#include "actor.h"
#include "view.h"
#include "registry.h"
#include "world.h"
#include "state_manager.h"

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

int ticksToForest = 3;
int ticksToWater = 5;
Position targetPosition = POSITION_NONE;
int wood = 0;
int neededWood = 300;
int wayPassed = 0;

Actor& woodCutter = ActorsRegistry::getRegistry().createActor();
Actor& hunter = ActorsRegistry::getRegistry().createActor();

int process() {
    cout << "Place: " << woodCutter.getPosition() << endl;
    cout << "Wood: " << World::getWorld().getWood() << endl;
    cout << "Thisrty: " << woodCutter.getWater() << endl;

    return 0;
}

int main(int argc, char* argv[]) {
    View& view = View::getView();
    World& world = World::getWorld();
    ActorsRegistry &registry = ActorsRegistry::getRegistry();
    StateManager& stateManager = StateManager::getInstance();
    woodCutter.setState(StateManager::getInstance().getState("StateStart"));

    while (process() == 0) {
        registry.update();
        world.update();
        view.draw();
        SDL_Delay(100);
    }
    return 0;
}