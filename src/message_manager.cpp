#include "message_manager.h"
#include "actor.h"
#include "registry.h"

void MessageManager::dispatchMessage(int actorId, Message &message) {
    Actor* actor = ActorsRegistry::getRegistry().getActor(actorId);
    actor->processMessage(message);
}
