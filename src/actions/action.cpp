#include "action.h"

namespace Core::Actions {

bool Action::isRunning() const { return running; }

void Action::stop() { running = false; }

AI::Actors::Actor* Action::getActor() { return actor; }

Action::Action(AI::Actors::Actor* actor, World&) : actor(actor) {}


} // namespace Core::Actions