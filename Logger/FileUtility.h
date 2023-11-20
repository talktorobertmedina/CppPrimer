#pragma once

#include <string>
#include <fstream>
#include <sstream>

class FileUtility
{
public:
	static std::ifstream open(const std::string& filename);
	static std::string read(const std::string& filename);
	static bool write(const std::string& filename, const std::string& write);
	static std::ofstream close(const std::string& filename);
};
