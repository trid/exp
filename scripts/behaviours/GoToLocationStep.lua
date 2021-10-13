---
--- Created by TriD.
--- DateTime: 14.10.2021 1:01
---

GoToLocationStep = {}

GoToLocationStep.__index = GoToLocationStep

function GoToLocationStep.new(location, nextStep)
    local self = setmetatable({}, GoToLocationStep)
    self.location = location
    self.nextStep = nextStep
    self.movementStatus = {}
    return self
end

function GoToLocationStep.run(self, actor)
    actor:say("Direction " .. self.location .. "!")
    self.movementStatus = g_world:moveActor(actor, self.location)
end

function GoToLocationStep.transition(self, actor)
    if self.movementStatus:finished() then
        return self.nextStep
    end
    return nil
end