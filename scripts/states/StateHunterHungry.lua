--
-- User: TriD
-- Date: 22.10.2014
-- Time: 0:11
--

function enterHunterHungry(actor)
    actor:say("I want to eat something!\n")
end

function executeHunterHungry(actor)
    if (getPlace(actor) == "home") then
        setState(actor, "StateEating", g_stateManager)
    else
        actor:say("I'll go to home!\n")
        g_world:moveActor(actor, "home");
        setState(actor, "StateHunterInRoute")
    end
end

function exitHunterHungry(actor)

end

StateHunterHungry = {
    enter = enterHunterHungry,
    execute = executeHunterHungry,
    exit = exitHunterHungry
}

g_stateManager:registerScriptedState("StateHunterHungry", "StateHunterHungry", g_scriptContext)
print("Registered StateHunterHungry\n")


