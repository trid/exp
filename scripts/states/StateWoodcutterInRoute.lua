--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 28.09.2014
-- Time: 23:09
-- To change this template use File | Settings | File Templates.
--

function enterWoodcutterInRoute(actor)
    actor:say("Start moving!")
    setStateBreackable(actor, false)
end

function executeWoodcutterInRoute(actor)
    actor:say("On my way!")
end

function exitWoodcutterInRoute(actor)
    actor:say("Finished moving!")
    setStateBreackable(actor, true)
end

function processMessageWoodcutterInRoute(actor, message)
    if (getMessageType(message) == "FINISHED_MOVING") then
        -- Always check if we at home and unload wood
        if (getPlace(actor) == "home") then
            unloadWood(actor)
        end
        if (getPlace(actor) == "forest") then
            setState(actor, "StateWoodcutting", g_stateManager)
        elseif (getPlace(actor) == "home" and getThirsty(actor) == 0) then
            setState(actor, "StateWoodcutterInRoute", g_stateManager)
            g_world:moveActor(actor, "well");
        elseif (getPlace(actor) == "home" and getFeed(actor) == 0) then
            setState(actor, "StateEating", g_stateManager)
        elseif (getPlace(actor) == "well") then
            setState(actor, "StateDrinking", g_stateManager)
        elseif (getPlace(actor) == "home" and getStoredWood() >= 300) then
            setState(actor, "StateFinished", g_stateManager)
        elseif (getPlace(actor) == "home" and getThirsty() ~= 0 and getFeed() ~= 0) then
            setState(actor, "StateWoodcutterInRoute", g_stateManager)
            g_world:moveActor(actor, "forest")
        elseif (getPlace(actor) ~= "home" and getWood() >= 300) then
            setState(actor, "StateWoodcutterInRoute", g_stateManager)
            g_world:moveActor(actor, "home")
        end
    end
end

StateWoodcutterInRoute = {
    enter = enterWoodcutterInRoute,
    execute = executeWoodcutterInRoute,
    exit = exitWoodcutterInRoute,
    processMessage = processMessageWoodcutterInRoute
}

g_stateManager:registerScriptedState("StateWoodcutterInRoute", "StateWoodcutterInRoute", g_scriptContext)
print("Registered StateWoodcutterInRoute\n")

