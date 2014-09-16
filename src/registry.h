#include "vector"

#include "actor.h"

using std::vector;

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
private:
    vector<Actor*> actors;
};