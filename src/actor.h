enum Position {
    POSITION_NONE,
    POSITION_HOME,
    POSITION_FOREST,
    POSITION_WATER
};

class Actor {
    friend class Registry;
private:
    int id;
    int food = 90;
    int water = 60;

    Position position = POSITION_HOME;
public:
    void update();
    void eat();
    void drink();

    int getFood() const {
        return food;
    }

    int getWater() const {
        return water;
    }

    int getID() const {
        return id;
    }

    Position getPosition() const {
        return position;
    }

    void setPosition(Position position) {
        this->position = position;
    }
};