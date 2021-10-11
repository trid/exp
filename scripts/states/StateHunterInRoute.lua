--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 29.09.2014
-- Time: 13:36
-- To change this template use File | Settings | File Templates.
--

function enterHunterInRoute(actor)
    actor:say("Start moving!")
    setStateBreackable(actor, false)
end

function executeHunterInRoute(actor)
    actor:say("On my way! I'm clever and fast!")
end

function exitHunterInRoute(actor)
    actor:say("Finished moving!")
    setStateBreackable(actor, true)
end

function processMessageHunterInRoute(actor, message)
    if (getMessageType(message) == "FINISHED_MOVING") then
        -- Always check if we at home and unload food
        if (getPlace(actor) == "home") then
            unloadFood(actor)
        end
        if (getPlace(actor) == "forest") then
            actor:say("Returned to forest!")
            setState(actor, "StateHunting", g_stateManager)
        elseif (getPlace(actor) == "well") then
             setState(actor, "StateDrinking", g_stateManager)
        elseif (getPlace(actor) == "home" and getStoredFood() >= 20) then
            setState(actor, "StateHunterRest", g_stateManager)
        elseif (getPlace(actor) == "home") then
            setState(actor, "StateEating", g_stateManager)
        end
    end
end

StateHunterInRoute = {
    enter = enterHunterInRoute,
    execute = executeHunterInRoute,
    exit = exitHunterInRoute,
    processMessage = processMessageHunterInRoute
}

g_stateManager:registerScriptedState("StateHunterInRoute", "StateHunterInRoute", g_scriptContext)
print("Registered StateHunterInRoute\n")
