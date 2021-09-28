#include "System.h"

// Get Long Description from Game Data json using the index
std::string GetLongDescription(entt::entity& e, entt::registry& r, json& j)
{
	std::string temp;

	auto name = r.get<SceneName>(e);
	auto ldesc = r.get<lDescIndex>(e);
	
	for (auto& array : j["Locations"]) {

		if (array["sceneName"].get<std::string>() == name.value) {

			temp = array["ldesc"][ldesc.value];
			//std::cout << array["ldesc"][ldesc.value] << "\n\n";
			break;

		}
	}

	return temp;
}

// Get Short Description from Game Data json using the index
// not currently supported
void GetShortDescription(entt::entity& e, entt::registry& r, json& j)
{
	auto name = r.get<SceneName>(e);
	auto sdesc = r.get<sDescIndex>(e);

	for (auto& array : j["Locations"]) {

		if (array["sceneName"].get<std::string>() == name.value) {

			std::cout << array["sdesc"][sdesc.value] << "\n\n";
			break;

		}
	}
}

// Get Audible Description from Game Data json using the index
// not currently supported
void GetAudibleDescription(entt::entity& e, entt::registry& r, json& j)
{
	auto name = r.get<SceneName>(e);
	auto adesc = r.get<aDescIndex>(e);

	for (auto& array : j["Locations"]) {

		if (array["sceneName"].get<std::string>() == name.value) {

			std::cout << array["adesc"][adesc.value] << "\n\n";
			break;

		}
	}
}
