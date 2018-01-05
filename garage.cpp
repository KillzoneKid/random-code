/* 
Some sort of garage class allowing multiple car add
while only unique ids are accepted
https://ideone.com/8yUyHV
*/

#include <iostream>
#include <unordered_set>
#include <initializer_list>

class Car 
{
private:
	int id;

public:
	Car(int id) : id(id) {};
	int getId() const { return id; }
};

struct Hash 
{
	std::size_t operator()(Car const &car) const
	{
		return std::hash<int>{}(car.getId());
	};
};

struct Equal
{
	bool operator()(Car const &car1, Car const  &car2) const
	{
		return car1.getId() == car2.getId();
	};
};

class Garage 
{
private:
	std::unordered_set<Car, Hash, Equal> allcars;

public:
	Garage() = default;
	
	void addCars(std::initializer_list<Car> cars)
	{
		for (auto car : cars)
			allcars.insert(car);
	}

	friend std::ostream &operator<<(std::ostream &os, Garage const &garage)
	{
		for (auto const &car : garage.allcars)
			os << "Car id: " << car.getId() << std::endl;

		return os;
	}
};

int main()
{
	Garage garage;
	Car car4(4);
	
	std::cout << "adding 3 cars" << std::endl;
	garage.addCars({ 1,2,3,3,3,3,1,2,3 });
	std::cout << garage << std::endl;

	std::cout << "adding 1 more" << std::endl;
	garage.addCars({ car4, car4, car4 });
	std::cout << garage << std::endl;

	return 0;
}