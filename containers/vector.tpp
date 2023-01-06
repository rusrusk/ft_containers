#include "vector.hpp"

namespace ft 
{
	//------------------Default constructor------------------//
	//constructs an empty container, without elements
	template <typename T, typename Alloc>
	ft::Vector<T, Alloc>::Vector(const allocator_type &alloc)
			:	_size(0),
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Default Constructor has been invoked" << std::endl;
	}

	//------------------Filled constructor------------------//
	//constructs container with n elems. Each elem is a copy of val
	template <typename T, typename Alloc>
	ft::Vector<T, Alloc>::Vector(size_type n, const value_type &val, const allocator_type &alloc) 
			:	_size(0),
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		for (int i = 0; i < n; i++)
			_allocator.construct(_start + i, val);

		if (M_DEBUG)
			std::cout << "[VECTOR] Filled constructor has been invoked";
	}

	//------------------Range constructor------------------//
	//constructs container with as many elems as range [first,last] with each elem constructed from its elem in that range
	template <typename T, typename Alloc>
	template <typename InputIterator>
	ft::Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc) 
			:	_size(0),
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		(void)first;
		(void)last;
		if (M_DEBUG)
			std::cout << "[VECTOR] Range constructor has been invoked";
	}
	//------------------Destructor------------------//
	template <typename T, typename Alloc>
	ft::Vector<T, Alloc>::~Vector() {
		if (M_DEBUG)
			std::cout << "[VECTOR] Destructor has been invoked";
	}

	//------------------Copy Constructor------------------//
	// template <typename T, typename Alloc>
	// ft::vector::
	

	/////////////////////////////////////////////////////////
	//		ITERATORS						/////////////////
	////////////////////////////////////////////////////////

	//////////////////////////////////////////////
	//begin///////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::iterator ft::Vector<T, Alloc>::begin() {
		return iterator(_start);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_iterator ft::Vector<T, Alloc>::begin() const {
		return const_iterator (_start);
	}

	//////////////////////////////////////////////
	//end/////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::iterator ft::Vector<T, Alloc>::end() {
		return iterator(_end);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_iterator ft::Vector<T, Alloc>::end() const {
		return const_iterator (_end);
	}

	//////////////////////////////////////////////
	//rbegin//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reverse_iterator ft::Vector<T, Alloc>::rbegin() {
		return reverse_iterator(_end - 1);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reverse_iterator ft::Vector<T, Alloc>::rbegin() const {
		return const_reverse_iterator(_end - 1);
	}

	//////////////////////////////////////////////
	//rend////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reverse_iterator ft::Vector<T, Alloc>::rend() {
		return reverse_iterator(_end - 1);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reverse_iterator ft::Vector<T, Alloc>::rend() const {
		return const_reverse_iterator (_end - 1);
	}

	//////////////////////////////////////////////////////
	//		ELEMENT 		ACCESS						//
	/////////////////////////////////////////////////////

	//////////////////////////////////////////////
	//operator[]//////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reference   ft::Vector<T, Alloc>::operator[](size_type n) {
		return (*(_start + n));
	if (M_DEBUG)
			std::cout << "[VECTOR] operator[] has been invoked";
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::operator[](size_type n) const {
		return (*(_start + n));
	}

	//////////////////////////////////////////////
	//at////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reference ft::Vector<T, Alloc>::at(size_type n) {
		if (n >= _size) {
			std::out_of_range("can't access element at() outside of the vector range");
		}
		return (*(_start + n));
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::at(size_type n) const {
		if (n >= _size) {
			std::out_of_range("can't access element at() outside of the vector range");
		}
		return (*(_start + n));
	}

	//////////////////////////////////////////////
	//front////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reference ft::Vector<T, Alloc>::front() {
		if (_size == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_start)
			std::out_of_range("can't call empty container with front()");
		return (*_start);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::front() const {
		if (_size == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_start)
			std::out_of_range("can't call empty container with front()");
		return (*_start);
	}

	//////////////////////////////////////////////
	//back////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reference ft::Vector<T, Alloc>::back() {
		if (_size == 0)
			std::out_of_range("can't call back() if size == 0");
		if (!_end)
			std::out_of_range("can't call back() if the container is empty");
		return (*(_end - 1));
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::back() const {
		if (_size == 0)
			std::out_of_range("ca't call back() if size == 0");
		if (!_end)
			std::out_of_range("can't call back() if the container is empty");
		return (*(_end - 1));
	}

	//////////////////////////////////////////////
	//data////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::value_type* ft::Vector<T, Alloc>::data() {
		return (*_start);
	}

	template <typename T, typename Alloc>
	const typename ft::Vector<T, Alloc>::value_type* ft::Vector<T, Alloc>::data() const {
		return (*_start);
	}

	//////////////////////////////////////////////////////
	//					CAPACITY						//
	/////////////////////////////////////////////////////

	//////////////////////////////////////////////
	//size////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::size_type ft::Vector<T, Alloc>::size() const {
		return (_end - _start);
	}

	//////////////////////////////////////////////
	//max_size////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::size_type ft::Vector<T, Alloc>::max_size() const {
		return (allocator_type().max_size());
	}

	//////////////////////////////////////////////
	//resize//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::Vector<T, Alloc>::resize(size_type n, value_type value) {
		if (n < size()) {
			if ()
		}
	}
}


