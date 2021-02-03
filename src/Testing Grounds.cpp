#include <iostream>

#include "Plugin Utils.h"
#include "JsonClass.h"


#include "Logger.h"


// Simple Toggles For "Block Tests"
#define PLUGIN_TEST 1
#define JSON_TEST 1

int main()
{

	serenity::Logger Log("Generic Logger");
	// separate Project altogether but yeah, that's way too wordy..Definitely Should Fix That Soon...
	Log.Init("Generic Logger.txt", serenity::details::logger::LogOutput::all);
	Log.Open();

#if PLUGIN_TEST

	Log.Log("############## Plugin Functions ##############\n");
	Toggles togOption;
	std::string togStr;
	for (int i = 0; i <= static_cast<int>(Toggles::isUndefined); i++) {
		togOption = static_cast<Toggles>(i);
		togStr = TogOptionToStr(togOption);
		Log.Log("Toggle Option To String: " + togStr );
	}
	Log.Log("############## End Plugin Section ##############\n\n");

	std::cout << std::endl;
#endif


#if JSON_TEST

	Log.Log("############## Json Functions ##############\n");

	using json = nlohmann::json;

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
	Log.Log("First Json To String Explicitly Casting Values To Nodes:\n" + jsonStr + "\n\n");
	// explicit json object using a struct to set boolean values
	json_struct::JsonTestToggles tog;



	// The Sake Of Ease Of This Implementation Is REAAALLLYY Tempting - Need To Mess Around A lot More =D
	json jsonCustConvert = tog;
	auto jsonStrthree = json_functions::RandomJsonPrettyPrint(jsonCustConvert);
	Log.Log("Third Json To String Where The Struct Is Directly Cast To Json Using to_json Implementation:\n " + jsonStrthree + "\n\n");

	// Not Sure About Nested Json Values, But This Makes Life Reeeaalllyy Easy Just Using Macros =D
	json_macro_test::MacroJson macroJTest;
	json macroJson = macroJTest;
	auto jsonStr4 = json_functions::RandomJsonPrettyPrint(macroJson);
	Log.Log("Fourth Test Json Using The Json Macros To Define The to_json Implementation:\n" + jsonStr4 + "\n\n");

	// I'm sure there's a way to combine the nested json values with the ease of using a macro based to/from_json
	json combinedJsonTest =
	{
		{"Toggle Options", tog}
	};
	auto jsonStr5 = json_functions::RandomJsonPrettyPrint(combinedJsonTest);
	Log.Log("Testing Some Combined Functionality Using The Nested Json & Macro Defined to_json:\n" + jsonStr5 + "\n\n");
	// What Do Ya Know!!?? The Above Works Like How I wanted though I've no idea if that's the api
	// correct way to implement that type of use case?
	

	std::cout << std::endl;
#endif



}

