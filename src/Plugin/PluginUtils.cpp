#include "Plugin/PluginUtils.h"

namespace options {

	const std::string TogOptionToStr(toggles toggleOption)
	{
		std::string togglestr;
		std::map<toggles, std::string> toggleMap = {
		  {toggles::isModEnabled, "isModEnabled"},
		  {toggles::isDebugEnabled, "isDebugEnabled"},
		  {toggles::isAridOptionEnabled, "isAridOptionEnabled"},
		  {toggles::isThirstIncreased, "isThirstIncreased"},
		  {toggles::isDryWells, "isDryWells"},
		  {toggles::isFlammableWood, "isFlammableWood"},
		  {toggles::isPuddles, "isPuddles"},
		  {toggles::isPuddleRunoff, "isPuddleRunoff"},
		  {toggles::isPuddleFreeze, "isPuddleFreeze"},
		  {toggles::IsPuddleSublimation, "IsPuddleSublimation"},
			{toggles::isUndefined, "isUndefined"}
		};
		if (toggleMap.contains(toggleOption)) {
			togglestr = toggleMap[toggleOption];
		}
		else {
			togglestr = "UNDEFINED";
		}
		return togglestr;
	}

	const std::string SliderOptionToStr(sliders sliderOption) {
		std::string sliderStr;
		std::map<sliders, std::string> sliderMap = {
		  {sliders::thirstIncrease, "thirstIncrease"},
		  {sliders::thirstIncreaseForActions, "thirstIncreaseForActions"},
		  {sliders::thirstIncreaseForNeeds, "thirstIncreaseForNeeds"},
		  {sliders::isUndefined, "isUndefined"}
		};
		if (sliderMap.contains(sliderOption)) {
			sliderStr = sliderMap[sliderOption];
		}
		else {
			sliderStr = "UNDEFINED";
		}
		return sliderStr;
	}

	const std::string MenuOptionsToStr(menuOptions menuItem) {
		std::string menuItemStr;
		std::map<menuOptions, std::string> menuMap = {
			{menuOptions::presetList, "presetList"},
			{menuOptions::defaultPreset, "defaultPreset"},
			{menuOptions::scriptFriendlyPreset, "scriptFriendlyPreset"},
			{menuOptions::realisticPreset, "realisticPreset"},
			{menuOptions::idealisticPreset, "idealisticPreset"},
			{menuOptions::allTheThingsPreset, "allTheThingsPreset"},
			{menuOptions::isUndefined, "isUndefined"}
		};
		if (menuMap.contains(menuItem)) {
			menuItemStr = menuMap[menuItem];
		}
		else {
			menuItemStr = "UNDEFINED";
		}
		return menuItemStr;
	}


}