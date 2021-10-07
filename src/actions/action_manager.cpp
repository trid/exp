#include "action_manager.h"
#include "action_drink.h"
#include "action_eating.h"
#include "action_woodcutting.h"
#include "action_hunting.h"

#include "constants.h"

namespace Core::Actions {

ActionManager::ActionManager(Core::World& world) :
        _world(world) {
    _actionMap[kActionDrink] = new ActionFactory<ActionDrink>;
    _actionMap[kActionEat] = new ActionFactory<ActionEating>;
    _actionMap[kActionCutWood] = new ActionFactory<ActionWoodcutting>;
    _actionMap[kActionHunt] = new ActionFactory<ActionHunting>;
}

ActionManager::~ActionManager() {
    for (auto item: _actionMap) {
        delete item.second;
    }
}

ActionPtr ActionManager::getAction(const std::string& action, Actor* actor) {
    return ActionPtr(_actionMap[action]->createAction(actor, _world));
}

} // namespace Core::Actions