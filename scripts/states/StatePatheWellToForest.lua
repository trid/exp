--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 27.09.2014
-- Time: 18:55
-- To change this template use File | Settings | File Templates.
--

function enterInRouteToForest(actor)
    print("Returning to forest!\n")
    resetSteps(actor)
end

function executeInRouteToForest(actor)
    print("On my way to forest!\n")
    updateSteps(actor)

    if (getSteps(actor) == 4) then
        moveTo(actor, "forest")
        setState(actor, "StateHunting")
    end
end

function exitInRouteToForest(actor)
    print("Returned to forest!\n")
end

StatePatheWellToForest = {
    enter = enterInRouteToForest,
    execute = executeInRouteToForest,
    exit = exitInRouteToForest
}

print("Registered StatePatheWellToForest\n")
registerScriptedState("StatePatheWellToForest", "StatePatheWellToForest")

