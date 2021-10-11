--
-- User: TriD
-- Date: 21.10.2014
-- Time: 23:45
--

function enterHunterThirsty(actor)
    actor:say("I want to drink!\n")
end

function executeHunterThirsty(actor)
    actor:say("I'll go to the well!\n")
    g_world:moveActor(actor, "well");
    setState(actor, "StateHunterInRoute", g_stateManager)
end

function exitHunterThirsty(actor)

end

StateHunterThirsty = {
    enter = enterHunterThirsty,
    execute = executeHunterThirsty,
    exit = exitHunterThirsty
}

g_stateManager:registerScriptedState("StateHunterThirsty", "StateHunterThirsty", g_scriptContext)
print("Registered StateHunterThirsty\n")
