//
// Created by TriD on 17.10.2021.
//

#ifndef EXP_AGENT_MOVEMENT_DATA_H
#define EXP_AGENT_MOVEMENT_DATA_H

#include <string>

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Agents {

class AgentPositioningData {
public:
    void updatePosition(double dx, double dy);

    [[nodiscard]] int getX() const;
    void setX(int x);

    [[nodiscard]] int getY() const;
    void setY(int y);

    [[nodiscard]] double getSpeed() const;
    void setSpeed(double speed);

private:
    //Pixels per second
    double _speed = 120;

    //Agent position
    double _x = 0.0;
    double _y = 0.0;
};

} // namespace Core::AI::Agents


#endif //EXP_AGENT_MOVEMENT_DATA_H
