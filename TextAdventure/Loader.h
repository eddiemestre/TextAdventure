#pragma once

#include "Components.h"
#include <entt/entt.hpp>
#include <nlohmann/json.hpp>
#include "LocationGraph.h"

using json = nlohmann::json;


void ParseLocationData(json& j, entt::registry& r, Graph& g, bool d);

void LDescParse(json&, entt::registry& r, Graph& g, bool d);