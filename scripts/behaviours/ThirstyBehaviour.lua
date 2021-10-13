---
--- Created by TriD.
--- DateTime: 14.10.2021 1:46
---

GoDrinkingStep = {
    transition = function(actor)
        if (actor:getPosition() == "well") then
            return DrinkStep
        end
        actor:say("Going to the well to drink some water.")
        return GoToLocationStep.new("well", DrinkStep)
    end
}

DrinkStep = {
    run = function(actor)
        actor:say("Oh fresh water!")
        actor:drink()
    end,

    transition = function(actor)
        if (not actor:hasAction()) then
            return ExitStep
        end
        return nil
    end
}

g_stateManager:registerBehaviour("Thirsty", GoDrinkingStep)