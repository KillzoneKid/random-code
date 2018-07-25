/*
	Tag dispatch technique, an alternative to SFINAE
	https://ideone.com/1vCjmu
*/

#include <iostream>

class Container{};
class DC1 : public Container {};
class DC2 : public DC1 {};
class Other {};

namespace kk
{
	template <typename T>
	struct is_container : std::false_type {};
	template <>
	struct is_container<Container> : std::true_type {};
	template <>
	struct is_container<DC1> : std::true_type {};
	template <>
	struct is_container<DC2> : std::true_type {};
}
// or
namespace kk2
{
	template <typename T>
	struct is_container : std::is_base_of<Container, T> {};
}

namespace detail
{
	template <typename T>
	bool isCont(T const &in, std::true_type)
	{
		std::cout << "is container\n";
		return true;
	}

	template <typename T>
	bool isCont(T const &in, std::false_type)
	{
		std::cout << "is not a container\n";
		return false;
	}
}

template <typename T>
bool isCont(T const &in)
{
	return detail::isCont(in, kk2::is_container<T>{});
}

int main()
{
	isCont(Container{});
	isCont(DC1{});
	isCont(DC2{});
	isCont(Other{});

	return 0;
}
