#pragma once

#include <vector>
#include <cassert>
#include <concepts>



namespace __detail
{
	template <typename T>
	size_t findInsertPosition(const std::vector<T>& _arr, size_t _left, size_t _right, const T& _value) noexcept
	{
		while (_right - _left > 1)
		{
			size_t midd = (_left + _right) / 2;

			if (_arr[midd] == _value)
				return midd;

			if (_arr[midd] < _value)
				_left = midd;
			else
				_right = midd;
		}
		return (_arr[_left] < _value) ? _right : _left;
	}



	template <typename T>
	void insert(std::vector<T>& _arr, size_t _from, size_t _to) noexcept
	{
		assert(_from >= _to);

		std::swap(_arr[_from], _arr[_to]);
		for (ptrdiff_t i = _from; i > _to + 1; i--)
			std::swap(_arr[i], _arr[i - 1]);
	}
}



template <std::totally_ordered T>
void BinaryInsertSort(std::vector<T>& _arr) noexcept
{
	for (ptrdiff_t i = 0; i < _arr.size(); i++)
	{
		auto position = __detail::findInsertPosition(_arr, 0, i, _arr[i]);
		__detail::insert(_arr, i, position);

	}
}
