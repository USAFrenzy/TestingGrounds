#pragma once

#include <string>
#include "nlohmann/json.hpp"

// https://github.com/nlohmann/json#examples

/*
	For The Use Case Of Skyrim:
	Might be able to go ahead and create a struct of json objects and then
	somehow parse the json nodes to read/write values to those nodes?
	Then in the config namespace of the plugin, add the json structures and
	functions to be able to use the configuration types that are converted to strings
	and then parsed by json to find the nodes and read/write the values to those nodes?
*/
using json = nlohmann::json;

namespace json_functions {

	std::string RandomJsonPrettyPrint(json objectDump);

}

namespace json_struct {



	struct JsonTestToggles
	{
		bool modEnabled = true;
		bool debugEnabled = false;
		bool aridOptionEnabled = true;
		bool thirstEnabled = true;
		bool dryWellsEnabled = true;
		bool flammableWoodEnabled = true;
		bool puddlesEnabled = true;
		bool puddleRunoffsEnabled = true;
		bool puddleFreezeEnabled = true;
		bool puddleSublimationEnabled = true;

	};
	// Got Rid Of The More Controlled to_json Implementation For The Macro - Don't Believe I'd be doing anything more than serializing/deserializing	
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(JsonTestToggles, modEnabled, debugEnabled, aridOptionEnabled, thirstEnabled,
		dryWellsEnabled, flammableWoodEnabled, puddlesEnabled, puddleRunoffsEnabled,
		puddleFreezeEnabled, puddleSublimationEnabled)

}

namespace json_macro_test
{
	struct MacroJson {
		std::string baseNodeTitle{ "Default Explicit Node Base Name" };
		int lineNumber{ 0 };
		std::string nodeValue{ "Default Explicit Node Value" };
	};

	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MacroJson, baseNodeTitle, lineNumber, nodeValue)

}