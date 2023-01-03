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
				_pointer(NULL)
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
				_pointer(NULL)
	{
		(void)n;
		(void)val;

		if (M_DEBUG)
			std::cout << "[VECTOR] Filled constructor has been invoked";;
	}

	//------------------Range constructor------------------//
	//constructs container with as many elems as range [first,last] with each elem constructed from its elem in that range
	template <typename T, typename Alloc>
	template <typename InputIterator>
	ft::Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc) 
			:	_size(0),
				_capacity(0),
				_allocator(alloc),
				_pointer(NULL)	
	{
		if (M_DEBUG)
			std::cout << "[VECTOR] Range constructor has been invoked";
	}
	//------------------Destructor------------------//
	template <typename T, typename Alloc>
	ft::Vector<T, Alloc>::~Vector() {
		if (M_DEBUG)
			std::cout << "[VECTOR] Destructor has been invoked";
	}

	
	
}


