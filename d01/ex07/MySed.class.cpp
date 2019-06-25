#include "MySed.class.hpp"

MySed::MySed( void ) { return; }
MySed::~MySed( void ) { return; }

bool MySed::checkArgs(std::string s1, std::string s2)
{
	if (!s1.empty() && !s2.empty())
		return true;
	return false;
}

std::string MySed::readFromFile(std::string filename)
{
	std::ifstream ifs (filename, std::ifstream::in);
	if (ifs)
	{
		std::stringstream buff;
		buff << ifs.rdbuf();
		return (buff.str());
	}
	std::cout << "Error to read: " + filename << std::endl;
	return ("");
}

std::string MySed::replace(std::string &str, const std::string &toFind, const std::string &replaceWith)
{
    size_t ptr = 0;
	while((ptr = str.find(toFind, ptr)) != std::string::npos) {
        str.replace(ptr, toFind.length(), replaceWith);
        ptr += replaceWith.length();
    }
	return str;
}

void MySed::writeToFile(std::string filename, std::string content)
{
	std::ofstream ofs (filename + ".replace", std::ofstream::out);
	if (ofs)
		ofs << content;
	else
		std::cout << "Error to write to: " + filename + ".replace" << std::endl;
	ofs.close();
}