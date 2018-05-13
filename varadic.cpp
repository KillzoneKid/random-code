/*
	Parsing varadic arguments to initializer_list
	https://ideone.com/RUDi1S
*/

#include <iostream> 
#include <string>
#include <utility>
#include <initializer_list>

class Data
{
	int i;

public:

	explicit Data(int i): i{ i } {};
	explicit Data(char const *i) : i{ std::stoi(i) } {};
	explicit Data(std::string const &i) : i{ std::stoi(i) } {};
	explicit Data(double i) : i{ static_cast<int>(i) } {};
	int getI() const {return i;}
};

class MyClass
{ 
public:

	template<class... ARGS>
	void PrintData(int id, bool mode, ARGS&&... args)
	{
		std::initializer_list<Data> args_list{ Data{ std::forward<ARGS>(args) }... };
		for (auto& arg : args_list)
		{
			std::cout << arg.getI() << std::endl;
		}
	}
};

int main()
{
	MyClass a;
	a.PrintData(1234, true, 1, "2", Data{ 3 }, Data{ Data{"4"} }, 5.0f, Data{ 6.0 }, std::string("7"), 8, 9);

	return 0;
}