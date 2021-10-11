--
-- User: TriD
-- Date: 01.10.2014
-- Time: 15:27
--

function enterHunterRest(actor)
    actor:say("At home and going rest!")
end

function executeHunterRest(actor)
    actor:say("Resting from hunt!")
    if (actor:getFood() == 0) then
        actor:eat()
    end
    if (g_world:getStoredFood() <= 10) then
        actor:say("I have a hunt to do!")
        setState(actor, "StateHunterInRoute", g_stateManager)
        g_world:moveActor(actor, "forest")
    end
end

function exitHunterRest(actor)
    actor:say("Returning from rest!")
end

StateHunterRest = {
    enter = enterHunterRest,
    execute = executeHunterRest,
    exit = exitHunterRest
}

g_stateManager:registerScriptedState("StateHunterRest", "StateHunterRest", g_scriptContext)
print("Registered StateHunterRest\n")

