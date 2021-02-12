#include <iostream>

// Plugin Sand-boxing Files
#include "Plugin/PluginUtils.h"
// Json Sand-boxing Files
#include "Json/JsonClass.h"
// Logger Files (May Use To Sandbox)
#include "Logger/Logger.h"


// Simple toggles For "Block Tests"
#define PLUGIN_TEST 1
#define JSON_TEST 1

// Individual Plugin Sandbox Sections
#define PLUGIN_HELPERS 1

// Individual Json Sandbox Sections
#define JSON_TO_FROM 1 // De/Serializing In JSON
#define  JSON_PLUGIN 1 // Tying In Some Plugin Functions To De/Serialize In JSON


int main()
{

	serenity::Logger genericLog("Generic Logger");
	// separate Project altogether but yeah, that's way too wordy..Definitely Should Fix That Soon...
	genericLog.Init("Logs", "GenericLogger.txt", serenity::details::logger::LogOutput::all);
	genericLog.Open();
	genericLog.Log("Running Sandbox Events");


#if PLUGIN_TEST
	genericLog.Log("Running Plugin Sandbox Events");


	serenity::Logger pluginLog("Plugin Logger");
	pluginLog.Init("Logs", "PluginLogger.txt", serenity::details::logger::LogOutput::all);
	// just for convenience
	using namespace options;
	pluginLog.Log("############## Plugin Section ##############\n\n");
#if PLUGIN_HELPERS
	pluginLog.Log("Plugin Helper Sandboxing:\n");
	toggles togOption;
	std::string togStr;
	for (int i = 0; i <= static_cast<int>(toggles::isUndefined); i++) {
		togOption = static_cast<toggles>(i);
		togStr = TogOptionToStr(togOption);
		pluginLog.Log("Toggle Option To String: " + togStr);
	}

	std::cout << std::endl;

	genericLog.Log("Finished Plugin Sandbox Events");
#endif PLUGIN_HELPERS

#endif // PLUGIN_TEST


#if JSON_TEST
	genericLog.Log("Running Json Sandbox Events");

	serenity::Logger jsonLog("Json Logger");
	jsonLog.Init("Logs", "JsonLogger.txt", serenity::details::logger::LogOutput::all);


	jsonLog.Log("############## Json Functions ##############");

	using json = nlohmann::json;
#if JSON_TO_FROM

	genericLog.Log("Running Json to/from_json Sandbox Events\n");


	json jsonTest;

	// explicit json object 
	jsonTest["Toggle Options"]["isModEnabled"] = true;
	jsonTest["Toggle Options"]["isDebugEnabled"] = false;
	jsonTest["Toggle Options"]["isAridOptionEnabled"] = true;
	jsonTest["Toggle Options"]["isThirstIncreased"] = true;
	jsonTest["Toggle Options"]["isDryWells"] = false;
	jsonTest["Toggle Options"]["isFlammableWood"] = true;
	jsonTest["Toggle Options"]["isPuddles"] = true;
	jsonTest["Toggle Options"]["isPuddleRunoff"] = true;
	jsonTest["Toggle Options"]["isPuddleFreeze"] = true;
	jsonTest["Toggle Options"]["isPuddleSublimation"] = true;
	std::string jsonStr;
	jsonStr = json_functions::RandomJsonPrettyPrint(jsonTest);
	jsonLog.Log("First Json To String Explicitly Casting Values To Nodes:\n" + jsonStr + "\n\n");
	// explicit json object using a struct to set boolean values
	json_struct::JsonTesttoggles tog;



	// The Sake Of Ease Of This Implementation Is REAAALLLYY Tempting - Need To Mess Around A lot More =D
	json jsonCustConvert = tog;
	auto jsonStrthree = json_functions::RandomJsonPrettyPrint(jsonCustConvert);
	jsonLog.Log("Third Json To String Where The Struct Is Directly Cast To Json Using to_json Implementation:\n " + jsonStrthree + "\n\n");

	// Not Sure About Nested Json Values, But This Makes Life Reeeaalllyy Easy Just Using Macros =D
	json_macro_test::MacroJson macroJTest;
	json macroJson = macroJTest;
	auto jsonStr4 = json_functions::RandomJsonPrettyPrint(macroJson);
	jsonLog.Log("Fourth Test Json Using The Json Macros To Define The to_json Implementation:\n" + jsonStr4 + "\n\n");

	// I'm sure there's a way to combine the nested json values with the ease of using a macro based to/from_json
	json combinedJsonTest =
	{
		{"Toggle Options", tog}
	};
	auto jsonStr5 = json_functions::RandomJsonPrettyPrint(combinedJsonTest);
	jsonLog.Log("Testing Some Combined Functionality Using The Nested Json & Macro Defined to_json:\n" + jsonStr5 + "\n\n");
	// What Do Ya Know!!?? The Above Works Like How I wanted though I've no idea if that's the api
	// correct way to implement that type of use case?
	genericLog.Log("Finished Json to/from_json Sandbox Events");


#endif // JSON_TO_FROM

#if JSON_PLUGIN // Json De/serializing of "plugin's" data
	jsonLog.Log("Running Plugin Data De/Serializing To JSON Sandbox Events\n");

	// Write Some Sandbox, Tests, Etc here



	jsonLog.Log("Finished Plugin Data De/Serializing To JSON Sandbox Events\n");
#endif JSON_PLUGIN




	genericLog.Log("Finished Json Sandbox Events");
#endif // JSON_TEST






	genericLog.Log("Finished All Sandbox Events");
}

