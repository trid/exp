--
-- User: TriD
-- Date: 03.10.2014
-- Time: 16:30
--

print("Loading scene objects\n")

createSceneObject("campfire", "home", 400, 300, g_world)
createSceneObject("forest", "forest", 500, 0, g_world)
createSceneObject("well", "well", 200, 200, g_world)

print("Creating woodcutter\n")

woodcutter = createAgent(g_actorsRegistry, g_world)
woodcutter:setName("John Wood")
woodcutter:setType("green")
setReaction(woodcutter, "NoState", "Woodcutting")
setReaction(woodcutter, "Thirsty", "Thirsty")
setReaction(woodcutter, "Hungry", "Hungry")
g_world:setAgentLocation(woodcutter, "home")

woodcutter:setMaxFood(120);
woodcutter:setMaxWater(90);


print("Creating hunter\n")

hunter = createAgent(g_actorsRegistry, g_world)
hunter:setName("Hunter Smith")
hunter:setType("blue")
setReaction(hunter, "NoState", "Hunting")
setReaction(hunter, "Thirsty", "Thirsty")
setReaction(hunter, "Hungry", "Hungry")
g_world:setAgentLocation(hunter, "home")

