/*
	Fun with streams (part 2)
	Reading whole lines and passing them to vector constructor
	https://ideone.com/rbyozD
*/

#include <iostream> 
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

class line : public std::string {};

std::istream &operator >>(std::istream &iss, line &line)
{
	std::getline(iss, line, '\n');
	return iss;
}

int main()
{
	std::istringstream iss("This is line 1\nThis is line 2\nThis is line 3");
	std::vector<std::string> v(std::istream_iterator<line>{iss}, std::istream_iterator<line>{});

	// test
	for (auto const &s : v)
		std::cout << s << std::endl;

	return 0;
}