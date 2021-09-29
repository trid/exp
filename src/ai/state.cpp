#include "state_manager.h"
#include "state.h"


State::State(StateManager& stateManager):
    _stateManager(stateManager)
{

}

StateManager& State::getStateManager() {
    return _stateManager;
}
