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
	// separate Project altogether but yeah, that's way too wordy..
	Log.Init("Generic Logger.txt", serenity::details::logger::LogOutput::all);
	Log.Open();

#if PLUGIN_TEST

	Log.Log("############## Plugin Functions ##############");
	Toggles togOption;
	std::string togStr;
	for (int i = 0; i <= static_cast<int>(Toggles::isUndefined); i++) {
		togOption = static_cast<Toggles>(i);
		togStr = TogOptionToStr(togOption);
		Log.Log("Toggle Option To String: " + togStr);
	}

	std::cout << std::endl;
#endif


#if JSON_TEST

	Log.Log("############## Json Functions ##############");

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
	Log.Log("First Json To String Explicitly Casting Values To Nodes:\n" + jsonStr);
	Log.Log("New Line\n");
	// explicit json object using a struct to set boolean values
	json_struct::JsonTestToggles tog;
	json togg = {
		{"Toggle Options",
		{
			{"isAridOptionEnabled", tog.aridOptionEnabled},
			{"isDebugEnabled", tog.debugEnabled},
			{"isModEnabled", tog.modEnabled},
			{"isThirstIncreased", tog.thirstEnabled},
			{"isDryWells", tog.dryWellsEnabled},
			{"isFlammableWood", tog.flammableWoodEnabled},
			{"isPuddles", tog.puddlesEnabled},
			{"isPuddleRunoff", tog.puddleRunoffsEnabled},
			{"isPuddleFreeze", tog.puddleFreezeEnabled},
			{"isPuddleSublimation", tog.puddleSublimationEnabled}
		}
		}
	};
	auto jsonStrtwo = json_functions::RandomJsonPrettyPrint(togg);
	Log.Log("Second Json To String Casting Struct Values To Nodes:\n " + jsonStrtwo);
	Log.Log("New Line\n");

	// The Sake Of Ease Of This Implementation Is REAAALLLYY Tempting - Need To Mess Around A lot More =D
	json jsonCustConvert = tog;
	auto jsonStrthree = json_functions::RandomJsonPrettyPrint(jsonCustConvert);
	Log.Log("Third Json To String Where The Struct Is Directly Cast To Json Using to_json Implementation:\n " + jsonStrthree);
	Log.Log("New Line\n");


	std::cout << std::endl;
#endif



}

