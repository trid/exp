---
--- Created by TriD.
--- DateTime: 14.10.2021 2:15
---

HuntingStartStep = {
    transition = function(actor)
        if g_world:getStoredFood() < 50 then
            actor:say("Need to collect some food.")
            return GoHuntingStep
        end
        actor:say("Nothing to do but stay in bed!")
        actor:addStatus("idle")
        return ExitStep
    end
}

GoHuntingStep = {
    transition = function(actor)
        if actor:getPosition() == "forest" then
            actor:say("Don't need to go anywhere, already in the forest.")
            return HuntStep
        end
        actor:say("Going to the forest! Feel like a wolf.")
        return GoToLocationStep.new("forest", HuntStep)
    end
}


HuntStep = {
    run = function(actor)
        actor:say("Start hunting! Hope I will not be a pray!")
        g_world:doAction(actor, "hunt")
    end,

    transition = function(actor)
        if actor:getInventory() == actor:getInventoryLimit() then
            return GoToLocationStep.new("home", UnloadFoodStep)
        end
    end
}

UnloadFoodStep = {
    run = function(actor)
        actor:say("Unloading my load of food")
        actor:unloadFood()
    end,

    transition = function(actor)
        return ExitStep
    end
}

g_stateManager:registerBehaviour("Hunting", HuntingStartStep)