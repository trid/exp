---
--- Created by TriD.
--- DateTime: 12.10.2021 22:45
---


CutWoodStartStep = {
    transition = function(actor)
        if g_world:getStoredWood() < 300 then
            actor:say("Need to collect some wood.")
            return GoWoodcuttingStep
        end
        actor:say("Nothing to do but stay in bed!")
        actor:addStatus("idle")
        return ExitStep
    end
}

GoWoodcuttingStep = {
    transition = function(actor)
        if actor:getPosition() == "forest" then
            actor:say("Don't need to go anywhere, already in the forest.")
            return CutWoodStep
        end
        actor:say("Going to the forest! Feel like a red hood.")
        return GoToLocationStep.new("forest", CutWoodStep)
    end
}


CutWoodStep = {
    run = function(actor)
        actor:say("Start cutting wood! Hope it will not kill me!")
        g_world:doAction(actor, "cut_wood")
    end,

    transition = function(actor)
        if actor:getInventory() == actor:getInventoryLimit() then
            return GoToLocationStep.new("home", UnloadWoodStep)
        end
    end
}

UnloadWoodStep = {
    run = function(actor)
        actor:say("Unloading my heavy wood")
        actor:unloadWood()
    end,

    transition = function(actor)
        return ExitStep
    end
}

g_stateManager:registerBehaviour("Woodcutting", CutWoodStartStep)