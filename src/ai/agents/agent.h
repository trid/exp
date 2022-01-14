#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "actor.h"
#include "agent_needs.h"
#include "agent_movement_data.h"
#include "inventory.h"


namespace Core {
class GlobalMessageBus;
class World;
} // namespace Core

namespace Core::AI::Agents {

class Agent: public AgentNeeds, public AgentPositioningData, public Actor, public Inventory {
public:
    explicit Agent(int id, Core::GlobalMessageBus& globalMessageBus);

    int getID() const;

    const std::string& getName() const;

    void setName(const std::string& name);

    void say(const std::string& message);

    void setType(const std::string& type);
    const std::string& getType() const;

private:
    int _id;

    std::string _name;
    // TODO decide some better way to differentiate agent's color
    std::string _type;

    Core::GlobalMessageBus& _globalMessageBus;
};

} // namespace Core::AI::Agents

#endif // ACTOR_H