#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../../message_manager.h"
#include "../../actions/action.h"
#include "../behaviour_step.h"

#include "actors_needs.h"

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

class Actor: public ActorsNeeds {
public:
    explicit Actor(int id, View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel);

    int getID() const { return id; }

    const std::string& getPosition() const { return position; }

    void setPosition(const std::string& position);
    BehaviourStepOpt getBehaviourStep();
    void setBehaviourStep(BehaviourStepOpt step);
    void setTargetPosition(const std::string& position);
    const std::string& getTargetPosition();

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

    void updatePosition(double dx, double dy) {
        x += dx;
        y += dy;
    }

    int getX() const { return x; }

    void setX(int x) { Actor::x = x; }

    int getY() const { return y; }

    void setY(int y) { Actor::y = y; }

    double getSpeed() { return speed; }

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

    std::string position = "";
    std::string target = "";
    BehaviourStepOpt _step = boost::none;
    std::string name;
    int inventory = 0;
    int inventoryLimit = 20;
    //Pixels per second
    double speed = 120;
    //Actor position
    double x = 0.0, y = 0.0;
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