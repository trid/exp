--
-- Created by IntelliJ IDEA.
-- User: TriD
-- Date: 24.09.2014
-- Time: 19:00
-- To change this template use File | Settings | File Templates.
--

function enter(actor)
    print("Starting my hunter's day!\n")
end

function execute(actor)
    print("I'll go to forest and hunt!\n")
    sendTo(actor, "forest", 3);
    setState(actor, "StateHunterInRoute")
end

function exit(actor)
    print("Got to do something!\n")
end

state_hunter_start = {
    enter = enter,
    execute = execute,
    exit = exit
}

print("Registered StateHunterStart\n")
registerScriptedState("StateHunterStart", "state_hunter_start")
