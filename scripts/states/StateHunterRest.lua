--
-- User: TriD
-- Date: 01.10.2014
-- Time: 15:27
--

function enterHunterRest(actor)
    print("At home and going rest!\n")
    resetSteps(actor)
end

function executeHunterRest(actor)
    print("Resting from hunt!\n")
    if (getFeed(actor) == 0) then
        eat(actor)
    end
    if (getStoredFood() <= 10) then
        print("I have a hunt to do!")
        setState(actor, "StateHunterInRoute")
        sendTo(actor, "forest", 3)
    end
end

function exitHunterRest(actor)
    print("Returning from rest!\n")
end

StateHunterRest = {
    enter = enterHunterRest,
    execute = executeHunterRest,
    exit = exitHunterRest
}

print("Registered StateHunterRest\n")
registerScriptedState("StateHunterRest", "StateHunterRest")

