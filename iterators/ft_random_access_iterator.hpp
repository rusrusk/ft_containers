#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

#include <iterator>
#include <iostream>
#include "ft_iterator_traits.hpp"

namespace ft
{
	// template <typename IteratorType>
	// class ConstRandomAccessIterator;

	template <typename IteratorType>
	class RandomAccessIterator {
	public :
		typedef				IteratorType													iterator_type;
		typedef typename	ft::random_access_iterator_tag									iterator_category;
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
		template <typename Iter>
		RandomAccessIterator(const RandomAccessIterator<Iter> &it) : _pointer(it.base()) {};


		//---------------POINTER CONSTRUCTOR---------------//
		RandomAccessIterator(pointer ptr) : _pointer(ptr) {};


		//---------------DESTRUCTOR---------------//
		~RandomAccessIterator() {};

		//---------------BASE---------------//
		pointer base() const {
			return _pointer;
		}

		//--------------COPY ASSIGNMENT OPERATOR---------------//
		// template <typename Iter>
		RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
			if (this == &rhs)
				return *this;
			_pointer = rhs._pointer;
			return *this;
		}

		// RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
		// 	_pointer = rhs._pointer;
		// 	return (*this);
		// }

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
		pointer operator->() const {
			return (_pointer);
		}

		reference operator*() const {
			return (*_pointer);
		}

		reference operator[](const difference_type& n) const {
			return (*(_pointer + n));
		}

		// //--------------EQUALITY AND INEQUALITY COMPARISON OVERLOAD OPERATORS---------------//
		// // template<typename IterLhs, typename IterRhs>
		// bool operator==(const RandomAccessIterator<IteratorType> rhs) const {
		// 	return base() == rhs.base();
		// }

		// // template<class IterLhs, typename IterRhs>
		// bool operator!=(const RandomAccessIterator<IteratorType> rhs) const {
		// 	return base() != rhs.base();
		// }

		// //--------------RELATIONAL OPERATORS---------------//
		// // template<typename IterLhs, typename IterRhs>
		// bool operator>(const RandomAccessIterator<IteratorType> rhs) const {
		// 	return base() > rhs.base();
		// }

		// // template <typename IterLhs, typename IterRhs>
		// bool operator<(const RandomAccessIterator<IteratorType> rhs) const {
		// 	return base() < rhs.base();
		// }

		// // template <typename IterLhs, typename IterRhs>
		// bool operator>=(const RandomAccessIterator<IteratorType> rhs) const {
		// 	return base() >= rhs.base();
		// }

		// // template<typename IterLhs, typename IterRhs>
		// bool operator<=(const RandomAccessIterator<IteratorType> rhs) const {
		// 	return base() <= rhs.base();
		// }

		// //--------------RELATIONAL OPERATORS USING CONST ITERATORS---------------//
		// bool operator==(const ConstRandomAccessIterator<IteratorType>rhs) const {
		// 	return (base() == rhs.base());
		// }

		// bool operator!=(const ConstRandomAccessIterator<IteratorType>rhs) const {
		// 	return (base() != rhs.base());
		// }

		// bool operator<(const ConstRandomAccessIterator<IteratorType>rhs) const {
		// 	return (base() < rhs.base());
		// }

		// bool operator>(const ConstRandomAccessIterator<IteratorType>rhs) const {
		// 	return (base() > rhs.base());
		// }

		// bool operator>=(const ConstRandomAccessIterator<IteratorType>rhs) const {
		// 	return (base() >= rhs.base());
		// }

		// bool operator<=(const ConstRandomAccessIterator<IteratorType>rhs) const {
		// 	return (base() <= rhs.base());
		// }




	};

	// template <typename Iter1, typename Iter2>
	// bool operator==(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() == rhs.base();
	// }
	// template <typename Iter1>
	// bool operator==(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() == rhs.base();
	// }
	// template <typename Iter1, typename Iter2>
	// bool operator!=(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() != rhs.base();
	// }
	// template <typename Iter1>
	// bool operator!=(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() != rhs.base();
	// }
	// template <typename Iter1, typename Iter2>
	// bool operator<(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() < rhs.base();
	// }
	// template <typename Iter1>
	// bool operator<(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() < rhs.base();
	// }
	// template <typename Iter1, typename Iter2>
	// bool operator<=(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() <= rhs.base();
	// }
	// template <typename Iter1>
	// bool operator<=(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() <= rhs.base();
	// }
	// template <typename Iter1, typename Iter2>
	// bool operator>(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() > rhs.base();
	// }
	// template <typename Iter1>
	// bool operator>(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() > rhs.base();
	// }
	// template <typename Iter1, typename Iter2>
	// bool operator>=(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() >= rhs.base();
	// }
	// template <typename Iter1>
	// bool operator>=(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() >= rhs.base();
	// }

	// template <typename Iter1, typename Iter2>
	// typename ft::iterator_traits<Iter1>::difference_type operator-(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter2> &rhs) {
	// 	return lhs.base() - rhs.base();
	// }

	// template <typename Iter1>
	// typename ft::iterator_traits<Iter1>::difference_type operator-(const RandomAccessIterator<Iter1> &lhs, const RandomAccessIterator<Iter1> &rhs) {
	// 	return lhs.base() - rhs.base();
	// }

	// template <typename Iter1>
	// RandomAccessIterator<Iter1> operator+(typename ft::iterator_traits<Iter1>::difference_type n, const RandomAccessIterator<Iter1> &rhs) {
	// 	return RandomAccessIterator<Iter1>(rhs.base() + n);
	// }













	// template <typename IteratorType>
	// class ConstRandomAccessIterator : public ft::iterator<random_access_iterator_tag, IteratorType>
	// {
	// 	public :
	// 			typedef const 	typename 	ft::iterator<random_access_iterator_tag, IteratorType>::value_type			value_type;
	// 			typedef 		typename	ft::iterator<random_access_iterator_tag, IteratorType>::difference_type		difference_type;
	// 			typedef 		typename	ft::iterator<random_access_iterator_tag, IteratorType>::pointer				pointer;
	// 			typedef 		typename	ft::iterator<random_access_iterator_tag, IteratorType>::reference			reference;
	// 			typedef 		typename	ft::iterator<random_access_iterator_tag, IteratorType>::iterator_category	iterator_category;

	// 	protected :
	// 			pointer _pointer;

	// 	public :

	// 		ConstRandomAccessIterator() : _pointer(NULL) {};

	// 		ConstRandomAccessIterator(const ConstRandomAccessIterator &rhs) : _pointer(rhs._pointer) {};

	// 		ConstRandomAccessIterator(pointer ptr) : _pointer(ptr) {};

	// 		template <class Iter>
	// 		ConstRandomAccessIterator(const RandomAccessIterator<Iter> &rhs) : _pointer(rhs.base()) {};

	// 		~ConstRandomAccessIterator() {};


	// 		ConstRandomAccessIterator &operator=(const ConstRandomAccessIterator &rhs) {
	// 			_pointer = rhs._pointer;
	// 			return (*this);
	// 		}

	// 		template <typename Iter>
	// 		ConstRandomAccessIterator &operator=(const RandomAccessIterator<Iter>&rhs) {
	// 			_pointer = rhs._pointer;
	// 			return (*this);
	// 		}

	// 		pointer base() const {
	// 			return _pointer;
	// 		}

	// 		reference operator*(void) const {
	// 			return *_pointer;
	// 		}

	// 		pointer operator->() const {
	// 			return (&(operator*()));
	// 		}

	// 		ConstRandomAccessIterator &operator++(void) {
	// 			_pointer++;
	// 			return (*this);
	// 		}

	// 		ConstRandomAccessIterator operator++(int) {
	// 			ConstRandomAccessIterator tmp(*this);
	// 			++(*this);
	// 			return tmp;
	// 		}

	// 		ConstRandomAccessIterator &operator--(void) {
	// 			_pointer++;
	// 			return (*this);
	// 		}

	// 		ConstRandomAccessIterator operator--(int) {
	// 			ConstRandomAccessIterator tmp(*this);
	// 			++(*this);
	// 			return tmp;
	// 		}

	// 		ConstRandomAccessIterator operator+(difference_type n) const {
	// 			return (ConstRandomAccessIterator(_pointer + n));
	// 		}

	// 		ConstRandomAccessIterator operator-(difference_type n) const {
	// 			return (ConstRandomAccessIterator(_pointer - n));
	// 		}

	// 		ConstRandomAccessIterator &operator+=(difference_type n) {
	// 			_pointer += n;
	// 			return (*this);
	// 		}

	// 		ConstRandomAccessIterator &operator-=(difference_type n) {
	// 			_pointer -= n;
	// 			return (*this);
	// 		}

	// 		reference operator[](difference_type n) const {
	// 			return (*(_pointer + n));
	// 		}

	// 		bool operator==(const ConstRandomAccessIterator <IteratorType>rhs) const {
	// 			return (base() == rhs.base());
	// 		}

	// 		bool operator!=(const ConstRandomAccessIterator <IteratorType>rhs) const {
	// 			return (base() != rhs.base());
	// 		}

	// 		bool operator<(const ConstRandomAccessIterator <IteratorType>rhs) const {
	// 			return (base() < rhs.base());
	// 		}

	// 		bool operator>(const ConstRandomAccessIterator<IteratorType>rhs) const {
	// 			return (base() > rhs.base());
	// 		}

	// 		bool operator>=(const ConstRandomAccessIterator<IteratorType>rhs) const {
	// 			return (base() >= rhs.base());
	// 		}

	// 		bool operator<=(const ConstRandomAccessIterator<IteratorType>rhs) const {
	// 			return (base() <= rhs.base());
	// 		}

	// 		//--------------RELATIONAL OPERATORS WITH NON-CONST ITERATORS---------------//
	// 		bool operator==(const RandomAccessIterator<IteratorType> rhs) const {
	// 			return (base() == rhs.base());
	// 		}

	// 		bool operator!=(const RandomAccessIterator<IteratorType> rhs) const {
	// 			return (base() != rhs.base());
	// 		}

	// 		bool operator<(const RandomAccessIterator<IteratorType> rhs) const {
	// 			return (base() < rhs.base());
	// 		}

	// 		bool operator>(const RandomAccessIterator<IteratorType> rhs) const {
	// 			return (base() > rhs.base());
	// 		}

	// 		bool operator>=(const RandomAccessIterator<IteratorType> rhs) const {
	// 			return (base() >= rhs.base());
	// 		}

	// 		bool operator<=(const RandomAccessIterator<IteratorType> rhs) const {
	// 			return (base() <= rhs.base());
	// 		}



			
	// };

		
		template <class Iter>
		RandomAccessIterator<Iter> operator+(typename RandomAccessIterator<Iter>::difference_type const n, RandomAccessIterator<Iter> const &rhs) {
			return (RandomAccessIterator<Iter>(rhs.base() + n));
		}


	// 	template<class T>
	// 	typename RandomAccessIterator<T>::difference_type operator-(const RandomAccessIterator<T> &lhs, const ConstRandomAccessIterator<const T> &rhs)
	// 	{
	// 	    return (lhs.base() - rhs.base());
	// 	}

	// 	template<class T>
	// 	typename RandomAccessIterator<T>::difference_type operator-(const ConstRandomAccessIterator<const T> &lhs, const RandomAccessIterator<T> &rhs)
	// 	{
	// 	    return (lhs.base() - rhs.base());
	// 	}

	// 	template<class T>
	// 	typename RandomAccessIterator<T>::difference_type operator-(const ConstRandomAccessIterator<const T> &lhs, const ConstRandomAccessIterator<const T> &rhs)
	// 	{
	// 	    return (lhs.base() - rhs.base());
	// 	}


		

}








#endif