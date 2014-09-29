--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 28.09.2014
-- Time: 23:09
-- To change this template use File | Settings | File Templates.
--

function enterWoodcutterInRoute(actor)
    print("Start moving!\n")
end

function executeWoodcutterInRoute(actor)
    print("On my way!\n")
end

function exitWoodcutterInRoute(actor)
    print("Finished moving!\n")
end

function processMessageWoodcutterInRoute(actor, message)
    if (getMessageType(message) == "FINISHED_MOVING") then
        if (getPlace(actor) == "forest") then
            setState(actor, "StateWoodcutting")
        elseif (getPlace(actor) == "home" and getThirsty(actor) == 0) then
            setState(actor, "StateWoodcutterInRoute")
            sendTo(actor, "well", 2);
        elseif (getPlace(actor) == "well") then
            drink(actor)
            setState(actor, "StateWoodcutterInRoute")
            sendTo(actor, "home", 2);
        elseif (getPlace(actor) == "home" and getThirsty ~= 0) then
            setState(actor, "StateWoodcutterInRoute")
            sendTo(actor, "forest", 3);
        end
    end
end

StateWoodcutterInRoute = {
    enter = enterWoodcutterInRoute,
    execute = executeWoodcutterInRoute,
    exit = exitWoodcutterInRoute,
    processMessage = processMessageWoodcutterInRoute
}

print("Registered StateWoodcutterInRoute\n")
registerScriptedState("StateWoodcutterInRoute", "StateWoodcutterInRoute")

