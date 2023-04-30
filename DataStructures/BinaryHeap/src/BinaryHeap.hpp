#pragma once
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <vector>



template <typename _Type, typename _Container = std::vector<_Type>, typename _Cmp = std::less<_Type>>
class BinaryHeap
{
public:

	using value_type = _Type;
	using iterator = typename _Container::iterator;
	using const_iterator = typename _Container::const_iterator;



	BinaryHeap() = default;
	BinaryHeap(const_iterator _it_cbegin, const_iterator _it_cend) noexcept;
	BinaryHeap(const std::initializer_list<_Type>& _init_list) noexcept;
	BinaryHeap(const BinaryHeap<_Type>& _other);
	BinaryHeap& operator=(const BinaryHeap<_Type>& _right);
	BinaryHeap(BinaryHeap<_Type>&& _other) noexcept;
	BinaryHeap& operator=(BinaryHeap<_Type>&& _right) noexcept;
	~BinaryHeap() = default;

	operator _Container() const noexcept;
	const _Type& operator[](size_t _index) const noexcept;

	const _Container& getContainer() const noexcept;
	void swap(BinaryHeap& _other) noexcept;
	size_t size() const noexcept;
	void push(const _Type& _value) noexcept;
	_Type pop();

private:

	void heapify() noexcept;
	void siftUp(int64_t _inedx) noexcept;
	void siftDown(size_t _index) noexcept;



	_Container m_container;
	_Cmp m_comporator = _Cmp();

};



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>::BinaryHeap(const std::initializer_list<_Type>& _init_list) noexcept
{
	m_container.reserve(_init_list.size());
	for (const auto& el : _init_list)
	{
		m_container.push_back(el);
	}
	heapify();
}



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>::BinaryHeap(const_iterator _it_cbegin, const_iterator _it_cend) noexcept
		: m_container(_it_cbegin, _it_cend)
{
	heapify();
}



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>::BinaryHeap(const BinaryHeap<_Type>& _other)
		: m_container(_other.m_container)
		, m_comporator(_other.m_comporator)
{ }



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>& BinaryHeap<_Type, _Container, _Cmp>::operator=(const BinaryHeap<_Type>& _right)
{
	if (this != &_right)
	{
		auto _heap = _right;
		swap(this, _heap);
	}
	return *this;
}



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>::BinaryHeap(BinaryHeap<_Type>&& _other) noexcept
		: m_container(std::move(_other.m_container))
		, m_comporator(std::move(_other.m_comporator))
{ }



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>& BinaryHeap<_Type, _Container, _Cmp>::operator=(BinaryHeap<_Type>&& _right) noexcept
{
	if (this != &_right)
	{
		auto _heap = std::move(_right);
		swap(this, _heap);
	}
	return *this;
}



template <typename _Type, typename _Container, typename _Cmp>
void BinaryHeap<_Type, _Container, _Cmp>::swap(BinaryHeap& _other) noexcept
{
	std::swap(m_container, _other.m_container);
	std::swap(m_comporator, _other.m_comporator);
}



template <typename _Type, typename _Container, typename _Cmp>
size_t BinaryHeap<_Type, _Container, _Cmp>::size() const noexcept
{
	return m_container.size();
}



template <typename _Type, typename _Container, typename _Cmp>
BinaryHeap<_Type, _Container, _Cmp>::operator _Container() const noexcept
{
	return m_container;
}



template <typename _Type, typename _Container, typename _Cmp>
const _Type& BinaryHeap<_Type, _Container, _Cmp>::operator[](size_t _index) const noexcept
{
	return m_container[_index];
}



template <typename _Type, typename _Container, typename _Cmp>
void BinaryHeap<_Type, _Container, _Cmp>::heapify() noexcept
{
	if (m_container.size() > 1)
	{
		for (int64_t i = m_container.size() / 2; i >= 0; --i)
	    {
			siftDown(i);
        }
	}
}



template <typename _Type, typename _Container, typename _Cmp>
void BinaryHeap<_Type, _Container, _Cmp>::siftDown(size_t _index) noexcept
{
	size_t left_child_index = 2 * _index + 1;
	size_t right_child_index = 2 * _index + 2;

	if (left_child_index < m_container.size() && right_child_index < m_container.size())
	{
		size_t swap_index = m_comporator(m_container[left_child_index], m_container[right_child_index]) ? left_child_index : right_child_index;

		if (m_comporator(m_container[swap_index], m_container[_index]))
		{
			std::swap(m_container[_index], m_container[swap_index]);
			siftDown(swap_index);
		}
	}
	if (right_child_index < m_container.size())
    {
		if (m_comporator(m_container[right_child_index], m_container[_index]))
		{
			std::swap(m_container[right_child_index], m_container[_index]);
			siftDown(right_child_index);
		}
    }
	if (left_child_index < m_container.size())
	{
		if (m_comporator(m_container[left_child_index], m_container[_index]))
		{
			std::swap(m_container[left_child_index], m_container[_index]);
			siftDown(left_child_index);
		}
	}
}



template <typename _Type, typename _Container, typename _Cmp>
void BinaryHeap<_Type, _Container, _Cmp>::siftUp(int64_t _index) noexcept
{
	int64_t parent_index = _index / 2 - 1;
	if (parent_index >= 0 && !m_comporator(m_container[parent_index], m_container[_index]))
	{
		std::swap(m_container[parent_index], m_container[_index]);
		siftUp(parent_index);
	}
}




template <typename _Type, typename _Container, typename _Cmp>
void BinaryHeap<_Type, _Container, _Cmp>::push(const _Type& _value) noexcept
{
	m_container.push_back(_value);
	siftUp(m_container.size() - 1);
}



template <typename _Type, typename _Container, typename _Cmp>
_Type BinaryHeap<_Type, _Container, _Cmp>::pop()
{
	if (!m_container.empty())
	{
		_Type _pop_elem = std::move(m_container[0]);
		std::swap(m_container[0], m_container[m_container.size() - 1]);
		m_container.pop_back();
		siftDown(0);
		return _pop_elem;
	}
	else
	{
		throw std::exception("Heap is empty");
	}
}

#endif
