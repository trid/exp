--
-- User: TriD
-- Date: 03.10.2014
-- Time: 16:30
--

print("Loading scene objects\n")

createSceneObject(400, 300, "campfire", "home")
createSceneObject(500, 0, "forest", "forest")
createSceneObject(200, 200, "well", "well")

print("Creating woodcutter\n")

woodcutter = createActor(g_actorsRegistry)
woodcutter:setName("John Wood")
setReaction(woodcutter, "NoState", "StateStart", g_stateManager)
setReaction(woodcutter, "thirsty", "StateWoodcutterThirsty", g_stateManager)
setReaction(woodcutter, "hungry", "StateWoodcutterHungry", g_stateManager)
woodcutter:setPosition("home")

woodcutter:setMaxFood(120);
woodcutter:setMaxWater(90);


print("Creating hunter\n")

hunter = createActor(g_actorsRegistry)
hunter:setName("Hunter Smith")
setReaction(hunter, "NoState", "StateHunterStart", g_stateManager)
setReaction(hunter, "thirsty", "StateHunterThirsty", g_stateManager)
setReaction(hunter, "hungry", "StateHunterHungry", g_stateManager)
hunter:setPosition("home")

