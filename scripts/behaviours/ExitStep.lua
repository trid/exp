---
--- Created by TriD.
--- DateTime: 14.10.2021 1:00
---

ExitStep = {
    run = function(actor)
        actor:say("Job's done!")
        actor:clearState()
    end,

    transition = function(actor)
        return nil
    end
}