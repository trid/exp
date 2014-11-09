#include "action_manager.h"
#include "action_drink.h"
#include "action_eating.h"
#include "action_woodcutting.h"
#include "action_hunting.h"

ActionManager::ActionManager() {
    actionMap["drink"] = new ActionFactory<ActionDrink>;
    actionMap["eat"] = new ActionFactory<ActionEating>;
    actionMap["cut_wood"] = new ActionFactory<ActionWoodcutting>;
    actionMap["hunt"] = new ActionFactory<ActionHunting>;
}

ActionManager::~ActionManager() {
    for (auto item: actionMap) {
        delete item.second;
    }
}

ActionPtr ActionManager::getAction(const string &action, Actor *actor) {
    return ActionPtr(actionMap[action]->createAction(actor));
}
