//
// Created by TriD on 02.10.2021.
//

#include "main_script_context.h"

#include <boost/filesystem.hpp>
#include <boost/optional/optional_io.hpp>

#include "../core/location_type.h"
#include "../core/travel.h"
#include "../core/world.h"

#include "../ai/state_manager.h"

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
    state["createSceneObject"] = &createSceneObject;
}

void MainScriptContext::registerClasses() {
    auto& state = getState();

    state.new_usertype<Core::AI::Agents::Agent>("AgentPrivate",
                                                "say", &Core::AI::Agents::Agent::say,
                                                "setName", &Core::AI::Agents::Agent::setName,
                                                "setMaxFood", &Core::AI::Agents::Agent::setMaxFood,
                                                "setMaxWater", &Core::AI::Agents::Agent::setMaxWater,
                                                "setType", &Core::AI::Agents::Agent::setType);

    state.new_usertype<Scripting::API::Agent>("Agent",
                                              "say", &Scripting::API::Agent::say,
                                              "getWater", &Scripting::API::Agent::getWater,
                                              "getPosition", &Scripting::API::Agent::getPosition,
                                              "getFood", &Scripting::API::Agent::getFood,
                                              "getInventory", &Scripting::API::Agent::getInventory,
                                              "getInventoryLimit", &Scripting::API::Agent::getInventoryLimit,
                                              "unloadResource", &Scripting::API::Agent::unloadResource,
                                              "hasAction", &Scripting::API::Agent::hasAction,
                                              "addStatus", &Scripting::API::Agent::addStatus,
                                              "move", &Scripting::API::Agent::move,
                                              "doAction", &Scripting::API::Agent::doAction,
                                              "clearState", &Scripting::API::Agent::clearState);

    state.new_usertype<Core::AI::Agents::AgentsRegistry>("AgentsRegistry",
                                                         "createAgent", &Core::AI::Agents::AgentsRegistry::createAgent);

    state.new_usertype<Core::AI::StateManager>("StateManager",
                                               "registerBehaviour", &Core::AI::StateManager::registerBehaviour);

    state.new_usertype<Core::Travel>("Travel",
                                           "finished", &Core::Travel::finished);

    state.new_usertype<Core::World>("World",
                                    "moveActor", &Core::World::moveActor,
                                    "doAction", &Core::World::doAction,
                                    "getStoredResource", &Core::World::getResourceCount,
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