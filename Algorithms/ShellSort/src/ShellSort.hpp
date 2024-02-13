#pragma once

#include <iterator>
#include <concepts>



template <std::random_access_iterator _Iter, typename _Comp = std::less<typename _Iter::value_type>>
void ShellSort(_Iter _begin, _Iter _end, const _Comp& _comp = {}) noexcept
{
    auto d = std::distance(_begin, _end);
    for (; d != 0; d /= 2)
    {
        for (auto i = _begin + d; i != _end; ++i)
        {
            for (auto j = i; std::distance(_begin, j) >= d; j -= d)
            {
                if (_comp(*j, *(j - d)))
                    std::swap(*j, *(j - d));
            }
        }
    }
}