#include "action_manager.h"

#include "action_drink.h"
#include "action_eating.h"
#include "action_woodcutting.h"
#include "action_hunting.h"
#include "constants.h"

namespace Core::Actions {

ActionManager::ActionManager(Core::World& world) :
        _world(world) {
    _actionMap[kActionDrink] = std::make_unique<ActionFactory<ActionDrink>>();
    _actionMap[kActionEat] = std::make_unique<ActionFactory<ActionEating>>();
    _actionMap[kActionCutWood] = std::make_unique<ActionFactory<ActionWoodcutting>>();
    _actionMap[kActionHunt] = std::make_unique<ActionFactory<ActionHunting>>();
}

ActionPtr ActionManager::getAction(const std::string& action, AI::Agents::Agent& actor) {
    return ActionPtr(_actionMap[action]->createAction(actor, _world));
}

} // namespace Core::Actions