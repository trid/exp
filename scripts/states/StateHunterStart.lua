--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 24.09.2014
-- Time: 19:00
-- To change this template use File | Settings | File Templates.
--

function enter(actor)
    actor:say("Starting my hunter's day!\n")
end

function execute(actor)
    if (getStoredFood() >= 20) then
        if (actor:getPosition() == "home") then
            setState(actor, "StateHunterRest", g_stateManager)
        else
            setState(actor, "StateHunterInRoute", g_stateManager)
            g_world:moveActor(actor, "home");
        end
    else
        actor:say("I'll go to forest and hunt!\n")
        g_world:moveActor(actor, "forest");
        setState(actor, "StateHunterInRoute", g_stateManager)
    end
end

function exit(actor)
    actor:say("Got to do something!\n")
end

StateHunterStart = {
    enter = enter,
    execute = execute,
    exit = exit
}

g_stateManager:registerScriptedState("StateHunterStart", "StateHunterStart", g_scriptContext)
print("Registered StateHunterStart\n")
