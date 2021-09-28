
#include "TextAdventure.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>



bool Game::Initialize() {

   // call all load data functions
   // if something messes up, print message and return false
    LoadData();
    firstRoomLoad = true;

    return true;
}

void Game::Shutdown() {
    // call unload data
    UnloadData();
}

void Game::LoadData() {

    fileInput.open(gameDataFilePath, std::ios::in);

    if (!fileInput) {
        std::cout << "Unable to open file: " << gameDataFilePath.c_str();
        exit(EXIT_FAILURE);
    }
    else if (fileInput && debugMode) {
        //std::cout << "File " << gameDataFilePath.c_str() << " openned successfully.\n";
    }

    GameData = json::parse(fileInput);
    // std::cout << GameData;

     // wrap in game data setter function
    if (!GameData.empty() && debugMode) {
        //std::cout << "Game Data loaded successfully\n";
    }
    else if (GameData.empty() && debugMode) {
        std::cout << "Game Data not loaded to json\n";
        exit(EXIT_FAILURE);
    }

    // load language
    PopulateDicionary(dictionary);
    ConstructGrammarTree(grammarTree);

    // create locations & doors
    ParseLocationData(GameData, registry, locationGraph, debugMode);

    // create player entity
    LoadPlayerEntity(player, registry, GameData);

    // to do: create NPCs and Enemies

    // to do: create items 

}

void Game::UnloadData() {
    // delete or close or save data
}


void Game::ProcessInput() {
    
    // ensure there is no previous input in vectors
    if (vectorInput.size() != 0) {
        vectorInput.clear();
    }
    if (inputGrammar.size() != 0) {
        inputGrammar.clear();
    }
    if (vectorOutput.size() != 0) {
        vectorOutput.clear();
    }

    // language and grammar checks
    bool validLanguage = false;
    bool validGrammar = false;

    // get player input
    std::string userInput;
    std::getline(std::cin, userInput);

    // temporary formatter
    std::cout << "\n";

    // lowercase input
    ToLower(userInput);

    //std::cout << userInput << '\n';

    // temporary exit solution
    if (userInput == "exit") {
        std::cout << "Thanks for playing\n";
        exit(EXIT_SUCCESS);
    }

    // place input into vector
    VectorizeInput(userInput, vectorInput);

    // remove any mention of "the" from input
    RemoveThe(vectorInput);

    // validate language


    if (!ValidateLanguage(vectorInput, inputGrammar, dictionary)) {
        // words or grammar aren't recognized, encourage user to retry input
        // short term solution to incorrect input
        vectorOutput.emplace_back("Come again?\n");
    }
    else {
        //std::cout << "valid language\n";
        validLanguage = true;
    }

    // //validate grammar
    if (!ConfirmGrammarPattern(inputGrammar, grammarTree, grammarIndex)) {
        if (validLanguage) {
            // short term solution to incorrect input
            vectorOutput.emplace_back("Come again?\n");
        }
    }
    else {
        //std::cout << "valid grammar\n";
        validGrammar = true;
    }


    //std::cout << grammarIndex << "\n";

    // determine event to add to event queue (by checking the action word and relation of userInput words)
    if (validLanguage && validGrammar) {
        DetermineEvents(vectorInput, grammarIndex, GameData, player, registry, dictionary);
    }

    // To Dos
    // write event system
    // events are executed in the UpdateGame function
    // the results are rendered in the GenerateOutput function

}

void Game::UpdateGame() {

    // handle event execution and game state changes

    // more temporary solution to game output
    // bool to check if player was in same location last loop
    bool wasHereLastLoop = false;

    if (previousRoom != "" && previousRoom == registry.get<Position>(player).value) {
        wasHereLastLoop = true;
    }

    auto t = registry.view<SceneName, lDescIndex, sDescIndex, aDescIndex>();

    for (auto i : t) {

        if (t.get<SceneName>(i).value == registry.get<Position>(player).value) {

            if (!wasHereLastLoop) {
                vectorOutput.emplace_back(GetLongDescription(i, registry, GameData));
                //GetShortDescription(i, registry, GameData);
                //GetAudibleDescription(i, registry, GameData);

                //auto name = t.get<SceneName>(i);
                //auto ldesc = t.get<lDescIndex>(i);
                //auto sdesc = t.get<sDescIndex>(i);
                //auto adesc = t.get<aDescIndex>(i);

                //std::cout << name.value << "\n";
                //std::cout << ldesc.value << "\n";
                //std::cout << sdesc.value << "\n";
                //std::cout << adesc.value << "\n";
                break;
            }
        }
    }


    // set previousRoom to this room
    previousRoom = registry.get<Position>(player).value;
    

}

void Game::GenerateOutput() {

    // what about:
    // displaying opening game info?
    // playing jingle?

    // this should loop through a queue of text entries to present relevant information to the player
    // eventually need to include the opening text for certain events "You are in.... the living room", "You hear .... sounds of", etc.
    for (auto& a : vectorOutput) {
        std::cout <<  a << "\n\n";
    }

    if (firstRoomLoad) {
        firstRoomLoad = false;
    }

}

void Game::NewGame() {

}


void Game::RunLoop()
{

    // how do we handle new game?
    // present some info to the user before we load the game? (title, copywrite, etc)

    while (runLoop) {
        if (!firstRoomLoad) {
            ProcessInput();     // get & check player Input, if valid, add valid events to queue, if not, add invalid event to queue, populate the event queue
        }
        UpdateGame();   // execute the event queue (if invalid input, should be event for that)
        GenerateOutput();   // render to screen 
    }
}