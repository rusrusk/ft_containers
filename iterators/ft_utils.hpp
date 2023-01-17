#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

#include "ft_iterator_traits.hpp"

namespace ft
{

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<bool B, class T = void >
	struct enable_if
	{

	};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	// template <typename T, T v>
	// struct integral_constant {
	// 	static const T value = v;
	// 	typedef T value_type;
	// 	typedef integral_constant<T, v> type;
	// 	operator T() {
	// 		return v;
	// 	}
	// };

	// template <typename T, T v>
	// const T integral_constant<T, v>::value;

	// typedef integral_constant<bool, false> false_type;
	// typedef integral_constant<bool, true> true_type;

	// template <typename T> struct is_integral :			public false_type {};
	// template <> struct is_integral<bool> :				public true_type {};
	// template <> struct is_integral<char> :				public true_type {};
	// template <> struct is_integral<wchar_t> :			public true_type {};
	// template <> struct is_integral <signed char> :		public true_type {};
	// template <> struct is_integral <short> :			public true_type {};
	// template <> struct is_integral <int> :				public true_type {};
	// template <> struct is_integral <long> :				public true_type {};
	// template <> struct is_integral <unsigned char> :	public true_type {};
	// template <> struct is_integral <unsigned short> :	public true_type {};
	// template <> struct is_integral <unsigned int> :		public true_type {};
	// template <> struct is_integral <unsigned long> :	public true_type {};

	// template <typename, typename> struct are_same : public false_type {};
	// template <typename T> struct are_same<T, T> : public true_type {};

	template <class T>
	void swap (T &a, T&b) {
		T c(a);
		a = b;
		b = c;
	}
}





#endif