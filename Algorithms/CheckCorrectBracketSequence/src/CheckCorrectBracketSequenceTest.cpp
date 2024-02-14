#include <iostream>

#include <CheckCorrectBracketSequence.hpp>



int main(int _argc, char* _argv[])
{
    std::string expression;

    std::cout << "Input expression:" << std::endl;
    std::cin >> expression;

    auto isValid = CheckCorrectBracketSequence(expression);
    if (isValid)
        std::cout << "Inputted expression is corrected" << std::endl;
    else
        std::cout << "Inputted expression is not corrected" << std::endl;

    return 0;
}