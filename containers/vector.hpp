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
#include "../iterators/ft_utils.hpp"

namespace ft
{
	template <class T, class A = std::allocator<T> >
		class vector {

			////////////////////~~~~~~~~~~	PUBLIC MEMBERS ~~~~~~~~~~////////////////////
			public :
			/////////////////////********** ALLOCATOR TYPES **********/////////////////////
			/////////////////////********** base type **********/////////////////////
				typedef					T								value_type;					//type of element
				typedef					A								allocator_type;				//type of memory manager
				typedef					std::ptrdiff_t					difference_type;

			/////////////////////********** pointers and reference **********/////////////////////
				typedef typename		A::reference					reference;					//reference to element
				typedef	typename		A::const_reference				const_reference;
				typedef typename		A::pointer						pointer;					//pointer to element
				typedef	typename		A::const_pointer				const_pointer;
				typedef	typename		A::size_type					size_type;
			

			/////////////////////********** ITERATOR TYPES **********/////////////////////
				typedef  ft::RandomAccessIterator<pointer>					iterator;
				typedef  ft::RandomAccessIterator<const_pointer>			const_iterator;
				typedef  ft::ReverseIterator<iterator>						reverse_iterator;
				typedef  ft::ReverseIterator<const_iterator>				const_reverse_iterator;

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
		explicit vector(const allocator_type &alloc = allocator_type());			
		//------------------Fill constructor(n copies of val)------------------//
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
		//------------------Range constructor(copy from [first:last])------------------//
		template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL);
		//------------------Default destructor------------------//
		~vector();
		//------------------Copy constructor------------------//
		vector(const vector &rhs, const allocator_type &alloc = allocator_type());			
		//------------------Copy assignment operator------------------//
		vector &operator=(const vector &rhs);

		void set_empty(void) {
			clear();
			if (_start)
				_allocator.deallocate(_start, size());
			_start = NULL;
			_end = NULL;
			_capacity = 0;
		}

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

		const_iterator			cend() const;
		//------------------cend------------------//

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
		template <class InputIterator> void assign(InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL);		//fill
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
		template<class InputIterator> void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL);

		//------------------erase------------------//
		iterator erase(iterator position);

		iterator erase(iterator first, iterator last);

		//------------------swap------------------//
		void swap(vector &x);

		// template <typename T, typename Alloc>
		friend void swap(vector &x, vector &y) {
			x.swap(y);
		}

		//------------------clear------------------//
		void clear();



		//------------------get_allocator------------------//
		allocator_type get_allocator() const;

		template <typename InputIterator>
		ptrdiff_t distance_iterator(InputIterator end, InputIterator start);
	};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//***NON-MEMBER FUNCTIONS***/////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//------------------operator==------------------//
		template <typename T, typename Alloc>
		bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return false;
			}
			return true;
		}

		//------------------operator!=------------------//
		template <typename T, typename Alloc>
		bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			return !(lhs == rhs);
		}


		//------------------operator< is a lexicographical ordering------------------//
		template <typename T, typename Alloc>
		bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		// ------------------operator>------------------//
		template <typename T, typename Alloc>
		bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			return rhs < lhs;
		}

		//------------------operator>=------------------//
		template <typename T, typename Alloc>
		bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			return !(lhs < rhs);
		}

		//------------------operator<=------------------//
		template <typename T, typename Alloc>
		bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
			return !(lhs > rhs);
		}
}
#include "vector.tpp"

#endif

