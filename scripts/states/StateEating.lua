--
-- User: TriD
-- Date: 04.11.2014
-- Time: 22:30
--

function enterEating(actor)
    say(actor, "Oh! Food!\n")
    eat(actor)
end

function executeEating(actor)
    say(actor, "Chew!\n")
    if (not hasAction(actor)) then
        setState(actor, nil)
    end
end

function exitEating(actor)
    say(actor, "Not thirsty anymore")
end

StateEating = {
    enter = enterEating,
    execute = executeEating,
    exit = exitEating
}

print("Registered StateEating\n")
registerScriptedState("StateEating", "StateEating")

