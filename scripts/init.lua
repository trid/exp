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

woodcutter = createActor(g_actorsRegistry, g_world)
woodcutter:setName("John Wood")
setReaction(woodcutter, "NoState", "Woodcutting")
setReaction(woodcutter, "Thirsty", "Thirsty")
setReaction(woodcutter, "Hungry", "Hungry")
woodcutter:setPosition(g_world, "home")

woodcutter:setMaxFood(120);
woodcutter:setMaxWater(90);


print("Creating hunter\n")

hunter = createActor(g_actorsRegistry, g_world)
hunter:setName("Hunter Smith")
setReaction(hunter, "NoState", "Hunting")
setReaction(hunter, "Thirsty", "Thirsty")
setReaction(hunter, "Hungry", "Hungry")
hunter:setPosition(g_world, "home")

