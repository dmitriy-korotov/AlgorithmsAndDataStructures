#include <iostream>

#include <BinaryInsertSort.hpp>

#include <vector>



int main(int _argc, char* _argv[]) 
{
    std::vector<int> vec = { 3, 5, 1, 0, 12, 43, 123, 1, -34, -123, 4, 15, 56 };
    auto out = std::ostream_iterator<int>(std::cout, " ");

    std::cout << "Initial vector:" << std::endl;
    std::copy(std::begin(vec), std::end(vec), out);

    BinaryInsertSort(vec);

    std::cout << std::endl << "Sorted vector:" << std::endl;
    std::copy(std::begin(vec), std::end(vec), out);

    return 0;
}