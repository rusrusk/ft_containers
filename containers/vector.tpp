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
		if (M_DEBUG)
			std::cout << "[VECTOR] Filled constructor has been invoked" << std::endl;
		// pointer tmp = _start;
		_start = _allocator.allocate(n);
		_end = _start + n;
		for (unsigned long i = 0; i < n; i++)
		{
			_allocator.construct(_start + i, val);
		}
	}

	//------------------Range constructor------------------//
	//constructs container with as many elems as range [first,last] with each elem constructed from its elem in that range
	template <typename T, typename Alloc>
	template <typename InputIterator>
	ft::Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type*) 
			:	_size(0),
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Range constructor has been invoked" << std::endl;
		_start = _allocator.allocate(last.base() - first.base());
		_end = _start;
		while (first != last)
		{
			_allocator.construct(_end, *first);
			_end++;
			first++;
		}
		
	}
	//------------------Destructor------------------//
	template <typename T, typename Alloc>
	ft::Vector<T, Alloc>::~Vector() {
		if (M_DEBUG)
			std::cout << "[VECTOR] Destructor has been invoked" << std::endl;
	}

	// ------------------Copy Constructor------------------//
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
		if (M_DEBUG)
			std::cout << "begin() has been invoked" << std::endl;
		return iterator(_start);

	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_iterator ft::Vector<T, Alloc>::begin() const {
		if (M_DEBUG)
			std::cout << "begin() const has been invoked" << std::endl;
		return const_iterator (_start);
	}

	//////////////////////////////////////////////
	//end/////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::iterator ft::Vector<T, Alloc>::end() {
		if (M_DEBUG)
			std::cout << "end() has been invoked" << std::endl;
		return iterator(_end);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_iterator ft::Vector<T, Alloc>::end() const {
		if (M_DEBUG)
			std::cout << "end() const has been invoked" << std::endl;
		return const_iterator (_end);
	}

	//////////////////////////////////////////////
	//rbegin//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reverse_iterator ft::Vector<T, Alloc>::rbegin() {
		if (M_DEBUG)
			std::cout << "rbegin() has been invoked" << std::endl;
		return reverse_iterator(_end - 1);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reverse_iterator ft::Vector<T, Alloc>::rbegin() const {
		if (M_DEBUG)
			std::cout << "rbegin() const has been invoked" << std::endl;
		return const_reverse_iterator(_end - 1);
	}

	//////////////////////////////////////////////
	//rend////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::reverse_iterator ft::Vector<T, Alloc>::rend() {
		if (M_DEBUG)
			std::cout << "rend() has been invoked" << std::endl;
		return reverse_iterator(_end - 1);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reverse_iterator ft::Vector<T, Alloc>::rend() const {
		if (M_DEBUG)
			std::cout << "rend() const has been invoked" << std::endl;
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
	if (M_DEBUG)
			std::cout << "[VECTOR] operator[] has been invoked" << std::endl;
		return (*(_start + n));
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::operator[](size_type n) const {
		if (M_DEBUG)
			std::cout << "operator[] has been invoked" << std::endl;
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
		if (M_DEBUG)
			std::cout << "at() has been invoked" << std::endl;
		return (*(_start + n));
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::at(size_type n) const {
		if (n >= _size) {
			std::out_of_range("can't access element at() outside of the vector range");
		}
		if (M_DEBUG)
			std::cout << "at() const has been invoked" << std::endl;
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
		if (M_DEBUG)
			std::cout << "front() has been invoked" << std::endl;
		return (*_start);
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::front() const {
		if (_size == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_start)
			std::out_of_range("can't call empty container with front()");
		if (M_DEBUG)
			std::cout << "front() const has been invoked" << std::endl;
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
		if (M_DEBUG)
			std::cout << "back() has been invoked" << std::endl;
		return (*(_end - 1));
	}

	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::const_reference ft::Vector<T, Alloc>::back() const {
		if (_size == 0)
			std::out_of_range("ca't call back() if size == 0");
		if (!_end)
			std::out_of_range("can't call back() if the container is empty");
		if (M_DEBUG)
			std::cout << "back() const has been invoked" << std::endl;
		return (*(_end - 1));
	}

	//////////////////////////////////////////////
	//data////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::value_type* ft::Vector<T, Alloc>::data() {
		if (M_DEBUG)
			std::cout << "data() has been invoked" << std::endl;
		return (*_start);
	}

	template <typename T, typename Alloc>
	const typename ft::Vector<T, Alloc>::value_type* ft::Vector<T, Alloc>::data() const {
		if (M_DEBUG)
			std::cout << "data() const has been invoked" << std::endl;
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
		if (M_DEBUG)
			std::cout << "size() const has been invoked" << std::endl;
		return (_end - _start);
	}

	//////////////////////////////////////////////
	//max_size////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::size_type ft::Vector<T, Alloc>::max_size() const {
		if (M_DEBUG)
			std::cout << "max_size() const has been invoked" << std::endl;
		return (allocator_type().max_size());
	}

	//////////////////////////////////////////////
	//resize//////////////////////////////////////
	//////////////////////////////////////////////
	// template <typename T, typename Alloc>
	// void ft::Vector<T, Alloc>::resize(size_type n, value_type value) {
	// 	if (n < size()) {
	// 		value = 
	// 	}
	// }

	//////////////////////////////////////////////
	//empty//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	bool ft::Vector<T, Alloc>::empty() const {
		return _size = 0; 
	}

	//////////////////////////////////////////////
	//capacity////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::Vector<T, Alloc>::size_type ft::Vector<T, Alloc>::capacity() const {
		return (_capacity);
	}

	/////////////////////////////////////////////
	//reserve////////////////////////////////////
	/////////////////////////////////////////////
	// template <typename T, typename Alloc>
	// typename ft::Vector<T, Alloc>::
		


	
	//////////////////////////////////////////////////////
	//					MODIFIERS						//
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////
	//assign/////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::Vector<T, Alloc>::assign(size_type n, const value_type &val) {
		if (n > max_size())
			throw std::length_error("EXCEPTION : assign() size is bigger than max_size()");
		clear();
		if (n > _capacity)
		{
			_allocator.deallocate(_start, _capacity);
			
		}
	}

	/////////////////////////////////////////////
	//clear//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::Vector<T, Alloc>::clear() {
		size_type ssize = size();
		for (size_type i = 0; i < ssize; i++)
		{
			_allocator.destroy(_end);
			--_end;
		}
	}
}


