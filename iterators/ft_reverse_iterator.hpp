#ifndef 	REVERSE_ITERATOR_HPP
# define	REVERSE_ITERATOR_HPP
#include "ft_iterator_traits.hpp"

namespace ft {
	template<class IteratorType>
	class ReverseIterator {
		public :
				typedef 			IteratorType										iterator_type;
				typedef typename	ft::random_access_iterator_tag						iterator_category;
				typedef typename	ft::iterator_traits<iterator_type>::value_type		value_type;
				typedef typename	ft::iterator_traits<iterator_type>::difference_type	difference_type;
				typedef typename	ft::iterator_traits<iterator_type>::pointer			pointer;
				typedef typename	ft::iterator_traits<iterator_type>::reference		reference;	

		private :
				iterator_type	_base_it;

		public :
				//---------------DEFAULT CONSTRUCTOR---------------//
				ReverseIterator( void ) : _base_it() {}

				//---------------INITIALIZATION CONSTRUCTOR---------------//
				explicit ReverseIterator (iterator_type it) : _base_it(it) {}

				//---------------COPY CONSTRUCTOR---------------//
				ReverseIterator(const IteratorType &rhs) : _base_it(rhs.base()) {}

				ReverseIterator(const ReverseIterator &rhs) : _base_it(rhs.base()) {}

				template <typename I>
				ReverseIterator(const ReverseIterator<I> &rhs) : _base_it(rhs.base()) {}

				//---------------DESTRUCTOR---------------//
				virtual ~ReverseIterator() {}

				//---------------OVERLOAD OPERATOR---------------//
				ReverseIterator &operator=(const ReverseIterator &rhs) {
					_base_it = rhs.base;
					return (*this);
				}

				//---------------BASE ITERATOR---------------//
				iterator_type base() const {
					return _base_it;
				}

				//---------------DEREFERENCE ITERATOR---------------//
				reference operator*() const {
					return (*_base_it);
				}

				//---------------ADDITION OPERATOR---------------//
				ReverseIterator operator+(difference_type n) const {
					return (ReverseIterator(_base_it - n));
				}

				//---------------PREFIX INCREMENT OPERATOR---------------//
				ReverseIterator &operator++() {
					_base_it--;
					return (*this);
				}

				//---------------POSTFIX INCREMENT OPERATOR---------------//
				ReverseIterator operator++(int) {
					ReverseIterator tmp(*this);
					--(*this);
					return tmp;
				}

				//---------------ADVANCE INCREMENT ITERATOR---------------//
				ReverseIterator &operator+=(difference_type n) {
					*this = *this + n;
					return (*this);
				}

				//---------------SUBTRACTION OPERATOR---------------//
				ReverseIterator operator-(difference_type n) const {
					return (ReverseIterator(_base_it + n));
				}

				//---------------PREFIX DECREMENT ITERATOR---------------//
				ReverseIterator &operator--() {
					_base_it++;
					return (*this);
				}

				//---------------POSTFIX DECREMENT ITERATOR---------------//
				ReverseIterator operator--(int) {
					ReverseIterator tmp(*this);
					++(*this);
					return tmp;
				}

				//---------------ADVANCE DECREMENT ITERATOR---------------//
				ReverseIterator &operator-=(difference_type n) {
					*this = *this - n;
					return (*this);
				}

				//---------------DEREFERENCE ITERATOR---------------//
				pointer operator->() const {
					return &(operator*());
				}

				//---------------DEREFERENCE ITERATOR WITH OFFSET---------------//
				reference operator[] (difference_type n) const {
					return (base()[-n-1]);
				}

				//---------------COMPARES UNDERLYING ITERATORS---------------//
				bool operator==(const ReverseIterator &rhs) const {
					return ( _base_it == rhs._base_it);
				}

				bool operator!=(const ReverseIterator &rhs) const {
					return (!(_base_it == rhs._base_it));
				}
	};
};


#endif