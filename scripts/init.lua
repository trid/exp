--
-- User: TriD
-- Date: 03.10.2014
-- Time: 16:30
--

print("Loading scene objects\n")

createSceneObject(400, 300, "home", "home")
createSceneObject(500, 0, "forest", "forest")
createSceneObject(200, 200, "well", "well")

print("Creating woodcutter\n")

woodcutter = createActor()
setName(woodcutter, "John Wood")
setReaction(woodcutter, "NoState", "StateStart")
setReaction(woodcutter, "thirsty", "StateWoodcutterThirsty")
setReaction(woodcutter, "hungry", "StateWoodcutterHungry")
moveTo(woodcutter, "home")

woodcutterObject = getScriptObject("actor" .. getId(woodcutter))
woodcutterMaxFoodParameter = getObjectParameter(woodcutterObject, "maxFood")
setParameterValue(woodcutterMaxFoodParameter, 120);
woodcutterMaxWaterParameter = getObjectParameter(woodcutterObject, "maxWater")
setParameterValue(woodcutterMaxWaterParameter, 90);


print("Creating hunter\n")

hunter = createActor()
setName(hunter, "Hunter Smith")
setReaction(hunter, "NoState", "StateHunterStart")
setReaction(hunter, "thirsty", "StateHunterThirsty")
setReaction(hunter, "hungry", "StateHunterHungry")
moveTo(hunter, "home")

