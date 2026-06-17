#pragma once

#include <string>
#include <map>

#include "ReflectionType.h"

class ClassRegistry
{
public:
    static void Register(const char* name, ClassInfoBase* info);

    static ClassInfoBase* Get(const char* name);

private:
    static std::map<std::string, ClassInfoBase*, std::less<>>& GetMap();
};