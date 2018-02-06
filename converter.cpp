/* 
Union converter from uint8_t array to unit32_t number
with custom byte order
https://ideone.com/Ki6JN3
*/

#include <iostream>

union Converter
{
private:
	uint8_t arr[4];
	uint32_t num;
public:
	uint32_t operator()(uint8_t const (&arr)[4])
	{
		this->arr[0] = arr[3];
		this->arr[1] = arr[2];
		this->arr[2] = arr[1];
		this->arr[3] = arr[0];
		new (&num) uint32_t; // activation of union member
		return num;
	}
} to_uint32_t;

int main()
{
	uint8_t a[4] = { 0, 255, 0, 255 };
	std::cout << to_uint32_t(a) << std::endl;
	std::cout << to_uint32_t({ 255, 0, 255, 0 }) << std::endl;

	return 0;
}