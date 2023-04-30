#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <unordered_map>



bool isGreatOrEqualPriority(char _first, char _second) noexcept
{
	static std::unordered_map<char, uint8_t> _priority_map = { std::pair<char, uint8_t>('+', 0), std::pair<char, uint8_t>('-', 0),
								   std::pair<char, uint8_t>('*', 1), std::pair<char, uint8_t>('/', 1) };

	return _priority_map[_first] >= _priority_map[_second];
}



std::string convertToPostfixExpr(const std::string& _expression, std::stack<int64_t>& _stack) noexcept
{
	std::string _postfix_expression;

	size_t start_num_index = -1;
	size_t inner_deep = 0;
        for (size_t i = 0; i < _expression.length(); ++i)
        {
                if (std::isdigit(_expression[i]))
                {
			if (i + 1 == _expression.length())
			{
				if (start_num_index == -1)
				{
					_postfix_expression.push_back(_expression[i]);
				}
				else
				{
					_postfix_expression += _expression.substr(start_num_index, i - start_num_index + 1);
				}
			}

                        if (start_num_index == -1)
                        {
                                start_num_index = i;
                        }
                }
                else
                {
                        if (start_num_index != -1)
                        {
				_postfix_expression += _expression.substr(start_num_index, i - start_num_index) + ' ';
                                start_num_index = -1;
                        }

			if (!std::isspace(_expression[i]) && _expression[i] != '(' && _expression[i] != ')')
			{
				if (inner_deep == 0)
				{
					while (!_stack.empty() && isGreatOrEqualPriority(_stack.top(), _expression[i]))
                                	{
                                        	_postfix_expression.push_back(_stack.top());
                                        	_stack.pop();
                                	}

				}
				_stack.push(_expression[i]);
			}
			else if (_expression[i] == '(')
			{
				++inner_deep;
				_stack.push(static_cast<int64_t>('('));
			}
			else if (_expression[i] == ')')
			{
				while (!_stack.empty() && _stack.top() != '(')
				{
					_postfix_expression.push_back(_stack.top());
					_stack.pop();
				}
				if (!_stack.empty())
				{
					_stack.pop();
				}
				--inner_deep;
			}
                }
		std::cout << i << ":\t" << _postfix_expression << std::endl;
        }

	while (!_stack.empty())
	{
		_postfix_expression.push_back(_stack.top());
		_stack.pop();
	}

	std::cout << "Result:\t" << _postfix_expression << std::endl;

	return _postfix_expression;
}



int64_t completeBinaryOperation(char _operator, int64_t _left, int64_t _right) noexcept
{
	switch (_operator)
	{
	case '+':
		std::cout << _left << ' ' << _right << std::endl;
		return _left + _right;
	case '-':
		return _left - _right;
	case '*':
		return _left * _right;
	case '/':
		return _left / _right;
	default:
		return 0;
	}
}



int64_t calculateStrExpr(const std::string& _expression) noexcept
{
	std::stack<int64_t> _stack;

	std::string _postfix_expression = convertToPostfixExpr(_expression, _stack);

	size_t start_num_index = -1;
	for (size_t i = 0; i < _postfix_expression.length(); ++i)
	{
		if (std::isdigit(_postfix_expression[i]))
		{
			if (start_num_index == -1)
			{
				start_num_index = i;
			}
		}
		else
		{
			if (start_num_index != -1)
			{
				_stack.push(std::stoull(_postfix_expression.substr(start_num_index, i - start_num_index)));
				start_num_index = -1;
			}

			if (!std::isspace(_postfix_expression[i]))
			{
				int64_t _right = _stack.top();
				_stack.pop();
				int64_t _left = _stack.top();
				_stack.pop();

				int64_t result = completeBinaryOperation(_postfix_expression[i], _left, _right);

				_stack.push(result);
			}
		}
	}

	return _stack.top();
}



int main(int argc, char** argv)
{
	char expr[100] = {'\0'};

	std::cin.getline(expr, 100);
	rewind(stdin);

	int64_t result = calculateStrExpr(expr);

	std::cout << "Result: " << result << std::endl;

	char end = _getch();

	return 0;
}
