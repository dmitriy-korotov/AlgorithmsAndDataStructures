#include <iostream>

#include <RecursiveCalcValueByFormula.hpp>

#include <chrono>



int main(int _arc, char* _argv[])
{
    int n = 0;
    std::cout << "Input 'n':\t";
    std::cin >> n;

    if (n < 0)
    {
        std::cout << "'n' must be not negative" << std::endl;
        return 0;
    }

    auto start = std::chrono::steady_clock::now();
    auto answer = RecursiveCalcValueByFormula(n);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Answer: " << answer << "\nTime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    return 0;
}