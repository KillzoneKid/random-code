/*
Universal comparator
https://ideone.com/jI536i
*/

#include <iostream>
#include <vector>
#include <algorithm>

class MyClass
{
public:

	struct
	{
		bool operator()(int a, int b)
		{
			return a < b;
		}
	} 
	myUniversalComparator;

	void mysort(std::vector<int> &vec) 
	{
		std::sort(vec.begin(), vec.end(), myUniversalComparator); // as sort comparator
	}

	bool mycompare(int a, int b)
	{
		return myUniversalComparator(a, b);
	}
};


int main()
{
	MyClass myclass;
	std::vector<int> vec = { 1,8,3,9,2 };
	
	// as std::sort comparator
	myclass.mysort(vec);
	for (auto n : vec)
		std::cout << n << " ";
	std::cout << std::endl;

	// as in class method invocation
	std::cout << vec[0] << " < " << vec[2] << " -> " << std::boolalpha << myclass.mycompare(vec[0], vec[2]) << std::endl;

	// as class method direct invocation 
	std::cout << vec[4] << " < " << vec[3] << " -> " << std::boolalpha << myclass.myUniversalComparator(vec[4], vec[3]) << std::endl;

	return 0;
}