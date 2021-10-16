//
// Created by TriD on 02.10.2021.
//

#include "main_script_context.h"

#include <boost/filesystem.hpp>

#include "../world.h"

#include "../ai/actors/actor.h"
#include "../ai/actors/registry.h"
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

    state.new_usertype<Core::AI::Actors::Actor>("Actor",
                                        "setState", &Core::AI::Actors::Actor::setBehaviourStep,
                                        "say", &Core::AI::Actors::Actor::say,
                                        "setName", &Core::AI::Actors::Actor::setName,
                                        "setPosition", &Core::AI::Actors::Actor::setPosition,
                                        "setMaxFood", &Core::AI::Actors::Actor::setMaxFood,
                                        "setMaxWater", &Core::AI::Actors::Actor::setMaxWater,
                                        "getWater", &Core::AI::Actors::Actor::getWater,
                                        "getPosition", &Core::AI::Actors::Actor::getPosition,
                                        "getFood", &Core::AI::Actors::Actor::getFood,
                                        "getInventory", &Core::AI::Actors::Actor::getInventory,
                                        "getInventoryLimit", &Core::AI::Actors::Actor::getInventoryLimit,
                                        "unloadWood", &Core::AI::Actors::Actor::unloadWood,
                                        "unloadFood", &Core::AI::Actors::Actor::unloadFood,
                                        "hasAction", &Core::AI::Actors::Actor::hasAction,
                                        "addStatus", &Core::AI::Actors::Actor::addStatus);

    state.new_usertype<Core::AI::Actors::ActorsRegistry>("ActorsRegistry",
                                                 "createActor", &Core::AI::Actors::ActorsRegistry::createActor);

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