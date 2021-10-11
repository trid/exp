--
-- User: TriD
-- Date: 04.11.2014
-- Time: 22:30
--

function enterEating(actor)
    actor:say("Oh! Food!\n")
    actor:eat()
end

function executeEating(actor)
    actor:say("Chew!\n")
    if (not actor:hasAction()) then
        setState(actor, "", g_stateManager)
    end
end

function exitEating(actor)
    actor:say("Not thirsty anymore")
end

StateEating = {
    enter = enterEating,
    execute = executeEating,
    exit = exitEating
}

g_stateManager:registerScriptedState("StateEating", "StateEating", g_scriptContext)
print("Registered StateEating\n")

