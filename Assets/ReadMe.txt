Sentences contain
- verb
- direct object
- indirect object (sometimes)
- always imperative

Example sentences:
- "Get keys" - action item
- "Give potion to John" - action item to entity
- "Engage Spiders" - action entity
- "Climb ladder" - action object
- "Use potion" - action item
- "Use the potion" - action item
- "climb up the tree" action direction object
- "go down the ladder" - action direction object
- "descend stairs" - action object
- "ascend stairs" - action object
- "talk to Connor" - action to entity
- "listen to the gorilla" - action to entity
- "inspect the room" - action object
- "drop the potion" - action item
- "use the keys on the door" - action item object 
- "give to John the potion" action to entity item
- "sell the potion" - action item
- "sell the potion to John" - action item to entity
- "Go south" - action direction

- action item*
- action item to entity +
- action to entity item +
- action entity*
- action object (action item?)*
- action item to object +
- action to entity ~
- action direction object
- action direction (action object?)*

- action item, action entity, action object, action direction should all function the same
- action item to entity, action to entity item, action item to object should function the same
- action to entity
- action direction object
- 4x scenarios?

All possible (valid) actions the demo: 
Living Room:
- Inspect/listen/use/drop/get keys
- inspect/listen room/living room
- Inspect/listen/use couch/couches
- inspect coffee table
- inspect/listen/use/go TV
- inspect/listen/go bad cartoon
- go direction
Foyer:
- inspect/listen room/foyer
- inspect/get/use shoes
- inspect/open/use coat closet
- inspect/listen/talk Boris
- go direction
Bedroom:
- inspect/listen room/Bedroom
- inspect/use/get/go computer game/game/monitor
- inspect/listen/talk William
- inspect/use bed
Kitchen:
- inspect/listen room/Kitchen
- inspect dirty dishes/dishes
- inspect/listen sink
- inspect/listen refrigerator/fridge
- inspect/use/open pantry/pantry door

Other items
- tasty beverage
- scrumptious snack



Not valid but accounted for:




Actions:
Inspect
Use
Get
Drop
Listen
Talk
Give
Go (Direction)

(not implemented yet)
Buy
Sell
Engage/Fight/Attack
Run/Flee/Escape


in file:
action {
	synonyms {
	}
	
}

For Prototype
Inspect any object specifically referenced. Returns long description
Use any item
Get any item
Drop any item
Listen any object specifically referenced
Talk any NPC 
Give and item
Go

Entities have components that dictate whether or not the above actions
can be done to them.

Objects in current game:
Boris - inspect, listen, talk, give
Coat Closet - inspect, listen
Shoes - inspect, get, use, listen
Couch - inspect, use, listen
Coffee Table
TV
Bad Cartoon
computer game
monitor
William
bed
tasty beverage
dirty dishges
sink
refrigerator
keys
scrupmtious snack

if all valid commands but can't interact with object that way (get shoes):
default lines for each actions
"There is nothing to inspect"
"You cannot use that"
"You cannot get that"
"You can't drop that"
"It doesn't make any sound"
"You cannot talk with ___"
"You cannot do that"
"You cannot go that way"
"You can't buy that"
"You can't sell that"

special words:
all, everything
both
but
except
one, an, a/quantity
it
them
him
her


parse steps:
1. get user input
2. input to lowercase
3. remove "the", and all characters that aren't a - z
4. get first word - look it up in dictionary (all dictionary unordered map - this map will have a pair that is the word and what part of speech that word is
5. if it's found and it's a verb, move to next step. Otherwise "Come again?"
6. Get second word - look it up in dictionary (all dictionary)
7. can either be a special word, noun, pronoun, preposition
8. check if command is valid (can you verb the second word? "Give to" "Listen to" "Use keys" etc, needs to be direct or indirect object)






Events
Needs:
1. determine if an action if valid
2. assuming it is, get the event associated with that action and what it is acted upon
3. 

"get keys"
look up keys
are they gettable? (yes)
create get event (keys)



version 1:

// create new Event
Event(get_event, player, json) {
// look up get_event under player
// looks for event_Listeners > list of all items player can get
// check which of those items are in this room
// populate array
}

Execute(get_keys,player,json) {

}
????

version 2:
// create new Event
// pass in (1) the entity getting the item (2) the item (3) json game data
Event(get_event, player, keys, gamedata) {
// sets event = get_event
// subject = player
// object = keys
// are there any event listeners?

version a: 
// does player have a list of possible events to execute (get_event, inspect_event, ring_bell, etc)?

}

"get_event": [
	{
		entity: keys,
		events: [
		]
	},
	{
		entity: rope,
		events: [
		]
	}
]

"keys": {
	Properties" [
		{
			canGet: true,
			haveBeenPickedUp: false,
			events: [
			]
		}
		{
			canInspect: true,
			haveBeenInspected: false,
			events: [
			]
	]
}
