#include <iostream>
#include "actor.h"

using namespace std;

class StateFinished: public State {
public:
    virtual void enter(Actor* actor){ cout << "Yup! I've finished!" << endl; }
    virtual void execute(Actor* actor) { cout << "Enjoing myself." << endl; };
    virtual void exit(Actor* actor){};

    static StateFinished* getInstance() {
        static StateFinished stateFinished;
        return &stateFinished;
    }
};