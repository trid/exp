--
-- User: TriD
-- Date: 03.10.2014
-- Time: 16:30
--

print("Creating woodcutter\n")

woodcutter = createActor()
setName(woodcutter, "John Wood")
setState(woodcutter, "StateStart")
moveTo(woodcutter, "home")

print("Creating hunter\n")

hunter = createActor()
setName(hunter, "Hunter Smith")
setState(hunter, "StateHunterStart")
moveTo(hunter, "home")

print("Loading scene objects\n")

createSceneObject(400, 300, "res/img/home.png", "home")
createSceneObject(500, 0, "res/img/trees.png", "forest")
createSceneObject(200, 200, "res/img/well.png", "well")