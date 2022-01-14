//
// Created by TriD on 17.10.2021.
//

#ifndef EXP_AGENT_NEEDS_H
#define EXP_AGENT_NEEDS_H

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Agents {

class AgentNeeds {
public:
    [[nodiscard]] int getFood() const;
    void setFood(int food);

    [[nodiscard]] int getWater() const;
    void setWater(int water);

    [[nodiscard]] int getMaxFood() const;
    void setMaxFood(int maxFood);

    [[nodiscard]] int getMaxWater() const;
    void setMaxWater(int maxWater);
private:
    int _food = 90;
    int _water = 60;
    int _maxFood = 90;
    int _maxWater = 60;
};

} // namespace AI::Agents


#endif //EXP_AGENT_NEEDS_H
