/*
	Split string with delimiters, similar to strtok
	Will not return empty strings
	https://ideone.com/LJota9
*/

#include <iostream> 
#include <string>

int main()
{
	std::string str = "Hello, everyone! This is: COSC-1436, SP18";
	std::string const delims{ " .,:;!?" };

	size_t beg, pos = 0;
	while ((beg = str.find_first_not_of(delims, pos)) != std::string::npos)
	{
		pos = str.find_first_of(delims, beg + 1);
		std::cout << str.substr(beg, pos - beg) << std::endl;
	}
	
	return 0;
}