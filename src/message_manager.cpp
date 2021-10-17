#include "message_manager.h"
#include "ai/actors/agent.h"
#include "ai/actors/registry.h"

namespace Core {

void MessageManager::dispatchMessage(int actorId, Message& message) {
    AI::Actors::Agent* actor = _actorRegistry.getAgent(actorId);
    actor->processMessage(message);
}

MessageManager::MessageManager(AI::Actors::AgentsRegistry& actorRegistry) :
        _actorRegistry(actorRegistry) {

}

} // namespace Core