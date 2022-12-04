#ifndef VECTOR_HPP
# define VECTOR_HPP

#ifndef M_DEBUG
#define M_DEBUG 0
#endif

#include <iostream>
#include <vector>
#include <iostream>
#include <memory>
#include <iterator>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
		class Vector {
			
			////////////////////~~~~~~~~~~	PUBLIC MEMBERS ~~~~~~~~~~////////////////////
			public :
			/////////////////////********** ALLOCATOR TYPES **********/////////////////////
			/////////////////////********** base type **********/////////////////////
				typedef					T										value_type;
				typedef					Alloc									allocator_type;

			/////////////////////********** pointers and reference **********/////////////////////
				typedef typename		allocator_type::reference				reference;
				typedef	typename		allocator_type::const_reference			const_reference;
				typedef	typename		allocator_type::pointer					pointer;
				typedef	typename		allocator_type::const_pointer			const_pointer;
				typedef	typename		allocator_type::size_type				size_type;
			

			/////////////////////********** ITERATOR TYPES **********/////////////////////
			typedef typename			alloc

			////////////////////~~~~~~~~~~	PRIVATE MEMBERS ~~~~~~~~~~////////////////////
			private:
					size_type				_size;
					allocator_type			_alloc;
					pointer					_first;
					pointer					_last;

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

	};
				

}

#include "vector.tpp"

#endif













	// class Vector
	// {

	// 	public :
	// 			Vector();
	// 			~Vector();
	// 			Vector(const Vector &rhs);
	// 			Vector(int elem, int init_val);
	// 			// Vector( const std::initializer_list<int>& list);
	// 			void pushToBack(int val);
	// 			void popBack();
	// 			int *print(int val);
	// 			bool isEmpty() const;
	// 			int Size() const;
	// 			int Capacity() const;

	// 			bool operator==(const Vector &rhs) const;
	// 			bool operator!=(const Vector &rhs) const;

	// 			friend std::ostream& operator <<(std::ostream &os, const Vector &rhs);

	// 	private :
	// 			int *_Array;
	// 			int _size;
	// 			int _capacity;

	// };