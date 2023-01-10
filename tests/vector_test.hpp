#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP


#include "test.hpp"
#include "../containers/vector.hpp"

class VectorTest : Test {
	private :
			static std::vector<int> test_assign_std() {
				std::vector<int> vec;
				std::vector<int> result;
				vec.assign(9000 * 100, 1);
				
			}
}











#endif