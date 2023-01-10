#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP


#include "test.hpp"
#include "../containers/vector.hpp"

class VectorTest : Test {
	private :

			static std::vector<int> test_constructor_iterator_std() {
				std::vector<int> vec;
				std::vector<int> result;
				vec.assign(3, 3);
				std::vector<int> tmp(5, 42);
				std::vector<int> tmp2(tmp.begin(), tmp.end());
				result.push_back(tmp2.size());
				result.push_back(tmp2.capacity());
				for (size_t i = 0; i < tmp.size(); i++) {
					result.push_back(tmp2[i]);
				}
				return result;
			}

			static std::vector<int> test_constructor_iterator_ft() {
				std::vector<int> result;
				ft::Vector<int> vec;
				vec.assign(3, 3);
				ft::Vector<int> tmp(5, 42);
				ft::Vector<int> tmp2(tmp.begin(), tmp.end());
				result.push_back(tmp2.size());
				result.push_back(tmp2.capacity());
				for (size_t i = 0; i < tmp.size(); i++) {
					result.push_back(tmp2[i]);
				}
				return result;
			}

	public :
			void launch_all_tests() {
				launch_test(test_constructor_iterator_ft, test_constructor_iterator_std, "assign()");
			}
};










#endif