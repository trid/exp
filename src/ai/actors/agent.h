#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../../message_manager.h"

#include "actor.h"
#include "agent_needs.h"
#include "agent_movement_data.h"

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

class Agent: public AgentNeeds, public AgentMovementData, public Actor {
public:
    explicit Agent(int id, Core::World& world, View::Widgets::GUIPanel& guiPanel);

    int getID() const { return id; }

    const std::string& getName() const { return name; }

    void setName(const std::string& name) { Agent::name = name; }

    int getInventory() const { return inventory; }

    void setInventory(int inventory) { Agent::inventory = inventory; }

    void say(const std::string& message);
    void processMessage(Core::Message& message);
    void addItem();
    void unloadWood();
    void unloadFood();

    int getInventoryLimit();
private:
    int id;

    std::string name;
    int inventory = 0;
    int inventoryLimit = 20;

    Core::World& _world;
    View::Widgets::GUIPanel& _guiPanel;
};

} // namespace Core::AI::Actors

#endif // ACTOR_H