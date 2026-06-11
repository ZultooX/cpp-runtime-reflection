#pragma once

#include <iostream>
#include <sstream>

#ifdef TESTING_SUITE_CLEAN

#include "SourceTokenizer.h"
#include <regex>
inline void Execute()
{
	Lexer::Tokenize("C:/MyFiles/Projects/cpp-runtime-reflection/Source/Player.h");
}

#endif