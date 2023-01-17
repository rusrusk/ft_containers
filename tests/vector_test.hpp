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
				ft::vector<int> vec;
				vec.assign(3, 3);
				ft::vector<int> tmp(5, 42);
				ft::vector<int> tmp2(tmp.begin(), tmp.end());
				result.push_back(tmp2.size());
				result.push_back(tmp2.capacity());
				for (size_t i = 0; i < tmp.size(); i++) {
					result.push_back(tmp2[i]);
				}
				return result;
			}

			static std::vector<int> test_insert_single_element_std() {
				std::vector<int> vector0;
				vector0.assign(5, 20);
				std::vector<int> vector1;
				std::vector<int> result;
				vector1.insert(vector1.begin(), 1);
				vector1.insert(vector1.begin() + 1, 2);
				vector1.insert(vector1.begin() + 2, 3);
				vector1.insert(vector1.begin() + 3, 5, 4);
				vector1.insert(vector1.begin() + 8, 5, 5);
				vector1.insert(vector1.begin() + 13, vector0.begin(), vector0.end());
				for (size_t i = 0; i < vector1.size(); i++)
					result.push_back(vector1[i]);
				return result;
			}

			static std::vector<int> test_insert_single_element_ft() {
				std::vector<int> vector;
				std::vector<int> result;

				return result;
			}

	public :
			void launch_all_tests() {
				// launch_test(test_constructor_iterator_ft, test_constructor_iterator_std, "assign()");
				launch_test(test_insert_single_element_std, test_insert_single_element_std, "insert()");
			}
};










#endif