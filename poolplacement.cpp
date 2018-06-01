/*
	Some kind of pool object placement by 
	overriding new and delete (inc smart pointer)
	https://ideone.com/AxsEUc
*/

#include <iostream>
#include <cstring>
#include <memory>

class A
{
public:

	A() { std::cout << "constructor\n"; }
	~A() { std::cout << "destructor\n"; }

	static void* operator new(std::size_t size);
	static void operator delete(void* ptr, std::size_t sz);
};

#define MAX_POOL 2;
const size_t size = sizeof(A) * MAX_POOL;
char pool[size] = {};
size_t nextFree = 0;

void* A::operator new(std::size_t size)
{
	if (nextFree + size > sizeof(pool))
		return static_cast<void *>(nullptr);

	void *ptr = &pool[nextFree];
	nextFree += size;
	return ptr;
}

void A::operator delete(void* ptr, std::size_t sz)
{
	std::memset(ptr, 0, sz);
}


int main()
{
	A* a = new A();
	if (a && a == reinterpret_cast<A*>(&pool[0 * sizeof(A)]))
		std::cout << "a pool placement succeeded" << std::endl;
	else
		std::cout << "a pool placement failed" << std::endl;

	std::unique_ptr<A> b = std::make_unique<A>();
	if (b.get() && b.get() == reinterpret_cast<A*>(&pool[1 * sizeof(A)]))
		std::cout << "b pool placement succeeded" << std::endl;
	else
		std::cout << "b pool placement failed" << std::endl;

	A* c = new A();
	if (c && c == reinterpret_cast<A*>(&pool[2 * sizeof(A)]))
		std::cout << "c pool placement succeeded" << std::endl;
	else
		std::cout << "c pool placement failed" << std::endl;

	delete a;
	delete c;
}