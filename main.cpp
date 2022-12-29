#include <iostream>
#include <vector>
#include "vector.hpp"

template <typename T>

class Vector {
	T* _begin;
	T* _end;
	T* _buffer_end;

	size_t size() const noexcept {
		return _end - _begin;
	}
	size_t capacity() const noexcept {
		return _buffer_end - _begin;
	}

	Vector(size_t count, const T& value = T()) {
		_begin(  )
	}


	 
}




int main () {

}










// int g(int *p) {
// 	if (!*p) {
// 		throw std::runtime_error("Fail");
// 	}
// 	return 3;
// }

// struct Something {
// 	int *p;
// 	Something(int *p): p(p) {}
// 	~Something() {delete p; }
// };

// int f(int x) {
// 	Something p(new int(x));
// 	int res = g(p.p);
// 	return res;
// }


// int main () {

// 	int res = f(5);
// 	std::cout << res << std::endl;
// }

