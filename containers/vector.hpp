#ifndef VECTOR_HPP
# define VECTOR_HPP

#ifndef M_DEBUG
#define M_DEBUG 0
#endif

#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include "../iterators/ft_random_access_iterator.hpp"
#include "../iterators/ft_reverse_iterator.hpp"

namespace ft
{
	template <class T, class A = std::allocator<T> >
		class Vector {

			////////////////////~~~~~~~~~~	PUBLIC MEMBERS ~~~~~~~~~~////////////////////
			public :
			/////////////////////********** ALLOCATOR TYPES **********/////////////////////
			/////////////////////********** base type **********/////////////////////
				typedef					T								value_type;					//type of element
				typedef					A								allocator_type;				//type of memory manager

			/////////////////////********** pointers and reference **********/////////////////////
				typedef typename		A::reference					reference;					//reference to element
				typedef	typename		A::const_reference				const_reference;
				typedef typename		A::pointer						pointer;					//pointer to element
				typedef	typename		A::const_pointer				const_pointer;
				typedef	typename		A::size_type					size_type;
			

			/////////////////////********** ITERATOR TYPES **********/////////////////////
				typedef ft::RandomAccessIterator<pointer>				iterator;
				typedef ft::RandomAccessIterator<const_pointer>			const_iterator;
				typedef ft::ReverseIterator<iterator>					reverse_iterator;
				typedef ft::ReverseIterator<const_iterator>				const_reverse_iterator;

			////////////////////~~~~~~~~~~	PRIVATE MEMBERS ~~~~~~~~~~////////////////////
			private:
					size_type				_size;
					size_type				_capacity;
					allocator_type			_allocator;
					pointer					_start;
					pointer					_end;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//***CONSTRUCTORS***///////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	public:
		//------------------Default constructor------------------//
		explicit Vector(const allocator_type &alloc = allocator_type());			
		//------------------Fill constructor------------------//
		explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
		//------------------Range constructor------------------//
		template <class InputIterator> Vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
		//------------------Default destructor------------------//
		~Vector();		
		//------------------Copy constructor------------------//
		Vector(const Vector &rhs);			
		//------------------Copy assignment operator------------------//
		Vector operator=(const Vector &rhs);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//***ITERATORS***////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//------------------begin------------------//
		iterator		begin();
		const_iterator	begin() const;

		//------------------end------------------//
		iterator		end();
		const_iterator	end() const;

		//------------------rbegin------------------//
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		//------------------rend------------------//
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		//------------------cbegin------------------//
		const_iterator			cbegin() const;

		//------------------cend------------------//
		const_iterator			cend() const;

		//------------------crbegin------------------//
		const_reverse_iterator	crbegin() const;

		//------------------crend------------------//
		const_reverse_iterator	crend() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//***CAPACITY***/////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//------------------size------------------//
		size_type		size() const;

		//------------------max_size------------------//
		size_type		max_size() const;

		//------------------resize------------------//
		void 			resize(size_type n, value_type val = value_type());

		//------------------capacity------------------//
		size_type		capacity() const;

		//------------------empty------------------//
		bool empty() const;

		//------------------reserve------------------//
		void reserve (size_type n);

		//------------------shrink_to_fit------------------//
		void shrink_to_fit();

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//***ACCESS ELEMENTS***//////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//------------------Operator []------------------//
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;

		//------------------at------------------//
		reference at(size_type n);
		const_reference at(size_type n) const;

		//------------------at------------------//
		reference front();
		const_reference front() const;

		//------------------back------------------//
		reference back();
		const_reference back() const;

		//------------------data------------------//
		value_type *data();
		const value_type *data() const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//***MODIFIERS***////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//------------------assign------------------//
		//range
		template <class InputIterator> void assign(InputIterator first, InputIterator last);
		//fill
		void assign(size_type n, const value_type &val);

		//------------------push_back------------------//
		void push_back(const value_type &val);

		//------------------pop_back------------------//
		void pop_back();

		//------------------insert------------------//
		//single element
		iterator insert(iterator position, const value_type &val);
		//fill
		void insert(iterator position, size_type n, const value_type &val);
		//range
		template<class InputIterator> void insert(iterator position, InputIterator first, InputIterator last);

		//------------------erase------------------//
		iterator erase(iterator position);

		iterator erase(iterator first, iterator last);

		//------------------swap------------------//
		void swap(Vector &x);

		//------------------clear------------------//
		void clear();

	};
}

#include "vector.tpp"

#endif

