#pragma once

#include <optional>
#include <iterator>



namespace __detail
{
	template <std::random_access_iterator _Iter, typename _Comp>
	std::optional<_Iter> __FibonacciSearch(_Iter _left, _Iter _right,
                                           const typename _Iter::value_type& _value,
                                           const _Comp& _comp) noexcept
	{
		size_t fib_last = 1;
		size_t fib_curr = 1;

        auto size = std::distance(_left, _right);

		for (auto i = _left; i < _right; i += fib_curr)
		{
			if (not _comp(*i, _value) and not _comp(_value, *i))
				return i;

			if (_comp(_value, *i))
			{
                if (fib_curr == 1)
                    return std::nullopt;
                return __FibonacciSearch(_left + fib_last, i, _value, _comp);
            }

			auto tmp = fib_last;
			fib_last = fib_curr;
			fib_curr += tmp;

            if (std::distance(_left, i) + fib_curr >= size)
                break;
		}
		return std::nullopt;
	}
}



template <std::random_access_iterator _Iter, typename _Comp = std::less<typename _Iter::value_type>>
std::optional<_Iter> FibonacciSearch(_Iter _begin, _Iter _end,
                                     const typename _Iter::value_type& _value,
                                     const _Comp& _comp = {}) noexcept
{
	return __detail::__FibonacciSearch(_begin, _end, _value, _comp);
}
