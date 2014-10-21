--
-- User: TriD
-- Date: 22.10.2014
-- Time: 0:11
--

function enterHunterHungry(actor)
    say(actor, "I want to eat something!\n")
end

function executeHunterHungry(actor)
    if (getPlace(actor) == "home") then
        eat(actor)
        setState(actor, nil)
    else
        say(actor, "I'll go to home!\n")
        sendTo(actor, "home");
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

print("Registered StateHunterHungry\n")
registerScriptedState("StateHunterHungry", "StateHunterHungry")


