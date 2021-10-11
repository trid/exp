--
-- User: TriD
-- Date: 04.11.2014
-- Time: 1:48
--

function enterDrinking(actor)
    actor:say("Oh! Water!")
    drink(actor)
end

function executeDrinking(actor)
    actor:say("Gulp!")
    if (not hasAction(actor)) then
        setState(actor, "", g_stateManager)
    end
end

function exitDrinking(actor)
    actor:say("Enough drinking.")
end

StateDrinking = {
    enter = enterDrinking,
    execute = executeDrinking,
    exit = exitDrinking
}

g_stateManager:registerScriptedState("StateDrinking", "StateDrinking", g_scriptContext)
print("Registered StateDrinking\n")

