#include "message_manager.h"
#include "ai/actors/agent.h"
#include "ai/actors/registry.h"

namespace Core {

void MessageManager::dispatchMessage(int actorId, Message& message) {
    auto actor = _actorRegistry.getAgent(actorId);
    if (actor) {
        actor->processMessage(message);
    }
}

MessageManager::MessageManager(AI::Actors::AgentsRegistry& actorRegistry) :
        _actorRegistry(actorRegistry) {

}

} // namespace Core