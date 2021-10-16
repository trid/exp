#include "message_manager.h"
#include "ai/actors/actor.h"
#include "ai/actors/registry.h"

namespace Core {

void MessageManager::dispatchMessage(int actorId, Message& message) {
    AI::Actors::Actor* actor = _actorRegistry.getActor(actorId);
    actor->processMessage(message);
}

MessageManager::MessageManager(AI::Actors::ActorsRegistry& actorRegistry) :
        _actorRegistry(actorRegistry) {

}

} // namespace Core