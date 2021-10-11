--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 27.09.2014
-- Time: 18:25
-- To change this template use File | Settings | File Templates.
--

function enterHunting(actor)
    actor:say("Started hunt!")
    g_world:doAction(actor, "hunt")
end

function executeHunting(actor)
    actor:say("Hunting! Yum, fresh meat!")

    if (g_world:getStoredFood() >= 20) then
        actor:say("Have enough food, returning home.")
        setState(actor, "StateHunterInRoute", g_stateManager)
        g_world:moveActor(actor, "home")
    elseif (actor:getInventory() == getInventoryLimit(actor)) then
        actor:say("My bag is heavy, returning home.")
        setState(actor, "StateHunterInRoute", g_stateManager)
        g_world:moveActor(actor, "home")
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

g_stateManager:registerScriptedState("StateHunting", "StateHunting", g_scriptContext)
print("Registered StateHunting\n")

