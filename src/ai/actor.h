#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../message_manager.h"
#include "../actions/action.h"
#include "state.h"


namespace View {
class ViewFacade;

namespace Widgets {
class GUIPanel;
} // namespace Widgets
} // namespace View

namespace Core {
class World;
} // namespace Core

namespace Core::AI {

class Actor {
    friend class ActorsRegistry;

public:
    explicit Actor(View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel);

    void update();
    void eat();
    void drink();

    int getFood() const { return food; }

    void setFood(int food) { this->food = food; }

    int getWater() const { return water; }

    void setWater(int water) { this->water = water; }

    int getMaxFood() { return maxFood; }

    void setMaxFood(int maxFood) {
        this->maxFood = maxFood;
        food = maxFood;
    }

    int getMaxWater() { return maxWater; }

    void setMaxWater(int maxWater) {
        this->maxWater = maxWater;
        water = maxWater;
    }

    int getID() const { return id; }

    const std::string& getPosition() const { return position; }

    void setPosition(const std::string& position);
    StateOpt getState();
    void setState(const StateOpt& state);
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

    bool isStateBreackable() const { return stateBreackable; }

    void setStateBreackable(bool stateBreackable) { Actor::stateBreackable = stateBreackable; }

    void addGlobalState(const std::string& stateName);
    void setReactor(const std::string& stateName, StateOpt reactionState);

    void removeGlobalState(std::string const& stateName);

    void setAction(Core::Actions::ActionPtr& action);
    void removeAction();
    bool hasAction();

    void updateStatus();
private:
    int id;
    int food = 90;
    int water = 60;
    int maxFood = 90;
    int maxWater = 60;

    std::string position = "";
    std::string target = "";
    StateOpt _state = boost::none;
    std::string name;
    int inventory = 0;
    int inventoryLimit = 20;
    //Pixels per second
    double speed = 120;
    //Actor position
    double x, y;
    bool stateBreackable = true;
    std::string executingState;
    std::unordered_set<std::string> globalStates;
    std::unordered_map<std::string, StateOpt> globalStateReactors;
    Core::Actions::ActionPtr currentAction;

    View::ViewFacade& _view;
    Core::World& _world;
    View::Widgets::GUIPanel& _guiPanel;
};

} // namespace Core::AI

#endif // ACTOR_H