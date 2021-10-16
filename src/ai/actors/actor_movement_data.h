//
// Created by TriD on 17.10.2021.
//

#ifndef EXP_ACTOR_MOVEMENT_DATA_H
#define EXP_ACTOR_MOVEMENT_DATA_H

#include <string>

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Actors {

class ActorMovementData {
public:
    [[nodiscard]] const std::string& getPosition() const;
    void setPosition(World& world, const std::string& position);

    void setTargetPosition(const std::string& position);
    const std::string& getTargetPosition();

    void updatePosition(double dx, double dy);

    [[nodiscard]] int getX() const;
    void setX(int x);

    [[nodiscard]] int getY() const;
    void setY(int y);

    [[nodiscard]] double getSpeed() const;
    void setSpeed(double speed);
private:
    std::string _position = "";
    std::string _target = "";

    //Pixels per second
    double _speed = 120;

    //Actor position
    double _x = 0.0;
    double _y = 0.0;
};

} // namespace Core::AI::Actors


#endif //EXP_ACTOR_MOVEMENT_DATA_H
