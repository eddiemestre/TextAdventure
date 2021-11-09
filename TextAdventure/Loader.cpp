#include "Loader.h"
#include "Components.h"

using json = nlohmann::json;

// Loads location data from the json file
void ParseLocationData(json& j, entt::registry& r, Graph& g, bool d) {
   
    // find Location section of json
    if (j.find("Locations") != j.end() && d) {
        //std::printf("Locations found \n");
    }

    // loop through Location Data
    for (auto &array : j["Locations"]) {
        const auto entity = r.create();

        // add sceneName to entity (needed for identification)
        if (array.contains("sceneName")) {
            auto scene = array["sceneName"].get<std::string>();
            r.emplace<SceneName>(entity, scene);
        }

        // add ldesc index to entity
        if (array.contains("ldesc")) {
            auto index = array["lindex"].get<int>();
            r.emplace<lDescIndex>(entity, index);
        }

        // add sdesc index to entity
        if (array.contains("sdesc")) {
            auto index = array["sindex"].get<int>();
            r.emplace<sDescIndex>(entity, index);
        }

        // add audio index to entity
        if (array.contains("adesc")) {
            auto index = array["aindex"].get<int>();
            r.emplace<aDescIndex>(entity, index);
        }
        
        // add persistent room objects and their initial states
        if (array.contains("persistentBoolObjects")) {
            r.emplace<PersistentRoomObjects>(entity);
            for (auto& a : array["persistentBoolObjects"]) {
                auto object = r.get<PersistentRoomObjects>(entity).objects.create();

                // name of object
                auto name = a["name"].get<std::string>();
                r.get<PersistentRoomObjects>(entity).objects.emplace<Name>(object, name);

                // Name of scene
                auto sceneName = array["sceneName"].get<std::string>();
                r.get<PersistentRoomObjects>(entity).objects.emplace<SceneName>(object, sceneName);

                // Activated State
                auto activated = a["activated"].get<bool>();
                r.get<PersistentRoomObjects>(entity).objects.emplace<Activated>(object, activated);

                // Render State
                auto render = a["render"].get<bool>();
                r.get<PersistentRoomObjects>(entity).objects.emplace<Render>(object, render);

                // Event Listeners
                if (a.contains("eventArray")) {
                    if (!a["eventArray"].empty()) {
                        for (auto& e : a["eventArray"]) {
                            auto eventName = e.get<std::string>();
                            r.get<PersistentRoomObjects>(entity).objects.emplace<EventArray>(object, eventName);
                        }
                    }
                }

                // determine type of Bool Object
                if (a.contains("type")) {
                    if (a["type"] == "door") {
                        auto type = a["type"].get<std::string>();
                        r.get<PersistentRoomObjects>(entity).objects.emplace<BoolType>(object, type);
                       
                        // Direction of door
                        auto direction = a["direction"].get<std::string>();
                        r.get<PersistentRoomObjects>(entity).objects.emplace<Direction>(object, direction);

                        // Which room it connects to
                        auto toLoc = a["toLocation"].get<std::string>();
                        r.get<PersistentRoomObjects>(entity).objects.emplace<ToLocation>(object, toLoc);

                    }
                }
            }
        }
    }

}

// TO DO: obsolete?
void LDescParse(json&, entt::registry& r, Graph& g, bool d)
{
}
