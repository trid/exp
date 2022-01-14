//
// Created by TriD on 31.12.2021.
//

#ifndef EXP_AGENT_H
#define EXP_AGENT_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

namespace Core {
class World;
struct Travel;

typedef std::shared_ptr<Travel> TravelPtr;
}

namespace Scripting::API {

class Agent {
public:
    Agent(Core::World& world, int id);

    void say(const std::string& message);

    [[nodiscard]] int getWater() const;
    [[nodiscard]] int getFood() const;

    [[nodiscard]] boost::optional<const std::string&> getPosition() const;

    [[nodiscard]] int getInventory() const;
    [[nodiscard]] int getInventoryLimit() const;
    void unloadResource(const std::string& resource);

    [[nodiscard]] bool hasAction() const;
    void addStatus(const std::string& status);
    void clearState();

    Core::TravelPtr move(const std::string& dest);
    void doAction(const std::string& action);
private:
    Core::World& _world;
    int _id;
};

}

#endif //EXP_AGENT_H
