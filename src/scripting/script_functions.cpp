#include "script_functions.h"

#include <iostream>

#include "lua.hpp"

#include "../constants.h"
#include "../location_manager.h"
#include "../world.h"

#include "../ai/actor_object.h"
#include "../ai/state_manager.h"
#include "../ai/registry.h"

#include "../view/scene_object_manager.h"
#include "../view/view_facade.h"

#include "constants.h"
#include "script_object_manager.h"


View::ViewFacade* g_view = nullptr;
View::SceneObjectManager* g_sceneObjectManager = nullptr;
extern Core::World* g_world;
View::Widgets::GUIPanel* g_panel;

namespace Scripting {

void print(const std::string& message) {
    std::cout << kScriptMessagePrefix << message;
}

void setState(Core::AI::Actor& actor, const std::string& stateName, Core::AI::StateManager& stateManager) {
    if (stateName.empty()) {
        actor.setState(boost::none);
    } else {
        auto actorState = stateManager.getState(stateName);
        actor.setState(actorState);
    }
}

void setReaction(Core::AI::Actor& actor, const std::string& reactionType, const std::string& stateName, Core::AI::StateManager& stateManager) {
    actor.setReactor(reactionType, stateManager.getState(stateName));
}

//Actor registry
Core::AI::Actor& createActor(Core::AI::ActorsRegistry& actorsRegistry) {
    return actorsRegistry.createActor(*g_view, *g_world, *g_panel);
}

//Scene objects
void createSceneObject(const std::string& type, const std::string& name, int x, int y) {
    g_world->getLocationManager().createLocation(type, name, x, y, *g_sceneObjectManager);
}

} // namespace Scripting