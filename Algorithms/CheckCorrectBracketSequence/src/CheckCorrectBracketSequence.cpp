#include <CheckCorrectBracketSequence.hpp>

#include <stack>



bool CheckCorrectBracketSequence(std::string_view _expression) noexcept
{
    std::stack<char> stack;
    for (auto symbol : _expression)
    {
        if (symbol == '(')
            stack.push(symbol);
        else if (symbol == ')')
        {
            if (stack.empty())
                return false;
            stack.pop();
        }
    }
    return stack.empty();
}