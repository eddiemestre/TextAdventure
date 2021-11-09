
#include "EventHandler.h"

// Determines the direction the player should go
// TO DO
// build a more robust event system with Message Handlers and subscribers
// include retrieval and execution of any event listeners/entity listeners
void DirectionAction(const std::string& userInput, entt::entity& ent1, entt::registry& registry, const json& gameData)
{

	// grab a view of persistent objects and scene names
	auto view = registry.view<PersistentRoomObjects, SceneName>();
	bool isRoom = false;
	bool foundRoom = false;


	for (auto& e : view) {

		// check if the entity SceneName is the same as the player's
		if (view.get<SceneName>(e).value == registry.get<Position>(ent1).value) {
			isRoom = true;
			//std::cout << "Here\n";
		}

		// check if entity (room) has Persistent Bool Objects
		if (registry.has<PersistentRoomObjects>(e) && isRoom) {
			// get room's registry of persistent Objects
			auto& t = registry.get<PersistentRoomObjects>(e).objects;

			auto j = t.view<Direction, Activated, ToLocation>();

			// loop through persistent objects
			for (auto& i : j) {

				// check if it's a door type
				if (t.get<BoolType>(i).type == "door") {

					if (t.get<Direction>(i).value == userInput) {
						//std::cout << "door direction: " << j.get<Direction>(i).value << "\n";
						//std::cout << "door activated: " << j.get<Activated>(i).value << "\n";
						//std::cout << "door toLocation: " << j.get<ToLocation>(i).value << "\n\n";

						if (j.get<Activated>(i).value) {
							Position& p = registry.replace<Position>(ent1, j.get<ToLocation>(i).value);
							foundRoom = true;
							// loop through event listeners and add to a queue?
							break;
						}
					}
				}
			}

			// if no door is found
			if (!foundRoom) {
				std::cout << "no door found going " << userInput << ". Try again.\n\n";
			}
			break;
		}
	}
}
