#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP


#include "test.hpp"
#include "../containers/vector.hpp"

class VectorTest : Test {
	private :

			//######################################################################
			//######################## CONSTRUCTORS ################################
			//######################################################################
			static std::vector<int> test_constructor_std()
			{
				int limit = LIMIT;
				std::vector<int> result;
				std::vector<int> vec;
				std::vector<int> tmp0(vec);
				std::vector<int> tmp1(10 * limit, 4), tmp2(10 * limit, 5);
				tmp1 = tmp2;
				std::vector<int> tmp3(tmp1);
				std::vector<int> tmp4(tmp1.begin(), tmp1.end());
				result.push_back(tmp4.size());
				result.push_back(tmp4.capacity());
				result.push_back(tmp1[2]);
				result.push_back(tmp3[2]);
				result.push_back(tmp4[2]);
				try {
					std::vector<int> tmp5(-1, -1);
				}
				catch (std::exception &err)
				{
					result.push_back(1);
				}
				return result;
			}

			static std::vector<int> test_constructor_ft()
			{
				int limit = LIMIT;
				std::vector<int> result;
				ft::vector<int> vec;
				ft::vector<int> tmp0(vec);
				ft::vector<int> tmp1(10 * limit, 4), tmp2(10 * limit, 5);
				tmp1 = tmp2;
				ft::vector<int> tmp3(tmp1);
				ft::vector<int> tmp4(tmp1.begin(), tmp1.end());
				result.push_back(tmp4.size());
				result.push_back(tmp4.capacity());
				result.push_back(tmp1[2]);
				result.push_back(tmp3[2]);
				result.push_back(tmp4[2]);
				try {
					std::vector<int> tmp5(-1, -1);
				}
				catch (std::exception &err)
				{
					result.push_back(1);
				}
				return result;
			}

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

			//######################################################################
			//######################## ITERATORS ###################################
			//######################################################################
			static std::vector<int> test_begin_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				vec.assign(1000, 1);
				result.push_back(*vec.begin());
				result.push_back(*++vec.begin());
				return result;
			}

			static std::vector<int> test_begin_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				vec.assign(1000, 1);
				result.push_back(*vec.begin());
				result.push_back(*++vec.begin());
				return result;
			}

			static std::vector<int> test_end_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				for (size_t i = 0; i < 10; ++i)
					vec.push_back(i);
				result.push_back(*(vec.end() - 1));
				result.push_back(*(vec.end() - 2));
				return result;
			}

			static std::vector<int> test_end_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				for (size_t i = 0; i < 10; ++i)
					vec.push_back(i);
				result.push_back(*(vec.end() - 1));
				result.push_back(*(vec.end() - 2));
				return result;
			}

			static std::vector<int> test_rbegin_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				for (size_t i = 0; i < 10; ++i)
					vec.push_back(i);
				result.push_back(vec[*vec.rbegin()]);
				vec.pop_back();
				result.push_back(vec[*vec.rbegin()]);
				return result;
			}

			static std::vector<int> test_rbegin_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				for (size_t i = 0; i < 10; ++i)
					vec.push_back(i);
				result.push_back(vec[*vec.rbegin()]);
				vec.pop_back();
				result.push_back(vec[*vec.rbegin()]);
				return result;
			}

			// static std::vector<int> test_rend_std()
			// {
			// 	std::vector<int> result;
			// 	std::vector<int> vec;
			// 	for (int i = 0; i < 10; ++i)
			// 		vec.push_back(i);
			// 	result.push_back(vec[*vec.rend()]);
			// 	return result;
			// }

			// static std::vector<int> test_rend_ft()
			// {
			// 	std::vector<int> result;
			// 	ft::vector<int> vec;
			// 	for (int i = 1; i < 10; ++i)
			// 		vec.push_back(i);
			// 	result.push_back(vec[*vec.rend()]);
			// 	return result;
			// }

			//######################################################################
			//######################## CAPACITY ####################################
			//######################################################################
			static std::vector<int> test_size_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				result.push_back(vec.size());
				for (int i = 0; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.size());
				vec.clear();
				result.push_back(vec.size());
				return result;
			}

			static std::vector<int> test_size_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				result.push_back(vec.size());
				for (int i = 0; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.size());
				vec.clear();
				result.push_back(vec.size());
				return result;
			}

			static std::vector<int> test_max_size_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				vec.assign(1, 42);
				result.push_back(vec.max_size());
				return result;
			}

			static std::vector<int> test_max_size_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				vec.assign(1, 42);
				result.push_back(vec.max_size());
				return result;
			}

			static std::vector<int> test_resize_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				vec.assign(42, 42);
				result.push_back(vec.size());
				vec.resize(1000);
				result.push_back(vec.size());
				vec.resize(42);
				result.push_back(vec.size());
				return result;
			}

			static std::vector<int> test_resize_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				vec.assign(42, 42);
				result.push_back(vec.size());
				vec.resize(1000);
				result.push_back(vec.size());
				vec.resize(42);
				result.push_back(vec.size());
				return result;
			}

			static std::vector<int> test_capacity_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				result.push_back(vec.capacity());
				vec.reserve(999);
				result.push_back(vec.capacity());
				vec.reserve(999);
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_capacity_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				result.push_back(vec.capacity());
				vec.reserve(999);
				result.push_back(vec.capacity());
				vec.reserve(999);
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_empty_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				result.push_back(vec.empty());
				vec.assign(42,42);
				result.push_back(vec.empty());
				return result;
			}

			static std::vector<int> test_empty_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				result.push_back(vec.empty());
				vec.assign(42,42);
				result.push_back(vec.empty());
				return result;
			}

			static std::vector<int> test_reserve_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				result.push_back(vec.capacity());
				vec.reserve(42);
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_reserve_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				result.push_back(vec.capacity());
				vec.reserve(42);
				result.push_back(vec.capacity());
				return result;
			}

			//######################################################################
			//######################## ELEMENT ACCESS ##############################
			//######################################################################
			static std::vector<int> test_operator_square_brackets_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				for (int i = 0; i < 42; ++i)
					vec.push_back(i);
				result.push_back(vec[0]);
				result.push_back(vec[42 -1]);
				result.push_back(vec[30]);
				return result;
			}

			static std::vector<int> test_operator_square_brackets_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				for (int i = 0; i < 42; ++i)
					vec.push_back(i);
				result.push_back(vec[0]);
				result.push_back(vec[42 -1]);
				result.push_back(vec[30]);
				return result;
			}

			static std::vector<int> test_at_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				vec.assign(9900 * limit, 1);
				result.push_back(vec.at(354 * limit));
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_at_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				vec.assign(9900 * limit, 1);
				result.push_back(vec.at(354 * limit));
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_front_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				for (int i = 1; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.front());
				for (int i = 1; i < limit * 2; ++i)
					vec.push_back(i);
				result.push_back(vec.front());
				return result;
			}

			static std::vector<int> test_front_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				for (int i = 1; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.front());
				for (int i = 1; i < limit * 2; ++i)
					vec.push_back(i);
				result.push_back(vec.front());
				return result;
			}

			static std::vector<int> test_back_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				for (int i = 0; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.back());
				return result;
			}

			static std::vector<int> test_back_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				for(int i = 0; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.back());
				return result;
			}

			static std::vector<int> test_data_std()
			{
				std::vector<int> result;
				std::vector<int> vec(42);
				int *p = vec.data();
				*p = 10;
				++p;
				*p = 20;
				p[2] = 100;
				for (unsigned i = 0; i < vec.size(); ++i)
					result.push_back(vec[i]);
				return result;
			}

			static std::vector<int> test_data_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec(42);
				int *p = vec.data();
				*p = 10;
				++p;
				*p = 20;
				p[2] = 100;
				for (unsigned i = 0; i < vec.size(); ++i)
					result.push_back(vec[i]);
				return result;
			}

			//######################################################################
			//######################## MODIFIERS ###################################
			//######################################################################
			static std::vector<int> test_assign_std()
			{
				int limit = LIMIT;
				std::vector<int> result;
				std::vector<int> vec;
				std::vector<int> tmp1, tmp2;
				vec.assign(3, 3);
				tmp1.assign(200 * limit, 1);
				tmp2.assign(4 * limit, 1);
				vec.assign(tmp1.begin(), tmp1.end());
				result.push_back(vec[1]);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				vec.assign(tmp2.begin(), tmp2.end());
				result.push_back(vec[444]);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_assign_ft()
			{
				int limit = LIMIT;
				std::vector<int> result;
				ft::vector<int> vec;
				std::vector<int> tmp1, tmp2;
				vec.assign(3, 3);
				tmp1.assign(200 * limit, 1);
				tmp2.assign(4 * limit, 1);
				vec.assign(tmp1.begin(), tmp1.end());
				result.push_back(vec[1]);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				vec.assign(tmp2.begin(), tmp2.end());
				result.push_back(vec[444]);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_push_back_std()
			{
				int limit = LIMIT;
				std::vector<int> result;
				std::vector<int> vec;
				for (int i = 0; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.push_back(vec.back());
				return result;
			}

			static std::vector<int> test_push_back_ft()
			{
				int limit = LIMIT;
				std::vector<int> result;
				ft::vector<int> vec;
				for (int i = 0; i < limit; ++i)
					vec.push_back(i);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.push_back(vec.back());
				return result;
			}

			static std::vector<int> test_pop_back_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				for (int i = 0; i < 10; ++i)
					vec.push_back(i);
				result.push_back(vec[vec.back()]);
				vec.pop_back();
				result.push_back(vec[vec.back()]);
				return result;
			}

			static std::vector<int> test_pop_back_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				for (int i = 0; i < 10; ++i)
					vec.push_back(i);
				result.push_back(vec[vec.back()]);
				vec.pop_back();
				result.push_back(vec[vec.back()]);
				return result;
			}

			static std::vector<int> test_insert_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				vec.assign(1000, 1);
				vec.insert(vec.end() - 50, 420 * limit, 2);
				result.push_back(vec[1222]);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_insert_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				vec.assign(1000, 1);
				vec.insert(vec.end() - 50, 420 * limit, 2);
				result.push_back(vec[1222]);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_insert_single_element_std()
			{
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
				ft::vector<int> vector0;
				vector0.assign(5, 20);
				ft::vector<int> vector1;
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

			static std::vector<int> test_erase_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				vec.assign(420 * limit, 42);
				result.push_back(*(vec.erase(vec.begin() + 8 * limit, vec.end() - 42 * limit)));
				result.push_back(*(vec.begin() + 42 * limit));
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.push_back(*(vec.erase(vec.begin() + 8 * limit)));
				result.push_back(*(vec.begin() + 42 * limit));
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_erase_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				vec.assign(420 * limit, 42);
				result.push_back(*(vec.erase(vec.begin() + 8 * limit, vec.end() - 42 * limit)));
				result.push_back(*(vec.begin() + 42 * limit));
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.push_back(*(vec.erase(vec.begin() + 8 * limit)));
				result.push_back(*(vec.begin() + 42 * limit));
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_swap_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				result.push_back(vec1.size());
				result.push_back(vec1.capacity());
				result.push_back(vec2.size());
				result.push_back(vec2.capacity());
				vec1.assign(100, 42);
				result.push_back(vec1.size());
				result.push_back(vec1.capacity());
				result.push_back(vec2.size());
				result.push_back(vec2.capacity());
				vec2.swap(vec1);
				result.push_back(vec1.size());
				result.push_back(vec1.capacity());
				result.push_back(vec2.size());
				result.push_back(vec2.capacity());
				return result;
			}

			static std::vector<int> test_swap_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				result.push_back(vec1.size());
				result.push_back(vec1.capacity());
				result.push_back(vec2.size());
				result.push_back(vec2.capacity());
				vec1.assign(100, 42);
				result.push_back(vec1.size());
				result.push_back(vec1.capacity());
				result.push_back(vec2.size());
				result.push_back(vec2.capacity());
				vec2.swap(vec1);
				result.push_back(vec1.size());
				result.push_back(vec1.capacity());
				result.push_back(vec2.size());
				result.push_back(vec2.capacity());
				return result;
			}
			
			static std::vector<int> test_clear_std()
			{
				std::vector<int> result;
				std::vector<int> vec;
				int limit = LIMIT;
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.assign(limit, 42);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.clear();
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			static std::vector<int> test_clear_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec;
				int limit = LIMIT;
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.assign(limit, 42);
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				result.clear();
				result.push_back(vec.size());
				result.push_back(vec.capacity());
				return result;
			}

			//######################################################################
			//######################## NON-MEMBER METHOD OVERLOADS #################
			//######################################################################
			static std::vector<int> test_operator_equal_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 42; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec1 == vec2);
				std::vector<int> vec3(vec1);
				result.push_back(vec1 == vec3);
				std::vector<int> vec4(vec1);
				result.push_back(vec1 == vec4);
				std::vector<int> vec5(vec1);
				result.push_back(vec4 == vec5);
				return result;
			}

			static std::vector<int> test_operator_equal_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 42; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec1 == vec2);
				ft::vector<int> vec3(vec1);
				result.push_back(vec1 == vec3);
				ft::vector<int> vec4(vec1);
				result.push_back(vec1 == vec4);
				ft::vector<int> vec5(vec1);
				result.push_back(vec4 == vec5);
				return result;
			}

			static std::vector<int> test_operator_not_equal_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 42; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec1 != vec2);
				std::vector<int> vec3(vec1);
				result.push_back(vec1 != vec3);
				std::vector<int> vec4(vec1);
				result.push_back(vec1 != vec4);
				std::vector<int> vec5(vec1);
				result.push_back(vec4 != vec5);
				return result;
			}

			static std::vector<int> test_operator_not_equal_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 42; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec1 != vec2);
				ft::vector<int> vec3(vec1);
				result.push_back(vec1 != vec3);
				ft::vector<int> vec4(vec1);
				result.push_back(vec1 != vec4);
				ft::vector<int> vec5(vec1);
				result.push_back(vec4 != vec5);
				return result;
			}

			static std::vector<int> test_operator_less_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 < vec1);
				std::vector<int> vec3(vec1);
				result.push_back(vec1 < vec3);
				std::vector<int> vec4(vec1);
				std::vector<int> vec5(vec1);
				result.push_back(vec4 < vec5);
				return result;
			}

			static std::vector<int> test_operator_less_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 < vec1);
				ft::vector<int> vec3(vec1);
				result.push_back(vec1 < vec3);
				ft::vector<int> vec4(vec1);
				ft::vector<int> vec5(vec1);
				result.push_back(vec4 < vec5);
				return result;
			}

			static std::vector<int> test_operator_less_or_equal_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 <= vec1);
				std::vector<int> vec3(vec1);
				result.push_back(vec1 <= vec3);
				std::vector<int> vec4(vec1);
				std::vector<int> vec5(vec1);
				result.push_back(vec4 <= vec5);
				return result;
			}

			static std::vector<int> test_operator_less_or_equal_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 <= vec1);
				ft::vector<int> vec3(vec1);
				result.push_back(vec1 <= vec3);
				ft::vector<int> vec4(vec1);
				ft::vector<int> vec5(vec1);
				result.push_back(vec4 <= vec5);
				return result;
			}

			static std::vector<int> test_operator_more_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 > vec1);
				std::vector<int> vec3(vec1);
				result.push_back(vec1 > vec3);
				std::vector<int> vec4(vec1);
				std::vector<int> vec5(vec1);
				result.push_back(vec4 > vec5);
				return result;
			}

			static std::vector<int> test_operator_more_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 > vec1);
				ft::vector<int> vec3(vec1);
				result.push_back(vec1 > vec3);
				ft::vector<int> vec4(vec1);
				ft::vector<int> vec5(vec1);
				result.push_back(vec4 > vec5);
				return result;
			}

			static std::vector<int> test_operator_more_or_equal_std()
			{
				std::vector<int> result;
				std::vector<int> vec1;
				std::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 >= vec1);
				std::vector<int> vec3(vec1);
				result.push_back(vec1 >= vec3);
				std::vector<int> vec4(vec1);
				std::vector<int> vec5(vec1);
				result.push_back(vec4 >= vec5);
				return result;
			}

			static std::vector<int> test_operator_more_or_equal_ft()
			{
				std::vector<int> result;
				ft::vector<int> vec1;
				ft::vector<int> vec2;
				for (int i = 0; i < 42; ++i)
					vec1.push_back(i);
				for (int i = 0; i < 24; ++i)
					vec2.push_back(i * -1);
				result.push_back(vec2 >= vec1);
				ft::vector<int> vec3(vec1);
				result.push_back(vec1 >= vec3);
				ft::vector<int> vec4(vec1);
				ft::vector<int> vec5(vec1);
				result.push_back(vec4 >= vec5);
				return result;
			}



	public :
			void launch_all_tests() {
				launch_test(test_constructor_ft, test_constructor_std, "CONSTRUCTOR()");
				launch_test(test_constructor_iterator_ft, test_constructor_iterator_std, "CONSTRUCTOR_ITR()");
				launch_test(test_begin_ft, test_begin_std, "BEGIN()");
				launch_test(test_end_ft, test_end_std, "END()");
				launch_test(test_rbegin_ft, test_rbegin_std, "RBEGIN()");
				// launch_test(test_rend_ft, test_rend_std, "REND()");
				launch_test(test_size_ft, test_size_std, "SIZE()");
				launch_test(test_max_size_ft, test_max_size_std, "MAX_SIZE()");
				launch_test(test_resize_ft, test_resize_std, "RESIZE()");
				launch_test(test_capacity_ft, test_capacity_std, "CAPACITY()");
				launch_test(test_empty_ft, test_empty_std, "EMPTY()");
				launch_test(test_reserve_ft, test_reserve_std, "RESERVE()");
				launch_test(test_reserve_ft, test_reserve_std, "RESERVE()");
				launch_test(test_operator_square_brackets_ft, test_operator_square_brackets_std, "OPERATOR[]()");
				launch_test(test_operator_square_brackets_ft, test_operator_square_brackets_std, "OPERATOR[]()");
				launch_test(test_front_ft, test_front_std, "FRONT()");
				launch_test(test_back_ft, test_back_std, "BACK()");
				launch_test(test_data_ft, test_data_std, "DATA()");
				launch_test(test_assign_ft, test_assign_std, "ASSIGN()");
				launch_test(test_push_back_ft, test_push_back_std, "PUSH_BACK()");
				launch_test(test_pop_back_ft, test_pop_back_std, "POP_BACK()");
				launch_test(test_insert_ft, test_insert_std, "INSERT()");
				launch_test(test_insert_single_element_ft, test_insert_single_element_std, "INSERT_ELEM()");
				launch_test(test_erase_ft, test_erase_std, "ERASE()");
				launch_test(test_swap_ft, test_swap_std, "SWAP()");
				launch_test(test_clear_ft, test_clear_std, "CLEAR()");
				launch_test(test_operator_equal_ft, test_operator_equal_std, "OPERATOR==()");
				launch_test(test_operator_not_equal_ft, test_operator_not_equal_std, "OPERATOR!=()");
				launch_test(test_operator_less_ft, test_operator_less_std, "OPERATOR<()");
				launch_test(test_operator_less_or_equal_ft, test_operator_less_or_equal_std, "OPERATOR<=()");
				launch_test(test_operator_more_ft, test_operator_more_std, "OPERATOR>()");
				launch_test(test_operator_more_or_equal_ft, test_operator_more_or_equal_std, "OPERATOR>=()");
			}

			void launch_all_values_tests()
			{
				launch_values_test(test_constructor_ft, test_constructor_std, "CONSTRUCTOR()");
				launch_values_test(test_constructor_iterator_ft, test_constructor_iterator_std, "CONSTRUCTOR_ITR()");
				launch_values_test(test_begin_ft, test_begin_std, "BEGIN()");
				launch_values_test(test_end_ft, test_end_std, "END()");
				launch_values_test(test_rbegin_ft, test_rbegin_std, "RBEGIN()");
				launch_values_test(test_rbegin_ft, test_rbegin_std, "REND()");
				launch_values_test(test_size_ft, test_size_std, "SIZE()");
				launch_values_test(test_max_size_ft, test_max_size_std, "MAX_SIZE()");
				launch_values_test(test_resize_ft, test_resize_std, "RESIZE()");
				launch_values_test(test_capacity_ft, test_capacity_std, "CAPACITY()");
				launch_values_test(test_reserve_ft, test_reserve_std, "RESERVE()");
				launch_values_test(test_front_ft, test_front_std, "FRONT()");
				launch_values_test(test_back_ft, test_back_std, "BACK()");
				launch_values_test(test_data_ft, test_data_std, "DATA()");
				launch_values_test(test_assign_ft, test_assign_std, "ASSIGN()");
				launch_values_test(test_push_back_ft, test_push_back_std, "PUSH_BACK()");
				launch_values_test(test_pop_back_ft, test_pop_back_std, "POP_BACK()");
				launch_values_test(test_insert_ft, test_insert_std, "INSERT()");
				launch_values_test(test_insert_single_element_ft, test_insert_single_element_std, "INSERT_ELEM()");
				launch_values_test(test_erase_ft, test_erase_std, "ERASE()");
				launch_values_test(test_swap_ft, test_swap_std, "SWAP()");
				launch_values_test(test_clear_ft, test_clear_std, "CLEAR()");
				launch_values_test(test_operator_equal_ft, test_operator_equal_std, "OPERATOR==()");
				launch_values_test(test_operator_not_equal_ft, test_operator_not_equal_std, "OPERATOR!=()");
				launch_values_test(test_operator_less_ft, test_operator_less_std, "OPERATOR<()");
				launch_values_test(test_operator_less_or_equal_ft, test_operator_less_or_equal_std, "OPERATOR<=()");
				launch_values_test(test_operator_more_ft, test_operator_more_std, "OPERATOR>()");
				launch_values_test(test_operator_more_ft, test_operator_more_or_equal_std, "OPERATOR>=()");
			}
};










#endif