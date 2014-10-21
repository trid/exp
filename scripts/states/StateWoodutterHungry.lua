--
-- User: TriD
-- Date: 22.10.2014
-- Time: 0:47
--

function enterWoodcutterHungry(actor)
    say(actor, "I want to eat something!\n")
end

function executeWoodcutterHungry(actor)
    if (getPlace(actor) == "home") then
        eat(actor)
        setState(actor, nil)
    else
        say(actor, "I'll go to home!\n")
        sendTo(actor, "home");
        setState(actor, "StateWoodcutterInRoute")
    end
end

function exitWoodcutterHungry(actor)

end

StateWoodcutterHungry = {
    enter = enterWoodcutterHungry,
    execute = executeWoodcutterHungry,
    exit = exitWoodcutterHungry
}

print("Registered StateWoodcutterHungry\n")
registerScriptedState("StateWoodcutterHungry", "StateWoodcutterHungry")