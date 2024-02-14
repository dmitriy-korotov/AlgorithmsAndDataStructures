#include <iostream>

#include <FibonacciSearch.hpp>

#include <vector>



int main(int _argc, char* _argv[]) 
{
    std::vector<int> vec = { 3, 5, 6, 9, 12, 56, 78, 89, 110, 324, 342, 2352, 123123, 342432 };
    auto out = std::ostream_iterator<int>(std::cout, " ");

    std::cout << "Vector elements:" << std::endl;
    std::copy(std::begin(vec), std::end(vec), out);

    int value1 = 110;
    auto result1 = FibonacciSearch(std::begin(vec), std::end(vec), value1);

    std::cout << std::endl << "Finding element '" << value1 << "'..." << std::endl;
    if (result1.has_value())
        std::cout << "Position: " << std::distance(std::begin(vec), result1.value()) << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    

    int value2 = 1110;
    auto result2 = FibonacciSearch(std::begin(vec), std::end(vec), value2);

    std::cout << std::endl << "Finding element '" << value2 << "'..." << std::endl;
    if (result2.has_value())
        std::cout << "Position: " << std::distance(std::begin(vec), result2.value()) << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    return 0;
}