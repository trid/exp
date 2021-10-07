#include "state_manager.h"
#include "state.h"

namespace Core::AI {

State::State(StateManager& stateManager) :
        _stateManager(stateManager) {

}

StateManager& State::getStateManager() {
    return _stateManager;
}

} // namespace Core::AI