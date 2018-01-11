/* 
A factory pattern design using map, lambdas and polymorphism
https://ideone.com/Bj51fT
*/

#include <map>
#include <functional>
#include <iostream>
#include <string>

class Base
{
public:
	virtual ~Base() = default;
	virtual std::string whatBaseAmI() = 0;
	virtual unsigned long toDec() = 0;
};

class Hex : public Base
{
	std::string _number;
public:
	Hex(std::string number) : _number(number) {}
	unsigned long toDec() override { return std::strtoul(_number.c_str(), NULL, 16); }
	std::string whatBaseAmI() override { return "Hex"; }
};

class Binary : public Base
{
	std::string _number;
public:
	Binary(std::string number) : _number(number) {}
	unsigned long toDec() override { return std::strtoul(_number.c_str(), NULL, 2); }
	std::string whatBaseAmI() override { return "Binary"; }
};

int main()
{
	std::map<std::string, std::function<Base *(std::string const &)>> factory =
	{
		{ "Binary", [](std::string const &number) { return new Binary(number); } },
		{ "Hex", [](std::string const &number) { return new Hex(number); } }
	};

	Base *b = factory["Binary"]("1001001001001");

	if (b)
	{
		std::cout << "Base: " << b->whatBaseAmI() << std::endl;
		std::cout << "Decimal Value: " << b->toDec() << std::endl;
	}

	return 0;
}