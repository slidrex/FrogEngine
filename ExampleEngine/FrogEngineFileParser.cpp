#include <fstream>
#include <string>
#include "FrogEngineFileParser.h"

std::string FrogEngine::ParseFile(const std::string& path)
{
	std::string line;
	std::string parsedString;
	std::ifstream stream(path);
	while (getline(stream, line)) parsedString += line + '\n';
	return parsedString;
}