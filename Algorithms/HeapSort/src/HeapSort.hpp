#pragma once
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <iostream>



template <typename _Iter, typename _Cmp>
void sift(_Iter _begin, _Iter _end, _Iter _current_node, _Cmp _comp) noexcept
{
	size_t _size = _end - _begin;
	size_t _index = _current_node - _begin;

	size_t _left_child_index = 2 * _index + 1;
	size_t _right_child_index = 2 * _index + 2;

	if (_left_child_index < _size && _right_child_index < _size)
	{
		_Iter _left_child_it = _begin + _left_child_index;
		_Iter _right_child_it = _begin + _right_child_index;

		_Iter _swap_it = _comp(*_left_child_it, *_right_child_it) ? _left_child_it : _right_child_it;

		if (_comp(*_swap_it, *_current_node))
		{
			std::swap(*_swap_it, *_current_node);
			sift(_begin, _end, _swap_it, _comp);
		}
	}
	else if (_left_child_index < _size)
	{
		_Iter _left_child_it = _begin + _left_child_index;

		if (_comp(*_left_child_it, *_current_node))
		{
			std::swap(*_left_child_it, *_current_node);
		}
	}
	else if (_right_child_index < _size)
	{
		_Iter _right_child_it = _begin + _right_child_index;

		if (_comp(*_right_child_it, *_current_node))
		{
			std::swap(*_right_child_it, *_current_node);
		}
	}
}


template <typename _Iter, typename _Cmp>
void Heapify(_Iter _begin, _Iter _end, _Cmp _comp) noexcept
{
	size_t _size = _end - _begin;
	for (_Iter _current_it = _end - _size / 2; _current_it != _begin; --_current_it)
	{
		sift(_begin, _end, _current_it - 1, _comp);
	}
}


template <typename _Iter, typename _Cmp = std::less<_Iter::value_type>>
void HeapSort(_Iter _begin, _Iter _end, _Cmp _comp = _Cmp()) noexcept
{
	static_assert(std::_Is_random_iter_v<_Iter>);

	for (_Iter _current_end = _end; _current_end != _begin; --_current_end)
	{
		Heapify(_begin, _current_end, _comp);
		std::swap(*_begin, *(_current_end - 1));
	}
}

#endif // !HEAP_SORT_H
