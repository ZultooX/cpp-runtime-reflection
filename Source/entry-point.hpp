#pragma once

#include <iostream>
#include <sstream>

#ifdef TESTING_SUITE_CLEAN

#include "Reflection/Lexer.h"
#include "Reflection/ReflectionGenerator.h"

#include <regex>
inline void Execute()
{
	Lexer lexer;
	lexer.Tokenize("C:/MyFiles/Projects/cpp-runtime-reflection/Source/Player.h");
	auto& o = lexer.GetClasses();

	ReflectionGenerator gen;
	gen.Generate(o);
}

#endif