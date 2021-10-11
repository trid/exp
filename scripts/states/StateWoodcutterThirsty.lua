--
-- User: TriD
-- Date: 22.10.2014
-- Time: 0:48
--

function enterWoodcutterThirsty(actor)
    actor:say("I want to drink!")
end

function executeWoodcutterThirsty(actor)
    actor:say("I'll go to the well!")
    g_world:moveActor(actor, "well");
    setState(actor, "StateWoodcutterInRoute", g_stateManager)
end

function exitWoodcutterThirsty(actor)

end

StateWoodcutterThirsty = {
    enter = enterWoodcutterThirsty,
    execute = executeWoodcutterThirsty,
    exit = exitWoodcutterThirsty
}

g_stateManager:registerScriptedState("StateWoodcutterThirsty", "StateWoodcutterThirsty", g_scriptContext)
print("Registered StateWoodcutterThirsty\n")
