#include "HeapSort.hpp"

#include <iostream>
#include <vector>



template <typename T>
void randInit(std::vector<T>& _vector, size_t _amount, uint64_t _max_module = 1000) noexcept
{
	static_assert(std::is_integral_v<T>);

	_vector.reserve(_amount);
	for (size_t i = 0; i < _amount; ++i)
	{
		_vector.push_back(rand() % (2 * _max_module) - _max_module);
	}
}



int main(int argc, char** argv)
{
	std::vector<int> vec;

	randInit(vec, 20, 100);

	for (int el : vec)
	{
		std::cout << el << ' ';
	}

	std::cout << "\n\nHeapSort:\n\n";

	HeapSort(vec.begin(), vec.end(), std::greater<int>());
	for (int el : vec)
	{
		std::cout << el << ' ';
	}

	return 0;
}