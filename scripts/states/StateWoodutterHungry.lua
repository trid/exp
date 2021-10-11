--
-- User: TriD
-- Date: 22.10.2014
-- Time: 0:47
--

function enterWoodcutterHungry(actor)
    actor:say("I want to eat something!\n")
end

function executeWoodcutterHungry(actor)
    if (actor:getPosition() == "home") then
        setState(actor, "StateEating", g_stateManager)
    else
        actor:say("I'll go to home!\n")
        g_world:moveActor(actor, "home");
        setState(actor, "StateWoodcutterInRoute", g_stateManager)
    end
end

function exitWoodcutterHungry(actor)

end

StateWoodcutterHungry = {
    enter = enterWoodcutterHungry,
    execute = executeWoodcutterHungry,
    exit = exitWoodcutterHungry
}

g_stateManager:registerScriptedState("StateWoodcutterHungry", "StateWoodcutterHungry", g_scriptContext)
print("Registered StateWoodcutterHungry\n")
