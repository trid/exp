#include "message_manager.h"
#include "ai/actor.h"
#include "ai/registry.h"

void MessageManager::dispatchMessage(int actorId, Message &message) {
    Actor* actor = _actorRegistry.getActor(actorId);
    actor->processMessage(message);
}

MessageManager::MessageManager(ActorsRegistry& actorRegistry):
    _actorRegistry(actorRegistry)
{

}
