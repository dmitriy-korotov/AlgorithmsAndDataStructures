#pragma once

#include <iterator>



namespace __detail
{       
    template <std::random_access_iterator _Iter, typename _Comp>
    std::pair<_Iter, _Iter> partition(_Iter _left, _Iter _right,
                                      const typename _Iter::value_type& _pivod, const _Comp& _comp) noexcept
    {
        auto eq = _left;
        auto gr = _left;

        auto curr = _left;
        for (; curr != _right; ++curr)
        {
            if (_comp(*curr, _pivod))
            {
                auto tmp = *curr;
                std::swap(*curr, *gr);
                std::swap(*eq, *gr);
                *eq = std::move(tmp);

                eq++;
                gr++;

                continue;
            }
            if (not _comp(*curr, _pivod) && not _comp(_pivod, *curr))
            {
                std::swap(*curr, *gr);
                gr++;
            }
        }
        return { eq, gr };
    }
}



template <std::random_access_iterator _Iter, typename _Comp = std::less<typename _Iter::value_type>>
void QuickSort(_Iter _left, _Iter _right, const _Comp& _comp = {}) noexcept
{
    auto size = std::distance(_left,  _right);
	if (size < 1)
		return;

	auto pivod = std::rand() % size + _left;

	auto [first, second] = __detail::partition(_left, _right, *pivod, _comp);

	QuickSort(_left, first, _comp);
	QuickSort(second, _right, _comp);
}
