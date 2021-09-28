#pragma once

#include <string>
#include <vector>
#include "entt/entt.hpp"
#include "Components.h"

struct SceneName {
	std::string value;

	SceneName(std::string& value);
};

struct Location {
	bool value = true;
};

struct Name {
	std::string value;
	Name(std::string& value);
};

struct lDescIndex {
	int value;

	lDescIndex() = default;

	lDescIndex(int i);
};

struct sDescIndex {
	int value;

	sDescIndex() = default;

	sDescIndex(int i);
};

struct aDescIndex {
	int value;

	aDescIndex() = default;

	aDescIndex(int i);
};

struct LocItems {
	std::vector<entt::entity> here;
	//std::vector<entt::entity> notHere; // obsolete?
};

struct LocNPCs {
	std::vector<entt::entity> here;
	//std::vector<entt::entity> notHere;	// obsolete?
};

struct LocEnemies {
	std::vector<entt::entity> here;
	//std::vector<entt::entity> notHere;	// obsolete?
};

struct PersistentRoomObjects {
	entt::registry objects;
};

struct BoolType {
	std::string type;

	BoolType(std::string& type);
};

struct EventArray {
	std::vector<std::string> value;

	EventArray() = default;

	EventArray(std::string& s);
};

struct Activated {
	bool value;

	Activated(bool b);
};

struct Render {
	bool value;

	Render(bool b);
};

struct Direction {
	std::string value;

	Direction(std::string& value);
};

struct ToLocation {
	std::string value;

	ToLocation(std::string& value);
};

struct Position {
	std::string value;

	Position(std::string& position);
};

struct Inventory {
	std::vector<entt::entity> value;
};

struct DialogueQueue {
	std::vector<std::string> value;
	int index;
};

struct EventQueue {
	std::vector<std::string> value;
};


