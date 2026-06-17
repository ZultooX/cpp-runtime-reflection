#include "Lexer.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include "ReflectionGenerator.h"

void ReflectionGenerator::Generate(const std::unordered_map<std::string, Class>& classes) const
{
	for (auto& [name, cls] : classes)
	{
		GenerateReflectionClass(name, cls);
	}
}

void ReflectionGenerator::GenerateReflectionClass(const std::string& name, const Class& cls) const
{
	std::cout << "Generating: " << name << std::endl;

	const std::string generatedFilepath = name + ".generated.cpp";

	std::stringstream stream;

	if (!cls._namespace.empty())
	{
		stream << "using namespace " << cls._namespace << ";"  "\n\n";
	}

	stream << "struct Variable {int offset; int size; };""\n";

	stream << "struct Generated_" << name << "\n";
	stream << "{\n";
	stream << "    static constexpr const char* ClassName = \"" << name << "\";"  "\n";
	stream << "    static const std::unorderded_map<std::string, Variable> variables ="  "\n";
	stream << "    {""\n";
	for (auto& var : cls.variables)
	{
		stream << "        { offsetof(" << name << ", " << var.name << "), sizeof(" << var.type << ") }"  "\n";
	}
	stream << "    };""\n";
	stream << "};""\n";

	std::ofstream out(name + ".generated.cpp");
	out << stream.str();
}