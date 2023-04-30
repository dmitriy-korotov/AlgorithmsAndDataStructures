#include "BinaryHeap.hpp"

#include <iostream>
#include <vector>



template <typename T>
void printHeap(const BinaryHeap<T>& _heap)
{
	for (size_t i = 0; i < _heap.size(); ++i)
	{
		std::cout << _heap[i] << ' ';
	}
	std::cout << std::endl;
}



int main(int argc, char** argv)
{
	std::cout << "Test starting...\n\n";

	std::vector<int> _vec = { 3, 4, 7, 23, 42, 4, 2, 1 , 34, 43, 2, 43, 2, 6 };
	BinaryHeap<int> _heap_from_vec(_vec.cbegin(), _vec.cend());
	BinaryHeap<int> _heap = {6, 34, 10, 3, 12, 34, 8, 3, 5};

	std::cout << "Heap from vector:\n\n";
	printHeap(_heap_from_vec);		std::cout << std::endl;

	std::cout << "Heap:\n\n";
	printHeap(_heap);	std::cout << std::endl;

	std::cout << "Push:\n\n";
	_heap.push(1);
	printHeap(_heap);	std::cout << std::endl;

	std::cout << "Pop:\n\n";
	_heap.pop();
	printHeap(_heap);	std::cout << std::endl;

	return 0;
}
