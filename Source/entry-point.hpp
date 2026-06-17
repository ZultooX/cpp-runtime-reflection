#pragma once

#include <iostream>
#include <sstream>
#include <Windows.h>

#ifdef TESTING_SUITE_CLEAN

#include "Reflection/Lexer.h"
#include "Reflection/ReflectionGenerator.h"

#include <regex>

#include "Reflection/ClassRegistry.h"

#include "Player.h"

inline void Execute(int argc, char* argv[])
{
	if (IsDebuggerPresent())
	{
		Lexer lexer;
		lexer.Tokenize("C:/Users/zulto/Desktop/MyFiles/Projects/cpp-runtime-reflection/Source/Player.h");
		auto& o = lexer.GetClasses();

		ReflectionGenerator gen;
		gen.Generate(o);

		SimonsMamma sm{};

		ClassInfoBase* refl = ClassRegistry::Get("SimonsMamma");
		const Property* prop = refl->GetProperty("thisShouldWork");

		prop->Set(&sm, 24);
	}
	else
	{
		
	}
}

#endif