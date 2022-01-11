//
// Created by TriD on 02.10.2021.
//

#include "main_script_context.h"

#include <boost/filesystem.hpp>
#include <boost/optional/optional_io.hpp>

#include "../travel.h"
#include "../world.h"

#include "../ai/actors/agent.h"
#include "../ai/actors/registry.h"
#include "../ai/state_manager.h"

#include "../view/view_facade.h"
#include "../view/widgets/gui_panel.h"

#include "constants.h"
#include "script_functions.h"

#include "api/agent.h"

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
    state["createAgent"] = &createActor;
    state["createSceneObject"] = &createSceneObject;
}

void MainScriptContext::registerClasses() {
    auto& state = getState();

    state.new_usertype<Core::AI::Actors::Agent>("AgentPrivate",
                                                "say", &Core::AI::Actors::Agent::say,
                                                "setName", &Core::AI::Actors::Agent::setName,
                                                "setMaxFood", &Core::AI::Actors::Agent::setMaxFood,
                                                "setMaxWater", &Core::AI::Actors::Agent::setMaxWater,
                                                "setType", &Core::AI::Actors::Agent::setType);

    state.new_usertype<Scripting::API::Agent>("Agent",
                                              "say", &Scripting::API::Agent::say,
                                              "getWater", &Scripting::API::Agent::getWater,
                                              "getPosition", &Scripting::API::Agent::getPosition,
                                              "getFood", &Scripting::API::Agent::getFood,
                                              "getInventory", &Scripting::API::Agent::getInventory,
                                              "getInventoryLimit", &Scripting::API::Agent::getInventoryLimit,
                                              "unloadWood", &Scripting::API::Agent::unloadWood,
                                              "unloadFood", &Scripting::API::Agent::unloadFood,
                                              "hasAction", &Scripting::API::Agent::hasAction,
                                              "addStatus", &Scripting::API::Agent::addStatus,
                                              "move", &Scripting::API::Agent::move,
                                              "doAction", &Scripting::API::Agent::doAction,
                                              "clearState", &Scripting::API::Agent::clearState);

    state.new_usertype<Core::AI::Actors::AgentsRegistry>("AgentsRegistry",
                                                         "createAgent", &Core::AI::Actors::AgentsRegistry::createAgent);

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
                                    "getStoredWood", &Core::World::getWood,
                                    "setAgentLocation", &Core::World::setAgentLocation);
}

void MainScriptContext::registerGlobals() {
    auto& state = getState();
    state["g_actorsRegistry"] = std::ref(_world.getAgentsRegistry());
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