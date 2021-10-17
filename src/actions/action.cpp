#include "action.h"

namespace Core::Actions {

bool Action::isRunning() const { return running; }

void Action::stop() { running = false; }

AI::Actors::Agent* Action::getActor() { return actor; }

Action::Action(AI::Actors::Agent* actor, World&) : actor(actor) {}


} // namespace Core::Actions