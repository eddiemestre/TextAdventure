#pragma once

#include <nlohmann/json.hpp>
#include <entt/entt.hpp>

#include <unordered_map>
#include <string>
#include <vector>
#include <map>

#include "Components.h"
#include "Loader.h"
#include "LocationGraph.h"
#include "System.h"
#include "Parser.h"

using json = nlohmann::json;

const std::string gameDataFilePath = "../Assets/GameData.json";

const bool debugMode = true;


struct Game
{

	bool Initialize();

	void UnloadData();

	void LoadData();

	void RunLoop();

	void Shutdown();

	void ProcessInput();

	void UpdateGame();

	void GenerateOutput();

	void NewGame();


	std::ifstream fileInput;
	json GameData;
	entt::registry registry;
	bool newGame = true;
	bool runLoop = true;
	bool firstRoomLoad;
	int grammarIndex;
	std::string previousRoom;

	entt::entity player = registry.create();

	std::vector<std::string> vectorInput;
	//std::string userInput;

	std::vector<std::string> vectorOutput;

	
	Graph locationGraph;
	//std::unordered_map<std::string, std::pair<std::string, std::string>> dictionary;
	std::unordered_map <std::string, std::vector<std::string>> dictionary;
	//std::vector<std::vector<std::string>> grammarTree;
	std::map<int, std::vector<std::string>> grammarTree;
	std::vector<std::string> inputGrammar;
};
