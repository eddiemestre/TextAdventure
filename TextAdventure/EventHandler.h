#pragma once

#include <entt/entt.hpp>
#include <nlohmann/json.hpp>

#include "Components.h"

#include <string>
#include <iostream>

using json = nlohmann::json;


void DirectionAction(const std::string& userInput, entt::entity& ent1, entt::registry& registry, const json& gameData);