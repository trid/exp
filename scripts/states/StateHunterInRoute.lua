--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 29.09.2014
-- Time: 13:36
-- To change this template use File | Settings | File Templates.
--

function enterHunterInRoute(actor)
    print("Start moving!\n")
end

function executeHunterInRoute(actor)
    print("On my way! I'm clever and fast!\n")
end

function exitHunterInRoute(actor)
    print("Finished moving!\n")
end

function processMessageHunterInRoute(actor, message)
    if (getMessageType(message) == "FINISHED_MOVING") then
        if (getPlace(actor) == "forest") then
            setState(actor, "StateHunting")
        elseif (getPlace(actor) == "well") then
            setState(actor, "StateHunterInRoute")
            sendTo(actor, "forest", 4);
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
