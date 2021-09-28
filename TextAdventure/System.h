#pragma once

#include "Components.h"
#include <string>
#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include <iostream>

using json = nlohmann::json;

std::string GetLongDescription(entt::entity& e, entt::registry& r, json& j);

void GetShortDescription(entt::entity& e, entt::registry& r, json& j);

void GetAudibleDescription(entt::entity& e, entt::registry& r, json& j);