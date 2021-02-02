#pragma once
#include <string>
#include <map>

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


const std::string TogOptionToStr(Toggles toggleOption)
{
	std::string toggleStr;
	std::map<Toggles, std::string> toggleMap = {
	  {Toggles::isModEnabled, "isModEnabled"},
	  {Toggles::isDebugEnabled, "isDebugEnabled"},
	  {Toggles::isAridOptionEnabled, "isAridOptionEnabled"},
	  {Toggles::isThirstIncreased, "isThirstIncreased"},
	  {Toggles::isDryWells, "isDryWells"},
	  {Toggles::isFlammableWood, "isFlammableWood"},
	  {Toggles::isPuddles, "isPuddles"},
	  {Toggles::isPuddleRunoff, "isPuddleRunoff"},
	  {Toggles::isPuddleFreeze, "isPuddleFreeze"},
	  {Toggles::IsPuddleSublimation, "IsPuddleSublimation"},
		{Toggles::isUndefined, "isUndefined"}
	};
	if (toggleMap.contains(toggleOption)) {
		toggleStr = toggleMap[toggleOption];
	}
	else {
		toggleStr = "UNDEFINED";
	}
	return toggleStr;
}
