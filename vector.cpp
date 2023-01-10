// #include "vector.hpp"

// Vector::Vector() : _size(0), _capacity(5), _Array(new int[5]) {

// 	std::cout << "Constructor was called" << std::endl;
// }


// Vector::~Vector() {
// 	delete[] _Array;
// 	std::cout << "Destructor was called" << std::endl;
// }


// void Vector::pushToBack(int val) {
// 	_Array[_size] = val;
// 	++_size;
// }

// void Vector::popBack() {
// 	--_size;
// }

// bool Vector::isEmpty() const {
// 	return _size == 0;
// }

// int Vector::Capacity() const {
// 	return _size;
// }

// int Vector::Size() const {
// 	return _size;
// }

// Vector::Vector(const Vector &rhs) 
// 		: _size(rhs._size), 
// 		_capacity(rhs._capacity),
// 		_Array(new int[5]) 
// {
// 	for(int i = 0; i < rhs.Size(); i++) {
// 		_Array[i] = rhs._Array[i];
// 	}

// }

// Vector::Vector(int elem, int init_val = 0) 
// 		:	_size(elem),
// 			_capacity(elem + 5),
// 			_Array(new int[5])	 
// {
// 	for (int i = 0; i < _size; ++i) {
// 		_Array[i] = init_val;
// 	}
// }

// bool Vector::operator==(const Vector &rhs) const {
// 	if (Size() != rhs.Size()) {
// 		return false;
// 	}
// 	for (int i = 0; i < Size(); ++i) {
// 		if (_Array[i] != rhs._Array[i]) {
// 			return false;
// 		}
		
// 	}
// 	return true;
// }

// bool Vector::operator!=(const Vector &rhs) const {
// 	return !(*this == rhs);
// }

// std::ostream& operator <<(std::ostream &os, const Vector &rhs) {

// 	for (int i = 0; i < rhs._size; ++i) {
// 		os << rhs._Array[i] << " ";
// 	}
// 	os << " || ";
// 	for (int i = rhs._size; i < rhs._capacity; ++i) {
// 		os << rhs._Array[i] << " ";
// 	}
// 	os << std::endl;
// 	return os;
// }

// // Vector::Vector(const std::initializer_list<int>&  list)
// 		// :	_size(0),
// 			// _capacity(list.size() + 5),
// 			// _Array(new int[_capacity])
// // {
// 	// for (int i = 0; i < list.size(); i++) {
// 		// pushToBack(i);
// 	// }
// 	// 
// // }