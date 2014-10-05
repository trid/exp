--
-- User: TriD
-- Date: 03.10.2014
-- Time: 16:30
--

print("Creating woodcutter")

woodcutter = createActor()
setName(woodcutter, "John Wood")
setState(woodcutter, "StateStart")
moveTo(woodcutter, "home")

print("Creating hunter")

hunter = createActor()
setName(hunter, "Hunter Smith")
setState(hunter, "StateHunterStart")
moveTo(hunter, "home")