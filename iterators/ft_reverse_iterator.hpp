#ifndef 	REVERSE_ITERATOR_HPP
# define	REVERSE_ITERATOR_HPP
#include "ft_iterator_traits.hpp"

namespace ft {
	template<typename IteratorType>
	class ReverseIterator {
		public :
				//set of type aliases for RI class template.
				//RI is a wrapper around an iterator that iterates over a range in reverse order.
				typedef 			IteratorType											iterator_type;		//type of iterator being wrapped by RI
				typedef typename	ft::random_access_iterator_tag							iterator_category;	//RI can be used with RAI
				typedef typename	ft::iterator_traits<iterator_type>::value_type			value_type;			//type of value being pointed to by iterator
				typedef typename	ft::iterator_traits<iterator_type>::difference_type		difference_type;	//represenet diff between 2 iterators.
				typedef typename	ft::iterator_traits<iterator_type>::pointer				pointer;			//pointer to the value type
				typedef typename	ft::iterator_traits<iterator_type>::reference			reference;			//reference to the value type

		private :
				iterator_type	_base_it;

		public :
				//---------------DEFAULT CONSTRUCTOR---------------//
				ReverseIterator( void ) : _base_it(NULL) {}

				//---------------INITIALIZATION CONSTRUCTOR---------------//
				ReverseIterator (const IteratorType &rhs) : _base_it(rhs.base()) {}

				ReverseIterator(const ReverseIterator &rhs) : _base_it(rhs.base()) {}

				template <typename Iter>
				ReverseIterator(const ReverseIterator<Iter> &rhs) : _base_it(rhs.base()) {}

				//---------------DESTRUCTOR---------------//
				~ReverseIterator() {}

				//---------------OVERLOAD OPERATOR---------------//
				ReverseIterator &operator=(const ReverseIterator &rhs) {
					if (this == &rhs)
						return *this;
					_base_it = rhs.base();
					return (*this);
				}

				//---------------BASE ITERATOR---------------//
				iterator_type base() const {
					return (_base_it);
				}

				//---------------SUBTRACTION OPERATOR---------------//
				ReverseIterator operator-(difference_type n) const {
					return (ReverseIterator(_base_it + n));
				}

				//---------------ADVANCE DECREMENT ITERATOR---------------//
				ReverseIterator operator-=(difference_type n) {
					_base_it += n;
					return (*this);
				}

				//---------------ADDITION OPERATOR---------------//
				ReverseIterator operator+(difference_type n) const {
					return (ReverseIterator(_base_it - n));
				}

				//---------------ADVANCE INCREMENT ITERATOR---------------//
				ReverseIterator operator+=(difference_type n) {
					_base_it -= n;
					return (*this);
				}

				//---------------PREFIX INCREMENT OPERATOR---------------//
				ReverseIterator &operator++() {
					--_base_it;
					return (*this);
				}

				//---------------POSTFIX INCREMENT OPERATOR---------------//
				ReverseIterator operator++(int) {
					ReverseIterator tmp(*this);
					--_base_it;
					return tmp;
				}

				//---------------PREFIX DECREMENT ITERATOR---------------//
				ReverseIterator &operator--() {
					++_base_it;
					return (*this);
				}

				//---------------POSTFIX DECREMENT ITERATOR---------------//
				ReverseIterator operator--(int) {
					ReverseIterator tmp(*this);
					++_base_it;
					return tmp;
				}

				//---------------DEREFERENCE ITERATOR---------------//
				reference operator*() const {
					return *iterator_type(_base_it - 1);
				}

				//---------------DEREFERENCE ITERATOR---------------//
				pointer operator->() const {
					return &(operator*());
					
				}

				//---------------DEREFERENCE ITERATOR WITH OFFSET---------------//
				reference operator[] (const difference_type& n) const {
					return *(*this + n);
				}



	};

	template <typename Iter1, typename Iter2>
	bool operator==(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter2> &rhs) {
		return lhs.base() == rhs.base();
	}
	template <typename Iter1>
	bool operator==(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter1> &rhs) {
		return lhs.base() == rhs.base();
	}
	template <typename Iter1, typename Iter2>
	bool operator!=(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter2> &rhs) {
		return lhs.base() != rhs.base();
	}
	template <typename Iter1>
	bool operator!=(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter1> &rhs) {
		return lhs.base() != rhs.base();
	}
	template <typename Iter1, typename Iter2>
	bool operator<(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter2> &rhs) {
		return lhs.base() > rhs.base();
	}
	template <typename Iter1>
	bool operator<(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter1> &rhs) {
		return lhs.base() > rhs.base();
	}
	template <typename Iter1, typename Iter2>
	bool operator<=(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter2> &rhs) {
		return lhs.base() >= rhs.base();
	}
	template <typename Iter1>
	bool operator<=(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter1> &rhs) {
		return lhs.base() >= rhs.base();
	}
	template <typename Iter1, typename Iter2>
	bool operator>(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter2> &rhs) {
		return lhs.base() < rhs.base();
	}
	template <typename Iter1>
	bool operator>(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter1> &rhs) {
		return lhs.base() < rhs.base();
	}
	template <typename Iter1, typename Iter2>
	bool operator>=(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter2> &rhs) {
		return lhs.base() <= rhs.base();
	}
	template <typename Iter1>
	bool operator>=(const ReverseIterator<Iter1> &lhs, const ReverseIterator<Iter1> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template <typename Iter>
	ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type const n, ReverseIterator<Iter> const &rhs) {
		return ReverseIterator<Iter>(rhs.base() - n);
	}

	template <typename Iter1, typename Iter2>
	typename ReverseIterator<Iter1>::difference_type operator-(ReverseIterator<Iter1> const &lhs, ReverseIterator<Iter2> const &rhs) {
		return rhs.base() - lhs.base();
	}
};


#endif