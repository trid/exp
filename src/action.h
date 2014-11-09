#ifndef ACTION_H
#define ACTION_H

#include <memory>

using std::shared_ptr;

class Actor;

class Action {
private:
    bool running = true;
protected:
    Actor* actor;
public:
    virtual bool isValid() = 0;
    virtual void update(int delta) = 0;
    virtual int progress() = 0;
    virtual bool isFinished() = 0;

    bool isRunning() { return running; }
    void stop() { running = false; }
    Actor* getActor() { return actor; }

    Action(Actor* actor): actor(actor) {}
};

class VirtualActionFactory {
public:
    virtual Action* createAction(Actor* actor) = 0;
};

template <class T> class ActionFactory: public VirtualActionFactory {
    virtual Action* createAction(Actor* actor) { return new T(actor); }
};

typedef shared_ptr<Action> ActionPtr;

#endif