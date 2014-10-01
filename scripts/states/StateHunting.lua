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

    if (getThirsty(actor) == 0) then
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "well", 4)
    elseif (getFeed(actor) == 0) then
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "home", 3)
    elseif (getStoredFood() >= 20) then
        print("Have enough food, returning home.\n")
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "home", 3)
    else
        addFood();
    end
end

function exitHunting(actor)
    print("Returning from hunt!\n")
end

StateHunting = {
    enter = enterHunting,
    execute = executeHunting,
    exit = exitHunting
}

print("Registered StateHunting\n")
registerScriptedState("StateHunting", "StateHunting")

