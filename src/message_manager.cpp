#include "message_manager.h"
#include "ai/actor.h"
#include "ai/registry.h"

void MessageManager::dispatchMessage(int actorId, Message &message) {
    Actor* actor = ActorsRegistry::getRegistry().getActor(actorId);
    actor->processMessage(message);
}
