---
--- Created by TriD.
--- DateTime: 14.10.2021 1:00
---

ExitStep = {
    run = function(actor)
        actor:say("Job's done!")
        setState(actor, "", g_stateManager)
    end,

    transition = function(actor)
        return nil
    end
}