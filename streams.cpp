/*
	Fun with streams
	1. Reading whole file into a string
	2. Reading whole file into std::cin
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iterator>

int main()
{
	// open file
	std::ifstream ifs("C:\\Users\\KK\\Desktop\\test.txt");

	// read the whole file into std::ostringstream and print
	std::ostringstream oss;
	oss << ifs.rdbuf();
	std::cout << oss.str() << std::endl;

	// rewind the file and reset flags
	ifs.seekg(0);
	ifs.clear();

	// read the whole file into std::cin
	std::cin.rdbuf(ifs.rdbuf());
	
	// iterate through data and print
	std::istream_iterator<std::string> it(std::cin);
	std::istream_iterator<std::string> eos;
	for (; it != eos; ++it)
		std::cout << *it << std::endl;
}