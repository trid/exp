#include "action_manager.h"
#include "action_drink.h"
#include "action_eating.h"
#include "action_woodcutting.h"
#include "action_hunting.h"

ActionManager::ActionManager(World& world):
    _world(world)
{
    _actionMap["drink"] = new ActionFactory<ActionDrink>;
    _actionMap["eat"] = new ActionFactory<ActionEating>;
    _actionMap["cut_wood"] = new ActionFactory<ActionWoodcutting>;
    _actionMap["hunt"] = new ActionFactory<ActionHunting>;
}

ActionManager::~ActionManager() {
    for (auto item: _actionMap) {
        delete item.second;
    }
}

ActionPtr ActionManager::getAction(const string &action, Actor *actor) {
    return ActionPtr(_actionMap[action]->createAction(actor, _world));
}
