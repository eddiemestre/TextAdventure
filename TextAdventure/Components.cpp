#include "Components.h"
#include <string>

// A list of all Components that need to be initialized

// likely obsolete
//BoolObject::BoolObject(std::string & name, std::string & sceneName, bool activated, bool render)
//	:name(name)
//	, sceneName(sceneName)
//	, activated(activated)
//	, render(render)
//{
//}

SceneName::SceneName(std::string& value)
	:value(value)
{
}

Name::Name(std::string& value)
	:value(value)
{
}

Activated::Activated(bool b)
	:value(b)
{
}

Render::Render(bool b)
	:value(b)
{
}

Position::Position(std::string& position)
	:value(position)
{
}

lDescIndex::lDescIndex(int i)
	:value(i)
{
}

sDescIndex::sDescIndex(int i)
	:value(i)
{
}

aDescIndex::aDescIndex(int i)
	:value(i)
{
}

Direction::Direction(std::string& value)
	:value(value)
{
}

ToLocation::ToLocation(std::string& value)
	:value(value)
{
}

EventArray::EventArray(std::string& s)
{
	value.emplace_back(s);
}

BoolType::BoolType(std::string& type)
	:type(type)
{
}
