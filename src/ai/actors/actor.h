#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../../message_manager.h"
#include "../../actions/action.h"
#include "../behaviour_step.h"

#include "actors_needs.h"
#include "actor_movement_data.h"

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

class Actor: public ActorNeeds, public ActorMovementData {
public:
    explicit Actor(int id, View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel);

    int getID() const { return id; }

    BehaviourStepOpt getBehaviourStep();
    void setBehaviourStep(BehaviourStepOpt step);

    const std::string& getName() const { return name; }

    void setName(const std::string& name) { Actor::name = name; }

    int getInventory() const { return inventory; }

    void setInventory(int inventory) { Actor::inventory = inventory; }

    void say(const std::string& message);
    void processMessage(Core::Message& message);
    void addItem();
    void unloadWood();
    void unloadFood();

    int getInventoryLimit();

    void addStatus(const std::string& stateName);
    void removeStatus(std::string const& stateName);
    const std::unordered_set<std::string>& getStatuses();
    const std::unordered_map<std::string, std::string>& getStatusReactors();

    void setReactor(const std::string& stateName, const std::string& reactionState);

    void setAction(Core::Actions::ActionPtr& action);
    void removeAction();
    bool hasAction();

    bool isExecutingReaction();
    void setExecutingReaction(bool executingReaction);
private:
    int id;

    BehaviourStepOpt _step = boost::none;
    std::string name;
    int inventory = 0;
    int inventoryLimit = 20;
    bool _executingReaction = false;
    std::unordered_set<std::string> _statuses;
    std::unordered_map<std::string, std::string> _statusReactors;
    Core::Actions::ActionPtr currentAction;

    View::ViewFacade& _view;
    Core::World& _world;
    View::Widgets::GUIPanel& _guiPanel;
};

} // namespace Core::AI::Actors

#endif // ACTOR_H