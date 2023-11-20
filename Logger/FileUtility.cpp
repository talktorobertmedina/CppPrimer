#include "FileUtility.h"

std::ifstream FileUtility::open(const std::string& filename)
{
	return std::ifstream(filename);
}

std::string FileUtility::read(const std::string& filename)
{
	std::ifstream file = FileUtility::open(filename);
	std::ostringstream oss;
	oss << file.rdbuf();
	file.close();
	return oss.str();
}

bool FileUtility::write(const std::string& filename, const std::string& write)
{
	return false;
}

std::ofstream FileUtility::close(const std::string& filename)
{
	return std::ofstream(filename);
}