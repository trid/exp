#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../../message_manager.h"

#include "actor.h"
#include "agent_needs.h"
#include "agent_movement_data.h"
#include "inventory.h"

namespace View {
class ViewFacade;

namespace Widgets {
class GUIPanel;
} // namespace Widgets
} // namespace View

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Actors {

class Agent: public AgentNeeds, public AgentMovementData, public Actor, public Inventory {
public:
    explicit Agent(int id, Core::World& world, View::Widgets::GUIPanel& guiPanel);

    int getID() const { return id; }

    const std::string& getName() const { return name; }

    void setName(const std::string& name) { Agent::name = name; }

    void say(const std::string& message);
    void processMessage(Core::Message& message);

    void unloadWood();
    void unloadFood();

private:
    int id;

    std::string name;

    Core::World& _world;
    View::Widgets::GUIPanel& _guiPanel;
};

} // namespace Core::AI::Actors

#endif // ACTOR_H