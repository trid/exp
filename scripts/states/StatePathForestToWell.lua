--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 27.09.2014
-- Time: 18:42
-- To change this template use File | Settings | File Templates.
--

function enterInRouteToWell(actor)
    print("Going to the well!\n")
    resetSteps(actor)
end

function executeInRouteToWell(actor)
    print("On my way for a fresh water!\n")
    updateSteps(actor)

    if (getSteps(actor) == 4) then
        moveTo(actor, "well")
        drink(actor);
        setState(actor, "StatePatheWellToForest")
    end
end

function exitInRouteToWell(actor)
    print("Returning from well!\n")
end

StatePathForestToWell = {
    enter = enterInRouteToWell,
    execute = executeInRouteToWell,
    exit = exitInRouteToWell
}

print("Registered StatePathForestToWell\n")
registerScriptedState("StatePathForestToWell", "StatePathForestToWell")

