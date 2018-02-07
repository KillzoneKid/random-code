/* 
An example of how to add extended methods 
to the main method of a class like so
a.mainMethod().extendedMethod()
https://ideone.com/Psh5Sj
*/

#include <iostream>
#include <string>

class Ext
{
private:
	class Int
	{
	private:
		int i;
	public:
		Int(int i) : i(i) {}
		operator int() const { return i; }
		int square() const { return i * i; }
		std::string toString() const { return "\"" + std::to_string(i) + "\""; }
	} _int;
public:
	Ext(int val) : _int(val) {}
	Int const &getInt() const { return _int; }
};

int main()
{
	Ext a{ 123 };
	std::cout << a.getInt() << std::endl;
	std::cout << a.getInt().square() << std::endl;
	std::cout << a.getInt().toString() << std::endl;

	return 0;
}