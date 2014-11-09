--
-- User: TriD
-- Date: 22.10.2014
-- Time: 0:48
--

function enterWoodcutterThirsty(actor)
    say(actor, "I want to drink!")
end

function executeWoodcutterThirsty(actor)
    say(actor, "I'll go to the well!")
    sendTo(actor, "well");
    setState(actor, "StateWoodcutterInRoute")
end

function exitWoodcutterThirsty(actor)

end

StateWoodcutterThirsty = {
    enter = enterWoodcutterThirsty,
    execute = executeWoodcutterThirsty,
    exit = exitWoodcutterThirsty
}

print("Registered StateWoodcutterThirsty\n")
registerScriptedState("StateWoodcutterThirsty", "StateWoodcutterThirsty")