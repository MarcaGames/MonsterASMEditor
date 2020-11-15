local currentPath, verbose = ...

local globalApp = require("premake/app")

local app = globalApp.app("MonsterASMEditor", currentPath, verbose)

globalApp.addState(app, { filter = "system:linux", premakeState = function()
	linkoptions { "-pthread -Wl, -rpath=\\$$ORIGIN" }
	links { "dl" }
end}, verbose)
globalApp.addState(app, { filter = "system:ios", premakeState = function()
	files {
		app.currentPath .. app.resourceDir .. "Info.plist",
		app.currentPath .. app.resourceDir
	}
end}, verbose)
globalApp.addState(app, { filter = { "system:macosx or ios", "files:**.cpp" }, premakeState = function()
	compileas "Objective-C++"
end}, verbose)
globalApp.addState(app, { filter = "configurations:Debug", premakeState = function()
	kind "ConsoleApp"
end}, verbose)
globalApp.addState(app, { filter = "configurations:Release", premakeState = function()
	kind "WindowedApp"
end}, verbose)
app.kind = "ConsoleApp"

return app