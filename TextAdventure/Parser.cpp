#include "Parser.h"

const std::string DICTIONARY_JSON = "../Assets/Dictionary.json";

// Converts input to lowercase
void ToLower(std::string& input) {
	// convert string to lowercase
	std::for_each(input.begin(), input.end(), [](char& c) {
		c = ::tolower(c);
	});
}

// uses a ' ' delimiter to parse the input string into a vector
// of strings each string being one word in length
void VectorizeInput(const std::string& input, std::vector<std::string>& vectorInput) {
	size_t start = 0;
	std::string delim = " ";
	size_t end = input.find(delim);

	while (end != std::string::npos) {
		vectorInput.push_back(input.substr(start, end - start));
		start = end + delim.length();
		end = input.find(delim, start);
	}

	vectorInput.push_back(input.substr(start, end));
}

// Removes "the" from the input vector (unnecessary word)
void RemoveThe(std::vector<std::string>& input)
{
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == "the") {
			input.erase(input.begin() + i);
		}
	}
}

// 
void PopulateDicionary(std::unordered_map<std::string, std::vector<std::string>>& dictionary)
{
	std::ifstream input(DICTIONARY_JSON);

	// invalidate input file
	if (!input) {
		std::cout << "Unable to open file: " << DICTIONARY_JSON.c_str() << "\n";
		exit(EXIT_FAILURE);
	}
	// valid
	else if (input) {
		//std::cout << "File " << DICTIONARY_JSON.c_str() << " openned successfully.\n";
	}

	json Dictionary = json::parse(input);

	// validate json file
	if (!Dictionary.empty()) {
		//std::cout << "Dictionary loaded successfully\n";
	}
	else if (Dictionary.empty()) {
		std::cout << "Dictionary not loaded to json\n";
		exit(EXIT_FAILURE);
	}

	// strings for master word and part of speech
	std::string masterWord;
	std::string pos;
	std::string wordType;

	// loops through the dictionary and populates the dictionary map with 
	// the masterword name, it's part of speech, and its word type
	// all of these are important for understanding grammar later
	for (auto& array : Dictionary["Dictionary"]) {

		masterWord = array["name"];
		pos = array["pos"];
		wordType = array["type"];

		std::vector<std::string> dictionaryVec = { masterWord, pos, wordType };

		// add master word to dictionary
		dictionary[masterWord] = dictionaryVec;

		// add synoyms to dictionary
		for (auto& a : array["syns"]) {
			dictionary[a] = dictionaryVec;
		}
	}

}

// Validates that each word in input matches to a word in the dictionary
// returns true if all words in input match dictionary
// returns false otherwise
bool ValidateLanguage(std::vector<std::string>& input, std::vector<std::string>& inputGrammar, std::unordered_map<std::string, std::vector<std::string>>& dictionary)
{
	bool valid = true;

	// validates input is in dictionary
	for (auto& i : input) {
		std::unordered_map<std::string, std::vector<std::string>>::const_iterator it = dictionary.find(i);
		if (it == dictionary.end()) {
			valid = false;
			return valid;
		}
		else {
			// replace input words with master words
			std::replace(input.begin(), input.end(), i, it->second[0]);
			inputGrammar.push_back(it->second[1]);
		}
	}

	return valid;
}

// constructs a grammar tree based on defined grammar strctures in Dictionary.json
void ConstructGrammarTree(std::map<int, std::vector<std::string>>& grammarT)
{
	std::ifstream input(DICTIONARY_JSON);

	json Dictionary = json::parse(input);

	std::string s = "action";

	std::vector<std::string> temp;
	int index;

	for (auto& array : Dictionary["Grammar"]) {
		temp.clear();

		if (array.contains("index_id")) {
			index = array.at("index_id");
		}

		for (auto& x : array["tree"]) {
			temp.push_back(x);
		}

		grammarT[index] = temp;
	}
}

// Validates that user input matches a grammar definition
bool ConfirmGrammarPattern(std::vector<std::string>& inputGrammar, std::map<int, std::vector<std::string>>& grammarT, int& gIndex){

	bool valid = false;

	// validates grammar Tree 
	int grammarIndex = 0;
	int posIndex = 0;

	for (auto& i : grammarT) {
		grammarIndex = 0;
		posIndex = 0;

		if (i.second.size() == inputGrammar.size()) {
			while (i.second[grammarIndex] == inputGrammar[posIndex]) {
				grammarIndex++;
				posIndex++;

				if (posIndex == inputGrammar.size() && grammarIndex == i.second.size()) {
					valid = true;
					gIndex = i.first;
					return valid;
				}
			}
		}

	}

	return valid; 

}

// load player entity data from json
void LoadPlayerEntity(entt::entity& player, entt::registry& registry, json& gamedata)
{
	// Player Position
	if (gamedata["Player"].contains("position")) {
		auto pos = gamedata["Player"].at("position").get<std::string>();
		registry.emplace<Position>(player, pos);
	}

	// Other Player Attributes go here

}

// Determine Events to run based on user input
// TO DO: develop this into a robust event system
void DetermineEvents(const std::vector<std::string>& userInput, const int& grammarIndex, const json& gameData, entt::entity& player, entt::registry& registry, const std::unordered_map<std::string, std::vector<std::string>>& dictionary)
{

	switch (grammarIndex) {

	case 0 :
		//std::cout << "action object\n";
		// determine if there is a relationship between these two words
		ActionObjectCompatibility(userInput, gameData, player, registry, dictionary); 
		break;
	case 1 :
		std::cout << "action object pronoun object\n";
		break;
	case 2:
		std::cout << "action pronoun object\n";
		break;
	case 3:
		std::cout << "action object object\n";
		break;
	case 4:
		//std::cout << "object\n";
		// determine if this makes sense
		ObjectCompatibility(userInput, gameData, player, registry, dictionary);
		break;
	default:
		std::cout << "invalid, make sure grammar case is added to DetermineEvents function in Parse.cpp\n";
		exit(EXIT_FAILURE);
	}
}

// determine events to run under case 0
// potentially temporary - need to develop more robust event system
void ActionObjectCompatibility(const std::vector<std::string>& userInput, const json& gameData, entt::entity& player, entt::registry& registry, const std::unordered_map<std::string, std::vector<std::string>>& dictionary)
{

	// go event
	if (userInput[0] == "go") {
		std::unordered_map<std::string, std::vector<std::string>>::const_iterator it = dictionary.find(userInput[1]);
		if (it->second[2] == "direction") {
			DirectionAction(it->second[0], player, registry, gameData);
		}
	}

	// other events
}

// determine events to run under case 4
void ObjectCompatibility(const std::vector<std::string>& userInput, const json& gameData, entt::entity& player, entt::registry& registry, const std::unordered_map<std::string, std::vector<std::string>>& dictionary)
{
	// check if this is a direction
	std::unordered_map<std::string, std::vector<std::string>>::const_iterator it = dictionary.find(userInput[0]);
	
	// if input is direction
	if (it->second[2] == "direction") {
		DirectionAction(it->second[0], player, registry, gameData);
		// do I loop through event queue here?
	}

}

// below is likely obsolete

//TreeNode::TreeNode()
//{
//}
//
//TreeNode::TreeNode(std::string& s)
//	:value(s)
//{
//}
//
//
//TreeNode* TreeNode::newNode(std::string& value)
//{
//	TreeNode* node = new TreeNode(value);
//	return node;
//}
//
//void TreeNode::AddChild(TreeNode* parent, std::string& childValue)
//{
//	TreeNode* temp = new TreeNode(childValue);
//	parent->children.push_back(temp);
//}

// obsolete?
//TreeNode* newNode(std::string& value) {
//	TreeNode* temp = new TreeNode;
//	temp->value = value;
//	return temp;
//}
//
//void AddChild(TreeNode* parent, std::string& childValue) {
//	TreeNode* child = new TreeNode;
//	for (auto& i : parent->children) {
//		if (i->value == childValue) {
//			return;
//		}
//	}
//	child->value = childValue;
//	parent->children.emplace_back(child);
//}