--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 27.09.2014
-- Time: 18:25
-- To change this template use File | Settings | File Templates.
--

function enterHunting(actor)
    say(actor, "Started hunt!")
end

function executeHunting(actor)
    say(actor, "Hunting! Yum, fresh meat!")

    if (getThirsty(actor) == 0) then
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "well", 4)
    elseif (getFeed(actor) == 0) then
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "home", 3)
    elseif (getStoredFood() >= 20) then
        say(actor, "Have enough food, returning home.")
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "home", 3)
    elseif (getInventory(actor) == getInventorySize(actor)) then
        say(actor, "My bag is heavy, returning home.")
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "home", 3)
    else
        addFood(actor);
    end
end

function exitHunting(actor)
    print("Returning from hunt!")
end

StateHunting = {
    enter = enterHunting,
    execute = executeHunting,
    exit = exitHunting
}

print("Registered StateHunting\n")
registerScriptedState("StateHunting", "StateHunting")

