#pragma once
#include <string>
#include <map>


namespace plugin_utils {

enum class Toggles {
	isPuddles = 0,
	isPuddleRunoff,
	isPuddleFreeze,
	IsPuddleSublimation,
	isAridOptionEnabled,
	isDryWells,
	isFlammableWood,
	isThirstIncreased,
	isDebugEnabled,
	isModEnabled,
	isUndefined
};


const std::string TogOptionToStr(Toggles toggleOption);

}