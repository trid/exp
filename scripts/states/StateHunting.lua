--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 27.09.2014
-- Time: 18:25
-- To change this template use File | Settings | File Templates.
--

function enterHunting(actor)
    print("Started hunt!\n")
    resetSteps(actor)
end

function executeHunting(actor)
    print("Hunting! Yum, fresh meat!\n")
    addFood();

    if (getThirsty(actor) == 0) then
        setState(actor, "StatePathForestToWell")
    end
end

function exitHunting(actor)
    print("Returning from forest!\n")
end

StateHunting = {
    enter = enterHunting,
    execute = executeHunting,
    exit = exitHunting
}

print("Registered StateHunting\n")
registerScriptedState("StateHunting", "StateHunting")

