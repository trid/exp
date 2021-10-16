---
--- Created by TriD.
--- DateTime: 14.10.2021 1:40
---

GoEatingStep = {
    transition = function(actor)
        actor:say("Oh, I'm hungry")
        if (actor:getPosition() == "home") then
            return EatStep
        end
        actor:say("Going home to get some food.")
        return GoToLocationStep.new("home", EatStep)
    end
}

EatStep = {
    run = function(actor)
        actor:say("Food!")
        g_world:doAction(actor, "eat")
    end,

    transition = function(actor)
        if (not actor:hasAction()) then
            return ExitStep
        end
        return nil
    end
}

g_stateManager:registerBehaviour("Hungry", GoEatingStep)