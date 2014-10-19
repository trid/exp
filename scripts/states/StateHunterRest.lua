--
-- User: TriD
-- Date: 01.10.2014
-- Time: 15:27
--

function enterHunterRest(actor)
    say(actor, "At home and going rest!")
end

function executeHunterRest(actor)
    say(actor, "Resting from hunt!")
    if (getFeed(actor) == 0) then
        eat(actor)
    end
    if (getStoredFood() <= 10) then
        say(actor, "I have a hunt to do!")
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "forest")
    end
end

function exitHunterRest(actor)
    say(actor, "Returning from rest!")
end

StateHunterRest = {
    enter = enterHunterRest,
    execute = executeHunterRest,
    exit = exitHunterRest
}

print("Registered StateHunterRest\n")
registerScriptedState("StateHunterRest", "StateHunterRest")

