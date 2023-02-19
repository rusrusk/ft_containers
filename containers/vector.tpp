#include "vector.hpp"

namespace ft 
{
	//------------------Default constructor------------------//
	//constructs an empty container, without elements
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::vector(const allocator_type &alloc)
			:	
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
	ft::vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) 
			:	
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Filled constructor has been invoked" << std::endl;
		assign(n, val);
		// _start = _allocator.allocate(n);
		// _end = _start;
		// while (n--)
		// {
		// 	_allocator.construct(_end, val);
		// 	_end++;
		// }
	}

	//------------------Range constructor------------------//
	//constructs container with as many elems as range [first,last] with each elem constructed from its elem in that range
	template <typename T, typename Alloc>
	template <typename InputIterator>
	ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type*) 
			:	
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Range constructor has been invoked" << std::endl;
		// _start = _allocator.allocate(last.base() - first.base());
		// _end = _start;
		// while (first != last)
		// {
		// 	_allocator.construct(_end, *first);
		// 	_end++;
		// 	first++;
		// }

		assign(first, last);
		

	}
	//------------------Destructor------------------//
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::~vector() {
		if (M_DEBUG)
			std::cout << "[vECTOR] Destructor has been invoked" << std::endl;
		clear();
		_allocator.deallocate(_start, capacity());
	}

	// ------------------Copy Constructor------------------//
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::vector(const vector &x, const allocator_type &alloc)
			:
				_capacity(0),
				_allocator(alloc),
				_start(NULL),
				_end(NULL)
	{
		if (M_DEBUG)
			std::cout << "[vECTOR] Copy constructor has been invoked" << std::endl;
		assign(x.begin(), x.end());
	}



	// ------------------Operator= Overloading------------------//
	template <typename T, typename Alloc>
	ft::vector<T, Alloc> & ft::vector<T, Alloc>::operator=(const vector &rhs) {
		if (this == &rhs)
			return *this;
		set_empty();
		assign(rhs.begin(), rhs.end());
		return (*this);
	}
	

	/////////////////////////////////////////////////////////
	//		ITERATORS						/////////////////
	////////////////////////////////////////////////////////

	//////////////////////////////////////////////
	//begin --> pointer to 1st element///////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin() {
		if (M_DEBUG)
			std::cout << "begin() has been invoked" << std::endl;
		return iterator(_start);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin() const {
		if (M_DEBUG)
			std::cout << "begin() const has been invoked" << std::endl;
		return const_iterator (_start);
	}

	//////////////////////////////////////////////
	//end --> pointer to last + 1 element/////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end() {
		if (M_DEBUG)
			std::cout << "end() has been invoked" << std::endl;
		return iterator(_end);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end() const {
		if (M_DEBUG)
			std::cout << "end() const has been invoked" << std::endl;
		return const_iterator (_end);
	}

	//////////////////////////////////////////////
	//rbegin//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin() {
		if (M_DEBUG)
			std::cout << "rbegin() has been invoked" << std::endl;
		return reverse_iterator(_end);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const {
		if (M_DEBUG)
			std::cout << "rbegin() const has been invoked" << std::endl;
		return const_reverse_iterator(_end);
	}

	//////////////////////////////////////////////
	//rend////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
		if (M_DEBUG)
			std::cout << "rend() has been invoked" << std::endl;
		return reverse_iterator(begin());
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const {
		if (M_DEBUG)
			std::cout << "rend() const has been invoked" << std::endl;
		return const_reverse_iterator (begin());
	}

	//////////////////////////////////////////////////////
	//		ELEMENT 		ACCESS						//
	/////////////////////////////////////////////////////

	//////////////////////////////////////////////
	//operator[]//////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference   ft::vector<T, Alloc>::operator[](size_type n) {
	if (M_DEBUG)
			std::cout << "[vECTOR] operator[] has been invoked" << std::endl;
		return *(_start + n);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::operator[](size_type n) const {
		if (M_DEBUG)
			std::cout << "operator[] has been invoked" << std::endl;
		return *(_start + n);
	}

	//////////////////////////////////////////////
	//at//////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::at(size_type n) {
		if (_start == NULL)
			throw std::out_of_range("accesing empty vector");
		if (n >= size()) {
			throw std::out_of_range("index is out of range in at()");
		}
		if (M_DEBUG)
			std::cout << "at() has been invoked" << std::endl;
		return *(_start + n);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(size_type n) const {
		if (_start == NULL)
			throw std::out_of_range("accesing empty vector");
		if (n >= size()) {
			throw std::out_of_range("index is out of range in at()");
		}
		if (M_DEBUG)
			std::cout << "at() const has been invoked" << std::endl;
		return *(_start + n);
	}

	//////////////////////////////////////////////
	//front --> first element////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front() {
		if (size() == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_start)
			std::out_of_range("can't call empty container with front()");
		if (M_DEBUG)
			std::cout << "front() has been invoked" << std::endl;
		return (*_start);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front() const {
		if (size() == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_start)
			std::out_of_range("can't call empty container with front()");
		if (M_DEBUG)
			std::cout << "front() const has been invoked" << std::endl;
		return (*_start);
	}

	//////////////////////////////////////////////
	//back --> last element////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back() {
		if (size() == 0)
			std::out_of_range("can't call back() if size == 0");
		if (!_end)
			std::out_of_range("can't call back() if the container is empty");
		if (M_DEBUG)
			std::cout << "back() has been invoked" << std::endl;
		return (*(_end - 1));
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back() const {
		if (size() == 0)
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
	typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data() {
		if (M_DEBUG)
			std::cout << "data() has been invoked" << std::endl;
		return (*_start);
	}

	template <typename T, typename Alloc>
	const typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data() const {
		if (M_DEBUG)
			std::cout << "data() const has been invoked" << std::endl;
		return (*_start);
	}

	//////////////////////////////////////////////////////
	//					CAPACITY						//
	/////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
	//size -->gives current number of elements//////////////////
	////////////////////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size() const {
		if (M_DEBUG)
			std::cout << "size() const has been invoked" << std::endl;
		return (_end - _start);
	}

	/////////////////////////////////////////////////////
	//max_size -->size of the largest possible vector////
	/////////////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size() const {
		if (M_DEBUG)
			std::cout << "max_size() const has been invoked" << std::endl;
		return (allocator_type().max_size());
	}

	////////////////////////////////////////////////////
	//resize --> added elements initialized by value////
	////////////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::resize(size_type n, value_type value) {
		size_type prev_size = size();
		if (n > max_size())
			throw std::length_error("n more than max_size() in resize()");
		if (n < prev_size) {
			for (size_type i = 0; i < prev_size; i++)
			{
				_allocator.destroy(_start + i);
			}
			_end = _start + n;
		}
		else
		{
			if (n > 2 * _capacity)
				reserve(n);
			else if (n > _capacity)
				reserve(2 * _capacity);
			for (; prev_size < n; prev_size++)
			{
				_allocator.construct(_start + prev_size, value);
			}
			_end = _start + n;
		}
	}

	//////////////////////////////////////////////
	//empty//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	bool ft::vector<T, Alloc>::empty() const {
		return (_start == _end);
	}

	///////////////////////////////////////////////////////////////////////
	//capacity --> size of the memory(in number of elements)allocated//////
	///////////////////////////////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity() const {
		return (_capacity);
	}

	////////////////////////////////////////////////////////////////////////
	//reserve --> gives current number of reserved memory slots; dont initialize any elements!////////
	///////////////////////////////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::reserve(size_type n) {
		size_type previous_size = size();
		if (n > max_size())
		{
			throw std::length_error("n is bigger than max_size()");
		}
		if (n > _capacity)
		{
			pointer tmp = _allocator.allocate(n);
			for (size_type i = 0; i < previous_size; i++)
			{
				_allocator.construct(tmp + i, *(_start + i));
				_allocator.destroy(_start + i);
			}
			_allocator.deallocate(_start, _capacity);
			_start = tmp;
			_end = _start + previous_size;
			_capacity = n;
		}
	}


	
	//////////////////////////////////////////////////////
	//					MODIFIERS						//
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////
	//assign --> n copies of val/////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::assign(size_type n, const value_type &init_value) {
		// if (n > max_size())
		// 	throw std::length_error("EXCEPTION : assign() size is bigger than max_size()");
		// if (n == 0)
		// 	return ;
		// if (n > _capacity)
		// {
		// 	_allocator.deallocate(_start, _capacity);
		// 	_start = _allocator.allocate(n);
		// 	// _capacity = _start + n;
		// 	_end = _start + n;

		// }
		// for (size_type i = 0; i < n; i++)
		// {
		// 	_allocator.construct(_start + i, init_value);
		// }
		// 	_end = _start + n;	
		clear();
		reserve(n);
		insert(begin(), n, init_value);
	}

	/////////////////////////////////////////////
	//assign -->copy from [first:last]///////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	template <typename InputIterator>
	void ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type*) {
		clear();
		reserve(distance_iterator(last, first));
		// while (first != last)
		// {
		// 	push_back(*first);
		// 	first++;
		// }
		insert(begin(), first, last);
	}

	/////////////////////////////////////////////
	//clear//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::clear() {
		size_type ssize = size();
		for (size_type i = 0; i < ssize; i++)
		{
			
			_allocator.destroy(_end);
			_end--;
		}
	}

	/////////////////////////////////////////////
	//swap//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::swap(vector &x) {
		
		ft::swap(_allocator, x._allocator);
		ft::swap(_start, x._start);
		ft::swap(_end, x._end);
		ft::swap(_capacity, x._capacity);
	}

	// template <typename T, typename Alloc>
	// void ft::vector<T, Alloc>::swap(vector<T, Alloc>&x, vector<T, Alloc>&y) {
	// 	x.swap(y);
	// }

	/////////////////////////////////////////////
	//push_back//////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::push_back(const value_type &value) {
		// size_type prev_size = size();
		// if (prev_size > max_size())
		// 	std::length_error("length error in push_back()");
		// if (prev_size == _capacity)
		// {
		// 	resize(prev_size + 1, value);
		// }
		// _allocator.construct(_start + prev_size++, value);
		// // _end++;
		insert(_end, value);
	}

	/////////////////////////////////////////////
	//pop_back///////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::pop_back() {
		if (_end <= _start)
			return ;
		_allocator.destroy(_end);
		--_end;
	}

	/////////////////////////////////////////////
	//insert/////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(iterator position, const value_type &value) {
		size_type diff = position - begin();
		insert(position, 1, value);
		return (begin() + diff);
		// size_type prev_size = size();
		// size_type prev_capacity = capacity();
		// pointer tmp0;
		// pointer tmp1 = _start;
		// size_type i = 0;
		
		// if (position > end() || position < begin())
		//  	std::logic_error("EXCEPTION : insert() error");
		// // difference_type position_diff = position - iterator(begin());
		// if (prev_size > prev_capacity && _capacity * 2 <= max_size())
		// {
		// 	tmp0 = _allocator.allocate(_capacity * 2);
		// 	_capacity = _capacity * 2;
		// }
		// else if (_capacity * 2 > max_size())
		// 	std::length_error("EXCEPTION : longer than max_size()");
		// else if (prev_capacity > prev_size)
		// 	tmp0 = _allocator.allocate(_capacity);
		// while (_start + i != position.base())
		// {
		// 	std::cout << "hey\n";
		// 	_allocator.construct(tmp0 + i, *(_start + i));
		// 	_allocator.destroy(_start + i);
		// 	i++;
		// }
		// _allocator.construct(tmp0 + i, value);
		// tmp1 = tmp0 + i;
		// i++;
		// while (_start + i - 1 != _end)
		// {
		// 	_allocator.construct(tmp0 + i, *(_start + i - 1));
		// 	_allocator.destroy(_start + i - 1);
		// 	i++;
		// }
		// _allocator.deallocate(_start, prev_capacity);
		// tmp0 = _start;
		// _end = _start + prev_size + 1;
		// return (iterator(tmp1));
	}

	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val) {
		size_type prev_size = size();
		size_type prev_capacity = capacity();
		pointer tmp0;
		size_type i = 0;

		if (position > end() || position < begin())
			std::logic_error("EXCEPTION : insert() error");
		if (n < 0 || n + prev_size > max_size())
			std::length_error("EXCEPTION : insert() error");
		if (prev_size + n > _capacity)
		{
			if (_capacity + n > max_size())
				std::length_error("EXCEPTION : insert() error : bigger than max_size()");
			tmp0 = _allocator.allocate(_capacity + n);
			_capacity = _capacity + n;
		}
		else
		{
			tmp0 = _allocator.allocate(_capacity);
		}
		while (_start + i != position.base())
		{
			_allocator.construct(tmp0 + i, *(_start + i));
			_allocator.destroy(_start + i);
			i++;
		}
		for (size_type helper = n; helper > 0; --helper) {
			_allocator.construct(tmp0 + i, val);
			i++;
		}
		while (_start + i - n != _end)
		{
			_allocator.construct(tmp0 + i, *(_start + i - n));

			_allocator.destroy(_start + i - n);
			i++;
		}
		_allocator.deallocate(_start, prev_capacity);
		_start = tmp0;
		_end = _start + prev_size + n;
	}

	template <typename T, typename Alloc>
	template <typename InputIterator>
	void ft::vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type*) {
		while (first != last)
		{
			position = insert(position, *first);
			position++;
			first++;
		}
	}

	/////////////////////////////////////////////
	//erase//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator position) {
		// if (position > end() || position < begin())
		// 	std::logic_error("EXCEPTION : erase() error : out of range!");
		// pointer ptr = position.base();
		// _allocator.destroy(ptr);
		// iterator result(ptr);
		// for (; ptr != _end; ptr++)
		// {
		// 	_allocator.construct(ptr, *(ptr + 1));
		// 	_allocator.destroy(ptr + 1);
		// }
		// _end = ptr;
		// return result;
		return erase(position, position + 1);
		// difference_type diff(position - (iterator)(begin()));
		// for (size_type i = 0; diff + i + 1 < size(); i++) {
		// 	_allocator.construct(_start + diff + i, *(_start + diff + i + 1));
		// }
		// _allocator.destroy(_start + size() - 1);
		// _end -= 1;
		// return iterator(_start + diff);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator first, iterator last) {
		// if (first.base() > last.base())
		// 	throw std::logic_error("EXCEPTION : first range iterator is more than last");
		// if (!(first.base() >= _start && first.base() < _end) || !(last.base() >= _start && last.base() < _end))
		// 	throw std::out_of_range("EXCEPTION : InputIter points outside of range of vector!");
		// pointer tmp = _allocator.allocate(_capacity);
		// pointer first_base = first.base();
		// pointer last_base = last.base();
		// size_type i = 0;
		// size_type j;

		// for (; _start + i != first_base; i++)
		// {
		// 	_allocator.construct(tmp + i, *(_start + i));
		// 	_allocator.destroy(_start + i);
		// }
		// j = i;
		// iterator out(tmp + i);
		// for (; _start + i < last_base; i++)
		// {
		// 	_allocator.destroy(_start + i);
		// }
		// for (; _start + i != _end; i++)
		// {
		// 	_allocator.construct(tmp + j, *(_start + i));
		// 	_allocator.destroy(_start + i);
		// 	j++;
		// }
		// _allocator.deallocate(_start, _capacity);
		// _start = tmp;
		// _end = tmp + j;
		// return out;

		size_type diff_len = distance_iterator(last, first);
		size_type rest_len = distance_iterator(end(), last);
		for (size_type i = 0; i < diff_len; ++i)
		{
			_allocator.destroy(first.base() + i);
		}
		for (size_type i = 0; i < rest_len; ++i)
		{
			first.base()[i] = last.base()[i];
			_allocator.destroy(last.base() + i);
		}
		_end -= diff_len;
		return first;
		// if (size() == 0)
			// std::cout << "error 4" << std::endl;

		// std::cout << _end - _start << std::endl;
			
		// if (first.base() > last.base())
			// std::cout << "error 1" << std::endl;

		// if(first.base() >= _end)
			// std::cout << "error 2.1" << std::endl;
		// if (first.base() < _start)
			// std::cout << "error 2.2" << std::endl;

		// if(last.base() >= _end)
			// std::cout << "error 3.1" << std::endl;
		// if(last.base() < _start)
			// std::cout << "error 3.2" << std::endl;

	}


	/////////////////////////////////////////////
	//get_allocator//////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::allocator_type ft::vector<T, Alloc>::get_allocator() const {
		return (_allocator);
	}

	/////////////////////////////////////////////
	//distance///////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	template <typename InputIterator>
	ptrdiff_t ft::vector<T, Alloc>::distance_iterator(InputIterator end, InputIterator start) {
		ptrdiff_t distance;

		distance = 0;

		while (start != end)
		{
			++distance;
			++start;
		}
		return distance;
	}

	// template <typename T, typename Alloc>
	// ft::vector<T, Alloc> ft::vector<T, Alloc>::operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
		
	// }

	// template <typename T, typename Alloc>
	// ft::vector<T, Alloc> ft::vector<T, Alloc>::operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {

	// }
}




