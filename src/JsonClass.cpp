#include "JsonClass.h"


namespace json_functions {


	std::string RandomJsonPrettyPrint(json objectDump)
	{
		std::string tmp = objectDump.dump(2);
		return tmp;
	}


}


namespace json_struct {


	void to_json(json& j, const JsonTestToggles& t)
	{
		j = json{
		{"Toggle Options",
		{
			{"isAridOptionEnabled", t.aridOptionEnabled},
			{"isDebugEnabled", t.debugEnabled},
			{"isModEnabled", t.modEnabled},
			{"isThirstIncreased", t.thirstEnabled},
			{"isDryWells", t.dryWellsEnabled},
			{"isFlammableWood", t.flammableWoodEnabled},
			{"isPuddles", t.puddlesEnabled},
			{"isPuddleRunoff", t.puddleRunoffsEnabled},
			{"isPuddleFreeze", t.puddleFreezeEnabled},
			{"isPuddleSublimation", t.puddleSublimationEnabled}
		}
		}
		};
	}
}