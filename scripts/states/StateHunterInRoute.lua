--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 29.09.2014
-- Time: 13:36
-- To change this template use File | Settings | File Templates.
--

function enterHunterInRoute(actor)
    say(actor, "Start moving!")
end

function executeHunterInRoute(actor)
    say(actor, "On my way! I'm clever and fast!")
end

function exitHunterInRoute(actor)
    say(actor, "Finished moving!")
end

function processMessageHunterInRoute(actor, message)
    if (getMessageType(message) == "FINISHED_MOVING") then
        -- Always check if we at home and unload food
        if (getPlace(actor) == "home") then
            unloadFood(actor)
        end
        if (getPlace(actor) == "forest") then
            say(actor, "Returned to forest!")
            setState(actor, "StateHunting")
        elseif (getPlace(actor) == "well") then
            drink(actor)
            setState(actor, "StateHunterInRoute")
            sendTo(actor, "forest", 4);
        elseif (getPlace(actor) == "home" and getStoredFood() >= 20) then
            setState(actor, "StateHunterRest")
        elseif (getPlace(actor) == "home") then
            eat(actor)
            setState(actor, "StateHunterInRoute")
            sendTo(actor, "forest", 3);
        end
    end
end

StateHunterInRoute = {
    enter = enterHunterInRoute,
    execute = executeHunterInRoute,
    exit = exitHunterInRoute,
    processMessage = processMessageHunterInRoute
}

print("Registered StateHunterInRoute\n")
registerScriptedState("StateHunterInRoute", "StateHunterInRoute")
