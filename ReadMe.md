# Text Adventure

Text-based RPG game in the vein of [Colossal Cave Adventure](https://en.wikipedia.org/wiki/Colossal_Cave_Adventure). The game utilizes [EnTT](https://github.com/skypjack/entt) and [Nlohmann Json](https://github.com/nlohmann/json) for a robust entity component system and json parsing. 
 
## Feature List

Current features are limited as the project is in its infancy. Support exists for the following: 
- Room traversal

## Project Roadmap
- [x] General system design and json parsing
- [x] Define grammar syntax and game vocabulary
- [x] Support room traversal across a series of connected locations
- [ ] Build a robust Event System for easy listening/executing of events
- [ ] Build support for character dialogue, item collection, and bool events (i.e. unlocking a chest or door)
- [ ] Enemy entity support
- [ ] Entity stats
- [ ] Combat System
- [ ] Develop a more robust rendering environment likely using [NCurses](https://en.wikipedia.org/wiki/Ncurses) or a similar library for retro flare

## Basic Overview

The program loads data from two json files - GameData.json and Dictionary.json. As the name suggests, GameData loads in all game data including location information, characters, dialogue, items, and events (this may eventually be broken up so files don't become unyieldy).

The Dictionary json contains valid words as well as common synonyms to give players flexibility when typing actions. The file also defines basic grammar rules for interpreting player input. 

All game objects are considered entities that are made up of various collections of components which provide the entities with specific behaviors. The interworkings of entities with their components are the bulk of the system. 
