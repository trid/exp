---
--- Created by TriD.
--- DateTime: 17.01.2022 23:26
---

SampleRequests = {
    update = function()
        requests = {}
        if not g_world:hasLocation("home") then
            if g_world:getStorage():getStoredResource("wood") > 300 then
                table.insert(requests, {request_type = "building", building = "home"})
            else
                table.insert(requests, {request_type = "resource", resource_type = "wood", amount = 300})
            end
        end
        if g_world:getStorage():getStoredResource("food") < 50 then
            table.insert(requests, {request_type = "resource", resource_type = "food", amount = 50})
        end
    end
}

g_world:addRequestGenerator(SampleRequests)