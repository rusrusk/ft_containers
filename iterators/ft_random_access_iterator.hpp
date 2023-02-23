#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

#include <iterator>
#include <iostream>
#include "ft_iterator_traits.hpp"

namespace ft
{
	//takes IteratorType as its param, which is the type of underlying itr that the RAI wraps around
	template <typename IteratorType>
	class RandomAccessIterator  {
	public :
		//These are used to define behaviour of itr and are required by STL
		typedef				IteratorType													iterator_type;
		typedef typename	std::random_access_iterator_tag									iterator_category;
		typedef typename	ft::iterator_traits<iterator_type>::value_type					value_type;
		typedef typename	ft::iterator_traits<iterator_type>::difference_type				difference_type;
		typedef typename	ft::iterator_traits<iterator_type>::pointer						pointer;
		typedef typename	ft::iterator_traits<iterator_type>::reference					reference;

	protected :
		pointer _pointer;

	public :
		//---------------CONSTRUCTOR---------------//
		RandomAccessIterator() : _pointer(NULL) {};

		//---------------COPY CONSTRUCTOR---------------//
		//allows creating a new RAI from existing one
		template <typename Iter>
		RandomAccessIterator(const RandomAccessIterator<Iter> &it) : _pointer(it.base()) {};


		//---------------POINTER CONSTRUCTOR---------------//
		//takes a poiinter to underlying iterator
		RandomAccessIterator(pointer ptr) : _pointer(ptr) {};


		//---------------DESTRUCTOR---------------//
		~RandomAccessIterator() {};

		//---------------BASE---------------//
		//returns underlying iterator
		pointer base() const {
			return _pointer;
		}

		//--------------COPY ASSIGNMENT OPERATOR---------------//
		RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
			if (this == &rhs)
				return *this;
			_pointer = rhs._pointer;
			return *this;
		}

		//--------------PREFIX INCREMENT OPERATOR---------------//
		RandomAccessIterator &operator++() {
			++_pointer;
			return (*this);
		}

		//--------------POSTFIX INCREMENT OPERATOR---------------//
		RandomAccessIterator operator++(int) {
			RandomAccessIterator tmp(*this);
			++(*this);
			return (tmp);
		}

		//--------------PREFIX DECREMENT OPERATOR---------------//
		RandomAccessIterator &operator--() {
			--_pointer;
			return (*this);
		}

		//--------------POSTFIX DECREMENT OPERATOR---------------//
		RandomAccessIterator operator--(int) {
			RandomAccessIterator tmp(*this);
			--(*this);
			return (tmp);
		}


		//--------------ARITHMETIC OPERATORS---------------//
		RandomAccessIterator operator+(difference_type n) const {
			return (RandomAccessIterator (_pointer + n));
		}

		RandomAccessIterator operator-(difference_type n) const {
			return (RandomAccessIterator (_pointer - n));
		}

		RandomAccessIterator operator+=(difference_type n) {
			_pointer += n;
			return (*this);
		}

		RandomAccessIterator &operator-=(difference_type n) {
			_pointer -= n;
			return (*this);
		}

		template <typename Iter>
		bool operator==(const RandomAccessIterator<Iter> &rhs) const {
			return _pointer == rhs.base();
		}

		template <typename Iter>
		bool operator!=(const RandomAccessIterator<Iter> &rhs) const {
			return _pointer != rhs.base();
		}

		template <typename Iter>
		ptrdiff_t operator-(const RandomAccessIterator<Iter> &rhs) const {
			return base() - rhs.base();
		}

		template <typename Iter>
		bool operator>(const RandomAccessIterator<Iter> &rhs) const {
			return _pointer > rhs.base();
		}
		template <typename Iter>
		bool operator<(const RandomAccessIterator<Iter> &rhs) const {
			return _pointer < rhs.base();
		}
		template <typename Iter>
		bool operator>=(const RandomAccessIterator<Iter> &rhs) const {
			return _pointer >= rhs.base();
		}
		template <typename Iter>
		bool operator<=(const RandomAccessIterator<Iter> &rhs) const {
			return _pointer <= rhs.base();
		}


		//--------------REFERENCE AND DEREFERENCE OPERATORS---------------//
		//overloaded reference and dereference opers allow accessing value pointed to by the itr
		pointer operator->() const {
			return (_pointer);
		}

		reference operator*() const {
			return (*_pointer);
		}

		reference operator[](const difference_type& n) const {
			return (*(_pointer + n));
		}
	};
		//these non-member methods take 2 arguments of diff types. left side takes int and right side takes object of type RAI
		template <class Iter>
		RandomAccessIterator<Iter> operator+(typename RandomAccessIterator<Iter>::difference_type const n, RandomAccessIterator<Iter> const &rhs) {
			return (RandomAccessIterator<Iter>(rhs.base() + n));
		}

		template<class T>
		typename RandomAccessIterator<T>::difference_type operator-(const RandomAccessIterator<const T> &lhs, const 
		RandomAccessIterator<const T> &rhs)
		{
		    return (lhs.base() - rhs.base());
		}
}

#endif