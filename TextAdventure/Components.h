#pragma once

#include <string>
#include <vector>
#include "entt/entt.hpp"
#include "Components.h"

// A list of all Components in the system. These Components make up the entirety
// of the game data

// Scene Name
struct SceneName {
	std::string value;

	SceneName(std::string& value);
};

// Location bool
struct Location {
	bool value = true;
};

// Entity Name
struct Name {
	std::string value;
	Name(std::string& value);
};

// Long Description index - we use this index to pull the appropriate
// long description from the game data
struct lDescIndex {
	int value;

	lDescIndex() = default;

	lDescIndex(int i);
};

// Short Description index - we use this index to pull the appropriate
// short description from the game data
struct sDescIndex {
	int value;

	sDescIndex() = default;

	sDescIndex(int i);
};

// Audio Description index - we use this index to pull the appropriate
// audio description from the game data
struct aDescIndex {
	int value;

	aDescIndex() = default;

	aDescIndex(int i);
};

// a list of all a location's items
struct LocItems {
	std::vector<entt::entity> here;
	//std::vector<entt::entity> notHere; // obsolete?
};

// a list of all a location's NPCs
struct LocNPCs {
	std::vector<entt::entity> here;
	//std::vector<entt::entity> notHere;	// obsolete?
};

// a list of all a location's enemies
struct LocEnemies {
	std::vector<entt::entity> here;
	//std::vector<entt::entity> notHere;	// obsolete?
};

// a registry of room entities that do not change (doors, permanent objects, etc)
struct PersistentRoomObjects {
	entt::registry objects;
};

// Bool Type - for entities and objects that have bool flags
struct BoolType {
	std::string type;

	BoolType(std::string& type);
};

// Array of events attached to specific entities
// This may change once the event system is developed
struct EventArray {
	std::vector<std::string> value;

	EventArray() = default;

	EventArray(std::string& s);
};

// A bool specifically for determining if an entity/object is activated
struct Activated {
	bool value;

	Activated(bool b);
};

// A bool to determine if an entity/object should be rendered
struct Render {
	bool value;

	Render(bool b);
};

// Directions for navigation
struct Direction {
	std::string value;

	Direction(std::string& value);
};

// A To Location for navigation
struct ToLocation {
	std::string value;

	ToLocation(std::string& value);
};

// Position of entities
struct Position {
	std::string value;

	Position(std::string& position);
};

// Inventory of entities - vector of entities
// (items are entities)
struct Inventory {
	std::vector<entt::entity> value;
};

// Dialogue queue
struct DialogueQueue {
	std::vector<std::string> value;
	int index;
};

// Event queue - may change depending on implementation
// of event system
struct EventQueue {
	std::vector<std::string> value;
};


