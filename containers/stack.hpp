#ifndef STACK_HPP
# define STACK_HPP


#include <iostream>
#include "vector.hpp"
#include "../iterators/ft_utils.hpp"


namespace ft
{
	template <typename T, class Container = ft::vector<T> >
	class stack
	{
		public :

			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***CONSTRUCTORS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

	//---------------------------DEFAULT CONSTRUCTOR---------------------------------------//
	explicit stack(const container_type &type = container_type())
		:	_type(type)
	{
		if (M_DEBUG)
            std::cout << "[STACK] Default constructor was invoked" << std::endl;
	}

	//---------------------------COPY CONSTRUCTOR---------------------------------------//
	stack(const stack &rhs)
		:	_type(rhs._type)
	{
		if (M_DEBUG)
            std::cout << "[STACK] Copy constructor was invoked" << std::endl;
	}

	//---------------------------DESTRUCTOR---------------------------------------//
	~stack()
	{
		if (M_DEBUG)
            std::cout << "[STACK] DESTRUCTOR was invoked" << std::endl;
	}

	//---------------------------COPY ASSIGNMENT OPERATOR---------------------------------------//
	stack &operator=(const stack &rhs)
	{
		if (*this == rhs)
			return *this;
		_type = rhs._type;
		return (*this);
	}

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***MEMBER FUNCTIONS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

	//---------------------------empty()---------------------------------------//
	bool empty () const
	{
		return _type.empty();
	}

	//---------------------------size()---------------------------------------//
	size_type size() const
	{
		return _type.size();
	}

	//---------------------------top()---------------------------------------//
	reference top()
	{
		return _type.back();
	}

	const_reference top() const
	{
		return _type.back();
	}

	//---------------------------push()---------------------------------------//
	void push( const value_type &val)
	{
		_type.push_back(val);
	}

	//---------------------------pop()---------------------------------------//
	void pop()
	{
		_type.pop_back();
	}

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***FRIEND MEMBER FUNCTION OVERLOADS***////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

	//---------------------------RELATIONAL OPERATORS FOR STACK---------------------------------------//
	template <class _T, class _Container>
	friend bool operator==(const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs);

	template <class _T, class _Container>
	friend bool operator!=(const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs);

	template <class _T, class _Container>
	friend bool operator<(const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs);

	template <class _T, class _Container>
	friend bool operator<=(const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs);

	template <class _T, class _Container>
	friend bool operator>=(const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs);

	template <class _T, class _Container>
	friend bool operator>(const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs);

		protected :
			container_type	_type;
	};

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***NON-MEMBER FUNCTION OVERLOADS***////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

	//---------------------------NON-MEMBER RELATIONAL OPERATORS FOR STACK---------------------------------//
	template <class T, class Container>
	bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._type == rhs._type);
	}

	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._type != rhs._type);
	}

	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._type < rhs._type);
	}

	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._type <= rhs._type);
	}

	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._type >= rhs._type);
	}

	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._type > rhs._type);
	}
};




#endif