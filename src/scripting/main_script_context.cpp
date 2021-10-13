//
// Created by TriD on 02.10.2021.
//

#include "main_script_context.h"

#include <boost/filesystem.hpp>

#include "../world.h"

#include "../ai/actor.h"
#include "../ai/registry.h"
#include "../ai/state_manager.h"

#include "../view/view_facade.h"
#include "../view/widgets/gui_panel.h"

#include "constants.h"
#include "script_functions.h"

namespace Scripting {

MainScriptContext::MainScriptContext(Core::World& world,
                                     Core::AI::StateManager& stateManager) :
        ScriptContext(),
        _world(world),
        _stateManager(stateManager) {
    getState().open_libraries(sol::lib::base);
    registerFunctions();
    registerClasses();
    registerGlobals();

    registerScriptedStates();
}

void MainScriptContext::registerFunctions() {
    auto& state = getState();
    state["print"] = &print;
    state["setState"] = &setState;
    state["setReaction"] = &setReaction;
    state["createActor"] = &createActor;
    state["createSceneObject"] = &createSceneObject;
}

void MainScriptContext::registerClasses() {
    auto& state = getState();

    state.new_usertype<Core::AI::Actor>("Actor",
                                        "setState", &Core::AI::Actor::setBehaviourStep,
                                        "say", &Core::AI::Actor::say,
                                        "setName", &Core::AI::Actor::setName,
                                        "setPosition", &Core::AI::Actor::setPosition,
                                        "setMaxFood", &Core::AI::Actor::setMaxFood,
                                        "setMaxWater", &Core::AI::Actor::setMaxWater,
                                        "getWater", &Core::AI::Actor::getWater,
                                        "drink", &Core::AI::Actor::drink,
                                        "getPosition", &Core::AI::Actor::getPosition,
                                        "eat", &Core::AI::Actor::eat,
                                        "getFood", &Core::AI::Actor::getFood,
                                        "getInventory", &Core::AI::Actor::getInventory,
                                        "getInventoryLimit", &Core::AI::Actor::getInventoryLimit,
                                        "unloadWood", &Core::AI::Actor::unloadWood,
                                        "unloadFood", &Core::AI::Actor::unloadFood,
                                        "setStateBreackable", &Core::AI::Actor::setStateBreackable,
                                        "hasAction", &Core::AI::Actor::hasAction,
                                        "addStatus", &Core::AI::Actor::addStatus);

    state.new_usertype<Core::AI::ActorsRegistry>("ActorsRegistry",
                                                 "createActor", &Core::AI::ActorsRegistry::createActor);

    state.new_usertype<Core::LocationManager>("LocationManager",
                                              "createLocation", &Core::LocationManager::createLocation);

    state.new_usertype<Core::Message>("Message",
                                      "messageType", &Core::Message::messageType);

    state.new_usertype<Core::AI::StateManager>("StateManager",
                                               "registerBehaviour", &Core::AI::StateManager::registerBehaviour);

    state.new_usertype<Core::Travel>("Travel",
                                           "finished", &Core::Travel::finished);

    state.new_usertype<Core::World>("World",
                                    "moveActor", &Core::World::moveActor,
                                    "doAction", &Core::World::doAction,
                                    "getStoredFood", &Core::World::getFood,
                                    "getStoredWood", &Core::World::getWood);
}

void MainScriptContext::registerGlobals() {
    auto& state = getState();
    state["g_actorsRegistry"] = std::ref(_world.getActorsRegistry());
    state["g_scriptContext"] = std::ref(static_cast<ScriptContext&>(*this));
    state["g_stateManager"] = std::ref(_stateManager);
    state["g_world"] = std::ref(_world);
}

void MainScriptContext::registerScriptedStates() {
    using boost::filesystem::path;
    using boost::filesystem::directory_iterator;
    using boost::filesystem::directory_entry;

    path p(kStateScriptsPath);

    for (auto it = directory_iterator(p); it != directory_iterator(); it++) {
        loadScript(it->path().string());
    }
}

} // namespace Scripting