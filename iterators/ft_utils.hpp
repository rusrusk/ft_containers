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

//-----------------ENABLE-IF-----------------//
	template<bool B, class T = void >
	struct enable_if
	{

	};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

//-----------------FT-PAIR MEMBER FUNCS-----------------//
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second()
		{

		}

		template <class U, class V>
		pair(const pair<U, V>&pr) : first(pr.first), second(pr.second)
		{

		}

		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{

		}
		pair &operator=(const pair &rhs)
		{
			first = rhs.first;
			second = rhs.second;
			return (*this);
		}
	};

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	};



	//------------FT::PAIR NON-MEMBER FUNCTIONS------------------------------------
	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		
		if (lhs.first < rhs.first)
			return (true);
		else if (lhs.first > rhs.first)
			return (false);
		else if (lhs.second < rhs.second)
			return (true);
		else
			return (false);
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {

		return (!(lhs < rhs));
	}

//########## START NEW_NON_CONST ##############

	template< class T1, class T2 >
	bool operator==(  ft::pair<T1,T2>& lhs,  ft::pair<T1,T2>& rhs ) {
		
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template< class T1, class T2 >
	bool operator!=(  ft::pair<T1,T2>& lhs,  ft::pair<T1,T2>& rhs ) {
		
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator<(  ft::pair<T1,T2>& lhs,  ft::pair<T1,T2>& rhs ) {
		
		if (lhs.first < rhs.first)
			return (true);
		else if (lhs.first > rhs.first)
			return (false);
		else if (lhs.second < rhs.second)
			return (true);
		else
			return (false);
	}

	template< class T1, class T2 >
	bool operator<=(  ft::pair<T1,T2>& lhs,  ft::pair<T1,T2>& rhs ) {
		
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator>(  ft::pair<T1,T2>& lhs,  ft::pair<T1,T2>& rhs ) {
		
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=(  ft::pair<T1,T2>& lhs,  ft::pair<T1,T2>& rhs ) {

		return (!(lhs < rhs));
	}

		
//------------FT_BINARY_FUNCTION--------------------------------------


	template< typename Arg1, typename Arg2, typename Result >
	struct binary_function
	{
		typedef Arg1				first_argument_type;
		typedef Arg2				second_argument_type;
		typedef Result				result_type;
	};


//------------INTEGRAL_CONSTANT--------------------------------------


	template<typename T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() { return v; }
	};

	template<typename T, T v>
	const T integral_constant<T, v>::value;

	typedef integral_constant<bool, false> false_type;
	typedef integral_constant<bool, true> true_type;

	
//------------IS_INTEGRAL--------------------------------------


	template<typename T> struct is_integral : public false_type {};
	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	// template<> struct is_integral<char16_t> : public true_type {}; //c++11
	// template<> struct is_integral<char32_t> : public true_type {}; //c++11
	template<> struct is_integral<short> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<long> : public true_type {};
	// template<> struct is_integral<long long> : public true_type {}; //c++11

	template<> struct is_integral<unsigned short> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long> : public true_type {};

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

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

}





#endif