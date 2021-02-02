#include <iostream>

#include "Plugin Utils.h"
#include "JsonClass.h"



// Simple Toggles For "Block Tests"
#define PLUGIN_TEST 1
#define JSON_TEST 1

int main()
{


#if PLUGIN_TEST

	std::cout << "############## Plugin Functions ##############" << std::endl;
	Toggles togOption;
	std::string togStr;
	for (int i = 0; i <= static_cast<int>(Toggles::isUndefined); i++) {
		togOption = static_cast<Toggles>(i);
		togStr = TogOptionToStr(togOption);
		std::cout << "Toggle Option To String: " << togStr << std::endl;
	}

	std::cout << std::endl;
#endif


#if JSON_TEST
	std::cout << "############## Json Functions ##############" << std::endl;

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
	std::cout << "First Json To String Explicitly Casting Values To Nodes:\n" <<jsonStr << std::endl;

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
	std::cout << "Second Json To String Casting Struct Values To Nodes:\n " << jsonStrtwo << std::endl;

	// The Sake Of Ease Of This Implementation Is REAAALLLYY Tempting - Need To Mess Around A lot More =D
	json jsonCustConvert = tog;
	auto jsonStrthree = json_functions::RandomJsonPrettyPrint(jsonCustConvert);
	std::cout << "Third Json To String Where The Struct Is Directly Cast To Json Using to_json Implementation:\n " << jsonStrthree << std::endl;


	std::cout << std::endl;
#endif



}

