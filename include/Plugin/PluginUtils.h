#pragma once
#include <string>
#include <map>


namespace options {

	enum class toggles {
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

	enum class sliders {
		thirstIncrease = 0,
		thirstIncreaseForActions,
		thirstIncreaseForNeeds,
		isUndefined
	};

	enum class menuOptions{
		presetList = 0,
		defaultPreset,
		realisticPreset,
		idealisticPreset,
		scriptFriendlyPreset,
		allTheThingsPreset,
		isUndefined
	};



	const std::string TogOptionToStr(toggles toggleOption);
	const std::string SliderOptionToStr(sliders sliderOption);
	const std::string MenuOptionsToStr(menuOptions menuItem);
}