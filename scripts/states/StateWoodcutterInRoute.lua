--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 28.09.2014
-- Time: 23:09
-- To change this template use File | Settings | File Templates.
--

function enterWoodcutterInRoute(actor)
    actor:say("Start moving!")
    actor:setStateBreackable(false)
end

function executeWoodcutterInRoute(actor)
    actor:say("On my way!")
end

function exitWoodcutterInRoute(actor)
    actor:say("Finished moving!")
    actor:setStateBreackable(true)
end

function processMessageWoodcutterInRoute(actor, message)
    if (message.messageType == "FINISHED_MOVING") then
        -- Always check if we at home and unload wood
        if (actor:getPosition() == "home") then
            actor:unloadWood()
        end
        if (actor:getPosition() == "forest") then
            setState(actor, "StateWoodcutting", g_stateManager)
        elseif (actor:getPosition() == "home" and actor:getWater() == 0) then
            setState(actor, "StateWoodcutterInRoute", g_stateManager)
            g_world:moveActor(actor, "well");
        elseif (actor:getPosition() == "home" and actor:getFood() == 0) then
            setState(actor, "StateEating", g_stateManager)
        elseif (actor:getPosition() == "well") then
            setState(actor, "StateDrinking", g_stateManager)
        elseif (actor:getPosition() == "home" and g_world:getStoredWood() >= 300) then
            setState(actor, "StateFinished", g_stateManager)
        elseif (actor:getPosition() == "home" and actor:getWater() ~= 0 and actor:getFood() ~= 0) then
            setState(actor, "StateWoodcutterInRoute", g_stateManager)
            g_world:moveActor(actor, "forest")
        elseif (actor:getPosition() ~= "home" and getWood() >= 300) then
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

