/*
	Unify functions with arguments
	and store in a vector
	https://ideone.com/0G2u7i
*/

#include <iostream>
#include <vector>
#include <functional>

static void fn1(int x, int y)
{
	std::cout << x << " " << y << std::endl;
}

static void fn2(int x, int *y, double z)
{
	std::cout << x << " " << *y << " " << z << std::endl;
}

static void fn3(const char* x, bool y)
{
	std::cout << x << " " << std::boolalpha << y << std::endl;
}

int main()
{
	std::vector<std::function<void()>> binds;
	int i = 20;

	binds.push_back(std::bind(&fn1, 1, 2));
	binds.push_back(std::bind(&fn1, 3, 4));
	binds.push_back(std::bind(&fn2, 1, &i, 3.99999));
	binds.push_back(std::bind(&fn2, 3, &i, 0.8971233921));
	binds.push_back(std::bind(&fn3, "test1", true));
	binds.push_back(std::bind(&fn3, "test2", false));

	for (auto const &fn : binds) fn();
	
	return 0;
}