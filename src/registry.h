#include "vector"

using std::vector;

class Actor;

class ActorsRegistry {
public:
    static ActorsRegistry& getRegistry() {
        static ActorsRegistry ar;
        return ar;
    };

    Actor& createActor();
    Actor& getActor(int id);
    const vector<Actor*>& getActors();
    void killActor(int id);
    void update();
private:
    vector<Actor*> actors;
};