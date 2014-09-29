#include "state.h"

#include <iostream>

using namespace std;

class StateWoodcutting: public State {
public:
    virtual void enter(Actor* actor) { cout << "Start cutting wood" << endl; };
    virtual void execute(Actor* actor);
    virtual void exit(Actor* actor) { cout << "Finished cutting wood" << endl; };


    virtual void processMessage(Actor *actor, Message &message) override;

    static State* getInstance() {
        static StateWoodcutting instance;
        return &instance;
    }
};