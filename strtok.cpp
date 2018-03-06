/*
	Split string with delimiters, similar to strtok
	Will not return empty strings
	https://ideone.com/lnrnQK
*/

#include <iostream> 
#include <string>

int main()
{
	std::string str = "onion ,  'potato .tomato. ' cucumber' .";
	
	std::string const delims = " ,.'";
	for (size_t pos, beg = 0; (pos = str.find_first_of(delims, beg)) != str.npos; beg = str.find_first_not_of(delims, pos + 1))
		std::cout << str.substr(beg, pos - beg) << std::endl;
}