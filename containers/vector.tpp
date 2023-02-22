#include "vector.hpp"

namespace ft 
{
	//------------------Default constructor------------------//
	//constructs an empty container, without elements
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::vector(const allocator_type &alloc)
			:	
				_size(0),
				_capacity(0),
				_allocator(alloc),
				_pointer(NULL)
				// _end(NULL)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Default Constructor has been invoked" << std::endl;
	}

	//------------------Filled constructor------------------//
	//constructs container with n elems. Each elem is a copy of val
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) 
			:	
				_size(n),
				_capacity(n),
				_allocator(alloc),
				_pointer(NULL)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Filled constructor has been invoked" << std::endl;
		//allocates memory for the vector
		_pointer = _allocator.allocate(n);
		//initializes each elem with value <val> by calling "construct"
		for (size_type i = 0; i < n; ++i)
			_allocator.construct(&(_pointer[i]), val);
	}

	//------------------Range constructor------------------//
	//constructs container with as many elems as range [first,last] with each elem constructed from its elem in that range
	//enable_if is used to ensure constructor is only enabled when input itr is not an integral type
	//This is necessary because integral types can be interpreted as integral values and lead to unexpected behavior
	template <typename T, typename Alloc>
	template <typename InputIterator>
	ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*) 
			:	
				_size(0),
				_capacity(0),
				_allocator(alloc)
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Range constructor has been invoked" << std::endl;
		InputIterator tmp = first;
		//calculated the size of range 
		while (tmp != last)
		{
			_size++;
			tmp++;
		}
		//allocates memory for vector and constructs each elem using input iter
		_pointer = _allocator.allocate(_size);
		for (size_type i = 0; i < _size; ++i)
			_allocator.construct(&(_pointer[i]), *first++);
		//sets capacity to be equal to its size
		_capacity = _size;
	}
	//------------------Destructor------------------//
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::~vector() {
		if (M_DEBUG)
			std::cout << "[vECTOR] Destructor has been invoked" << std::endl;
		clear();
		_allocator.deallocate(_pointer, capacity());
	}

	// ------------------Copy Constructor------------------//
	template <typename T, typename Alloc>
	ft::vector<T, Alloc>::vector(const vector &x)
			:	_size(x._size),
				_capacity(x._capacity),
				_allocator(x._allocator)
	{
		if (M_DEBUG)
			std::cout << "[vECTOR] Copy constructor has been invoked" << std::endl;
		_pointer = _allocator.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(&(_pointer[i]), x[i]);
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
		return iterator(_pointer);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin() const {
		if (M_DEBUG)
			std::cout << "begin() const has been invoked" << std::endl;
		return const_iterator (_pointer);
	}

	//////////////////////////////////////////////
	//end --> pointer to last + 1 element/////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end() {
		if (M_DEBUG)
			std::cout << "end() has been invoked" << std::endl;
		return iterator(_pointer + _size);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end() const {
		if (M_DEBUG)
			std::cout << "end() const has been invoked" << std::endl;
		return const_iterator (_pointer + _size);
	}

	//////////////////////////////////////////////
	//rbegin//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin() {
		if (M_DEBUG)
			std::cout << "rbegin() has been invoked" << std::endl;
		return reverse_iterator(_pointer + _size);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const {
		if (M_DEBUG)
			std::cout << "rbegin() const has been invoked" << std::endl;
		return const_reverse_iterator(_pointer + _size);
	}

	//////////////////////////////////////////////
	//rend////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
		if (M_DEBUG)
			std::cout << "rend() has been invoked" << std::endl;
		return reverse_iterator(_pointer);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const {
		if (M_DEBUG)
			std::cout << "rend() const has been invoked" << std::endl;
		return const_reverse_iterator (_pointer);
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
		return *(_pointer + n);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::operator[](size_type n) const {
		if (M_DEBUG)
			std::cout << "operator[] has been invoked" << std::endl;
		return *(_pointer + n);
	}

	//////////////////////////////////////////////
	//at//////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::at(size_type n) {
		if (_pointer == NULL)
			throw std::out_of_range("accesing empty vector");
		if (n >= size()) {
			throw std::out_of_range("index is out of range in at()");
		}
		if (M_DEBUG)
			std::cout << "at() has been invoked" << std::endl;
		return (_pointer[n]);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(size_type n) const {
		if (_pointer == NULL)
			throw std::out_of_range("accesing empty vector");
		if (n >= size()) {
			throw std::out_of_range("index is out of range in at()");
		}
		if (M_DEBUG)
			std::cout << "at() const has been invoked" << std::endl;
		return (_pointer[n]);
	}

	//////////////////////////////////////////////
	//front --> first element////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front() {
		if (size() == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_pointer)
			std::out_of_range("can't call empty container with front()");
		if (M_DEBUG)
			std::cout << "front() has been invoked" << std::endl;
		return (*_pointer);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front() const {
		if (size() == 0)
			std::out_of_range("can't call empty container with front()");
		if (!_pointer)
			std::out_of_range("can't call empty container with front()");
		if (M_DEBUG)
			std::cout << "front() const has been invoked" << std::endl;
		return (*_pointer);
	}

	//////////////////////////////////////////////
	//back --> last element////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back() {
		if (size() == 0)
			std::out_of_range("can't call back() if size == 0");
		if (!_pointer)
			std::out_of_range("can't call back() if the container is empty");
		if (M_DEBUG)
			std::cout << "back() has been invoked" << std::endl;
		return (_pointer[_size - 1]);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back() const {
		if (size() == 0)
			std::out_of_range("ca't call back() if size == 0");
		if (!_pointer)
			std::out_of_range("can't call back() if the container is empty");
		if (M_DEBUG)
			std::cout << "back() const has been invoked" << std::endl;
		return (_pointer[_size - 1]);
	}

	//////////////////////////////////////////////
	//data////////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data() {
		if (M_DEBUG)
			std::cout << "data() has been invoked" << std::endl;
		return (_pointer);
	}

	template <typename T, typename Alloc>
	const typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data() const {
		if (M_DEBUG)
			std::cout << "data() const has been invoked" << std::endl;
		return (_pointer);
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
		return (_size);
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
		if (n > max_size())
			throw std::length_error("n more than max_size() in resize()");
		if (n > _capacity)
		{
			size_type tmp_cap = _capacity;
			while(tmp_cap < n)
				tmp_cap *= 2;
			reallocate(tmp_cap, value);
		}
		else if (n > _size)
		{
			for (size_type i = _size; i < n; ++i)
				_allocator.construct(&(_pointer[i]), value);
		}
		else if (n < _size)
		{
			for (size_type i = n - 1; i < _size; ++i)
				_allocator.destroy(&(_pointer[i]));
		}
		_size = n;
	}

	//////////////////////////////////////////////
	//empty//////////////////////////////////////
	//////////////////////////////////////////////
	template <typename T, typename Alloc>
	bool ft::vector<T, Alloc>::empty() const {
		return (_size == 0);
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
		if (n > max_size())
		{
			throw std::length_error("n is bigger than max_size()");
		}
		if (n > _capacity)
		{
			//allocates new memory
			pointer tmp = _allocator.allocate(n);
			//loops through existing ones, constructs new elems in new memory block by copying the old ones and destroys the old elems
			for (size_type i = 0; i < _size; i++)
			{
				_allocator.construct(tmp + i, *(_pointer + i));
				_allocator.destroy(_pointer + i);
			}
			//deallocates old memory
			_allocator.deallocate(_pointer, _capacity);
			//updates pointer and cap to the new memory
			_pointer = tmp;
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

		while (first != last)
		{
			push_back(*first);
			first++;
		}

		insert(begin(), first, last);
	}

	/////////////////////////////////////////////
	//clear//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::clear() {
		for (size_type i = 0; i < _size; i++)
		{
			
			_allocator.destroy(&(_pointer[i]));
		}
			_size = 0;
	}

	/////////////////////////////////////////////
	//swap//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::swap(vector &x) {
		pointer tmp_pointer = _pointer;
		allocator_type tmp_allocator = _allocator;
		size_type tmp_size = _size;
		size_type tmp_capacity = _capacity;

		_pointer = x._pointer;
		_allocator = x._allocator;
		_size = x._size;
		_capacity = x._capacity;

		x._pointer = tmp_pointer;
		x._allocator = tmp_allocator;
		x._size = tmp_size;
		x._capacity = tmp_capacity;
	}

	/////////////////////////////////////////////
	//push_back//////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::push_back(const value_type &value) {
		if (!_capacity)
			reallocate(1);
		if (_size == _capacity)
			reallocate(_capacity * 2);
		_allocator.construct(_pointer + _size, value);
		++_size;
	}

	/////////////////////////////////////////////
	//pop_back///////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::pop_back() {
		if (!_size)
			return ;
		_allocator.destroy(&(_pointer[_size - 1]));
		--_size;
	}

	/////////////////////////////////////////////
	//insert/////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(iterator position, const value_type &value) {
		if (!_pointer)
		{
			_pointer = _allocator.allocate(1);
			_allocator.construct(&_pointer[0], value);
			_size = 1;
			_capacity = 1;
			return iterator(&_pointer[0]);
		}
		size_type counter = 0;
		for (iterator it = begin(); it != position; ++it)
			++counter;
		if (_size == _capacity)
		{
			if (!_capacity)
				reallocate(1);
			else
				reallocate(_capacity * 2);
		}
		//copies each element to the next higher index and destroys original element. This creates empty slot at pos itr.
		for (size_type i = _size; i > counter; --i)
		{
			_allocator.construct(&(_pointer[i]), _pointer[i - 1]);
			_allocator.destroy(&(_pointer[i - 1]));
		}
		//constructs new elem at pos itr using given value, increments size and returns itr to inserted element
		_allocator.construct(&(_pointer[counter]), value);
		++_size;
		return (iterator(&(_pointer[counter])));
	}

	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val) {
		if (!_pointer)
		{
			_pointer = _allocator.allocate(n);
			for (size_type i = 0; i < n; ++i)
				_allocator.construct(&_pointer[i], val);
			_size = n;
			_capacity = n;
			return ;
		}
		size_type counter = 0;
		for (iterator it = begin(); it != position; ++it)
			++counter;
		if (_size + n >= _capacity)
		{
			if (!_capacity)
				reallocate(n);
			else
				reallocate(_size + n);
		}
		//copy each elem 'n' positions to the right until elem at index 'count + n' is reached.
		//this makes room for new elems to be inserted
		for (size_type i = (_size + n - 1); i >= counter + n; --i)
		{
			_allocator.construct(&(_pointer[i]), _pointer[i - n]);
			_allocator.destroy(&(_pointer[i - n]));
		}
		//construct 'n' copies of val startin from index 'counter'
		for (size_type i = 0; i < n; ++i)
			_allocator.construct(&(_pointer[counter + i]), val);
		//update size by adding n;
		_size += n;
	}

	template <typename T, typename Alloc>
	template <typename InputIterator>
	void ft::vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type*) {
		if (first == last)
			return;
		size_type tmp_size = 0;
		for (InputIterator tmp_it = first; tmp_it != last; tmp_it++)
			tmp_size++;
		pointer copy_start = NULL;
		pointer copy_end = NULL;
		size_type copy_capacity = 0;
		pointer pointer_pos = position.base();
		InputIterator it_first = first;
		InputIterator it_last = last;
		pointer tmp_pointer = _pointer;

		if (_size + tmp_size >= _capacity)
		{
			copy_capacity = _size + tmp_size;
			if (_size + tmp_size > _capacity * 2)
				copy_capacity = _size + tmp_size;
			else
				copy_capacity = _capacity * 2;
			copy_start = _allocator.allocate(copy_capacity);
			copy_end = copy_start;
				try 
				{
					while(tmp_pointer != pointer_pos)
					{
						_allocator.construct(copy_end, *tmp_pointer);
						_allocator.destroy(tmp_pointer);
						copy_end++;
						tmp_pointer++;
					}
					while (it_first != it_last)
					{
						_allocator.construct(copy_end, *it_first);
						copy_end++;
						it_first++;
					}
					while (tmp_pointer != (_pointer + _size))
					{
						_allocator.construct(copy_end, *tmp_pointer);
						_allocator.destroy(tmp_pointer);
						copy_end++;
						tmp_pointer++;
					}
				}
				catch (...)
				{
					while (copy_start != copy_end)
						_allocator.destroy(copy_end--);
					_allocator.destroy(copy_start);
					_allocator.deallocate(copy_start, copy_capacity);
					throw;
				}
				_allocator.deallocate(_pointer, _capacity);
				_pointer = copy_start;
				_capacity = copy_capacity;
				_size += tmp_size;
			}
			else {
				size_type pos_counter = 0;
				for (iterator it = this->begin(); it != position; it++)
					pos_counter++;
				//shifts elems to the right by tmp_size positions to make room for new elems
				//starts from last elem and moves backwards until it reaches the pos where new elems should be inserted
				//constructs copy of prev elem shifted by tmp_szie and destroys prev element
				for (size_type i = (_size + tmp_size - 1); i >= (pos_counter + tmp_size); i--)
				{
					_allocator.construct(&(_pointer[i]), _pointer[i - tmp_size]);
					_allocator.destroy(&(_pointer[i - tmp_size]));
				}
				//constructs elems starting from pos specified by pos_counter and inserts each elem
				for (size_type i = 0; i < tmp_size; i++)
					_allocator.construct(&(_pointer[pos_counter + i]), *first++);
				//increment size by tmp_size to reflect new_size of vector
				_size += tmp_size;
			}
	}

	/////////////////////////////////////////////
	//erase//////////////////////////////////////
	/////////////////////////////////////////////
	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator position) {
		return erase(position, position + 1);
		}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(iterator first, iterator last) {
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
		_size -= diff_len;
		return first;
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

	template <typename T, typename Alloc>
	void ft::vector<T, Alloc>::reallocate(size_type new_capacity, value_type value)
	{
		//allocate new block of size new_capacity
		pointer tmp = _allocator.allocate(new_capacity);
		//constructs copis of them in new memory block
		for (size_type i = 0; i < _size; ++i)
			_allocator.construct(&(tmp[i]), _pointer[i]);
		//if new_cap is greater than size then it constructs remaining ones with value
		for (size_type i = _size; i < new_capacity; ++i)
			_allocator.construct(&(tmp[i]), value);
		for (size_type i = 0; i < _size; ++i)
			_allocator.destroy(&(_pointer[i]));
		_allocator.deallocate(_pointer, _capacity);
		_pointer = tmp;
		_capacity = new_capacity;
	}
}

namespace std
{
	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc>&lhs, ft::vector<T, Alloc>&rhs)
	{
		lhs.swap(rhs);
	}
}


