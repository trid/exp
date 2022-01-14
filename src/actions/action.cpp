#include "action.h"

namespace Core::Actions {

bool Action::isRunning() const { return _running; }

void Action::stop() { _running = false; }

AI::Agents::Agent& Action::getActor() { return _actor; }

Action::Action(AI::Agents::Agent& actor, World&) : _actor(actor) {}


} // namespace Core::Actions