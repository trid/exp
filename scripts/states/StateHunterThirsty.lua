--
-- User: TriD
-- Date: 21.10.2014
-- Time: 23:45
--

function enterHunterThirsty(actor)
    say(actor, "I want to drink!\n")
end

function executeHunterThirsty(actor)
    say(actor, "I'll go to the well!\n")
    sendTo(actor, "well");
    setState(actor, "StateHunterInRoute")
end

function exitHunterThirsty(actor)

end

StateHunterThirsty = {
    enter = enterHunterThirsty,
    execute = executeHunterThirsty,
    exit = exitHunterThirsty
}

print("Registered StateHunterThirsty\n")
registerScriptedState("StateHunterThirsty", "StateHunterThirsty")
