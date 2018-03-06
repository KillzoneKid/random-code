/*
	For loop and smatch and .suffix() with regex_search
	https://ideone.com/jRsAWd
*/

#include <regex>
#include <iostream>
#include <string>

int main()
{
	std::string str = " \"one\":\"1\", \"two\":2, \"two\":44, \"three\":3, \"two\":22 ";

	std::string const expr{ "\"two\":(\\d+)" };
	for (std::smatch matches; std::regex_search(str, matches, std::regex(expr)); str = matches.suffix())
		std::cout << matches[1] << std::endl;

	return 0;
}