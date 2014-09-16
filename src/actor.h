class Actor {
    friend class Registry;
private:
    int id;
    int food = 90;
    int water = 60;
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
};