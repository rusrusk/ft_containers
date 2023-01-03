#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

#include <iterator>
#include <iostream>
#include "ft_iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class RandomAccessIterator {
	public :
		typedef Iterator	iterator_type;
		typedef typename	ft::random_access_iterator_tag						iterator_category;
		typedef typename	ft::iterator_traits<iterator_type>::value_type		value_type;
		typedef typename	ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename	ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename	ft::iterator_traits<iterator_type>::reference		reference;

	protected :
		pointer _pointer;

	public :
		//---------------CONSTRUCTOR---------------//
		RandomAccessIterator(pointer ptr_param) : _pointer(ptr_param) {};

		//---------------COPY CONSTRUCTOR---------------//
		template<class I>
		RandomAccessIterator(const RandomAccessIterator<I> &it) : _pointer(it.base()) {};

		//---------------DESTRUCTOR---------------//
		virtual ~RandomAccessIterator() {};

		//---------------BASE---------------//
		pointer base() const {
			return _pointer;
		}

		//--------------COPY ASSIGNMENT OPERATOR---------------//
		RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
			if (this != &rhs)
				return *this;
			_pointer = rhs._pointer;
			return *this;
		}

		//--------------PREFIX INCREMENT OPERATOR---------------//
		RandomAccessIterator &operator++() {
			_pointer++;
			return *this;
		}

		//--------------POSTFIX INCREMENT OPERATOR---------------//
		RandomAccessIterator operator++(int) {
			RandomAccessIterator tmp(*this);
			++(*this);
			return (tmp);
		}

		//--------------PREFIX DECREMENT OPERATOR---------------//
		RandomAccessIterator &operator--() {
			_pointer--;
			return *this;
		}

		//--------------POSTFIX DECREMENT OPERATOR---------------//
		RandomAccessIterator operator--(int) {
			RandomAccessIterator tmp(*this);
			--(*this);
			return (tmp);
		}


		//--------------ARITHMETIC OPERATORS---------------//
		RandomAccessIterator operator+(difference_type n) const {
			return _pointer + n;
		}

		RandomAccessIterator operator-(difference_type n) const {
			return _pointer - n;
		}

		//ptrdiff_t operator-()

		//--------------REFERENCE AND DEREFERENCE OPERATORS---------------//
		pointer operator->() const {
			return _pointer;
		}

		reference operator*() const {
			return *_pointer;
		}



	};
		//--------------EQUALITY AND INEQUALITY COMPARISON OVERLOAD OPERATORS---------------//
		template<typename IterLhs, typename IterRhs>
		bool operator==(const RandomAccessIterator<IterLhs> &lhs, const RandomAccessIterator<IterRhs> &rhs) {
			return lhs.base() == rhs.base();
		}

		template<class IterLhs, typename IterRhs>
		bool operator!=(const RandomAccessIterator<IterLhs> &lhs, const RandomAccessIterator<IterRhs> &rhs) {
			return lhs.base() != rhs.base();
		}

		//--------------RELATIONAL OPERATORS---------------//
		template<typename IterLhs, typename IterRhs>
		bool operator>(const RandomAccessIterator<IterLhs> &lhs, const RandomAccessIterator<IterRhs> &rhs) {
			return lhs.base() > rhs.base();
		}

		template <typename IterLhs, typename IterRhs>
		bool operator<(const RandomAccessIterator<IterLhs> &lhs, const RandomAccessIterator<IterRhs> &rhs) {
			return lhs.base() < rhs.base();
		}

		template <typename IterLhs, typename IterRhs>
		bool operator>=(const RandomAccessIterator<IterLhs> &lhs, const RandomAccessIterator<IterRhs> &rhs) {
			return lhs.base() >= rhs.base();
		}

		template<typename IterLhs, typename IterRhs>
		bool operator<=(const RandomAccessIterator<IterLhs> &lhs, const RandomAccessIterator<IterRhs> &rhs) {
			return lhs.base() <= rhs.base();
		}

}








#endif