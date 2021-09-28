#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"
#include "entt/entt.hpp"

#include "Components.h"
#include "EventHandler.h"

using json = nlohmann::json;

// likely obsolete struct

//struct TreeNode {
//	std::string value;
//	std::vector<TreeNode*> children;
//
//	TreeNode();
//
//	TreeNode(std::string& s);
//
//	//TreeNode* ConstructGrammarTree();
//	//TreeNode* newNode(std::string& value);
//
//	//bool operator==(const TreeNode* n1, const TreeNode* n2);
//
//	void AddChild(TreeNode* parent, std::string& childValue);
//
//};



void ToLower(std::string& input);

void VectorizeInput(const std::string& input, std::vector<std::string>& vectorInput);

void RemoveThe(std::vector<std::string>& input);

void PopulateDicionary(std::unordered_map<std::string, std::vector<std::string>>& dictionary);

bool ValidateLanguage(std::vector<std::string>& input, std::vector<std::string>& inputGrammar, std::unordered_map<std::string, std::vector<std::string>>& dictionary);

void ConstructGrammarTree(std::map<int, std::vector<std::string>>& grammarT);

bool ConfirmGrammarPattern(std::vector<std::string>& inputGrammar, std::map<int, std::vector<std::string>>& grammarT, int& gIndex);

void LoadPlayerEntity(entt::entity& player, entt::registry& registry, json& gamedata);

void DetermineEvents(const std::vector<std::string>& userInput, const int& grammarIndex, const json& gameData, entt::entity& player, entt::registry& registry, const std::unordered_map<std::string, std::vector<std::string>>& dictionary);

void ActionObjectCompatibility(const std::vector<std::string>& userInput, const json& gameData, entt::entity& player, entt::registry& registry, const std::unordered_map<std::string, std::vector<std::string>>& dictionary);

void ObjectCompatibility(const std::vector<std::string>& userInput, const json& gameData, entt::entity& player, entt::registry& registry, const std::unordered_map<std::string, std::vector<std::string>>& dictionary);