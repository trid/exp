--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 27.09.2014
-- Time: 18:13
-- To change this template use File | Settings | File Templates.
--

function enterGoingHunt(actor)
    print("Packed my bags and going to forest!\n")
    resetSteps(actor)
end

function executeGoingHunt(actor)
    print("In route to forest!\n")
    updateSteps(actor)
    if (getSteps(actor) == 3) then
        moveTo(actor, 2)
        setState(actor, "StateHunting")
    end
end

function exitGoingHunt(actor)
    print("In forest!\n")
end

StateGoingHunt = {
    enter = enterGoingHunt,
    execute = executeGoingHunt,
    exit = exitGoingHunt
}

print("Registered StateGoingHunt\n")
registerScriptedState("StateGoingHunt", "StateGoingHunt")