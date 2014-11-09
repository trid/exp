--
-- User: TriD
-- Date: 04.11.2014
-- Time: 1:48
--

function enterDrinking(actor)
    say(actor, "Oh! Water!")
    drink(actor)
end

function executeDrinking(actor)
    say(actor, "Gulp!")
    if (not hasAction(actor)) then
        setState(actor, nil)
    end
end

function exitDrinking(actor)
    say(actor, "Enough drinking.")
end

StateDrinking = {
    enter = enterDrinking,
    execute = executeDrinking,
    exit = exitDrinking
}

print("Registered StateDrinking\n")
registerScriptedState("StateDrinking", "StateDrinking")

