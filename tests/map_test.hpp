#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP


#include "test.hpp"
#include "../containers/map.hpp"


class MapTest : Test
{
	private : 
		//######################################################################
		//######################## CONSTRUCTORS ################################
		//######################################################################
		static std::vector<int> test_constructor_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			result.push_back(map.size());
			std::map<int, int> map2(map);
			result.push_back(map2.size());
			return result;
		}

		static std::vector<int> test_constructor_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			result.push_back(map.size());
			ft::map<int, int> map2(map);
			result.push_back(map2.size());
			return result;
		}

		//######################################################################
		//######################## ITERATORS ###################################
		//######################################################################
				static std::vector<int>test_iterators_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			for (int i = 0, j = -100; i < 100; ++i, --j)
				map.insert(std::make_pair(i, j));
			std::map<int, int>::iterator it1 = map.begin();
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1++;
			it1++;
			it1++;
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1--;
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1++;
			it1++;
			it1++;
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1--;
			result.push_back(it1->first);
			result.push_back(it1->second);
			
			std::map<int, int>::iterator it2 = --map.end();
			result.push_back(it2->first);
			result.push_back(it2->second);
			it2--;
			it2--;
			it2--;
			result.push_back(it2->first);
			result.push_back(it2->second);
			it2--;
			it2--;
			it2--;
			it2++;
			result.push_back(it2->first);
			result.push_back(it2->second);
			std::map<int, int>::reverse_iterator it3 = ++map.rbegin();
			result.push_back(it3->first);
			result.push_back(it3->second);
			it3++;
			it3++;
			it3++;
			it3--;
			result.push_back(it3->first);
			result.push_back(it3->second);
			std::map<int, int>::reverse_iterator it4 = --map.rend();
			result.push_back(it4->first);
			result.push_back(it4->second);
			it4--;
			it4--;
			it4--;
			it4++;
			result.push_back(it4->first);
			result.push_back(it4->second);
			return result;
		}

		static std::vector<int>test_iterators_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			for (int i = 0, j = -100; i < 100; ++i, --j)
				map.insert(ft::make_pair(i, j));
			ft::map<int, int>::iterator it1 = map.begin();
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1++;
			it1++;
			it1++;
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1--;
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1++;
			it1++;
			it1++;
			result.push_back(it1->first);
			result.push_back(it1->second);
			it1--;
			result.push_back(it1->first);
			result.push_back(it1->second);
			
			ft::map<int, int>::iterator it2 = --map.end();
			result.push_back(it2->first);
			result.push_back(it2->second);
			it2--;
			it2--;
			it2--;
			result.push_back(it2->first);
			result.push_back(it2->second);
			it2--;
			it2--;
			it2--;
			it2++;
			result.push_back(it2->first);
			result.push_back(it2->second);
			ft::map<int, int>::reverse_iterator it3 = ++map.rbegin();
			result.push_back(it3->first);
			result.push_back(it3->second);
			it3++;
			it3++;
			it3++;
			it3--;
			result.push_back(it3->first);
			result.push_back(it3->second);
			ft::map<int, int>::reverse_iterator it4 = --map.rend();
			result.push_back(it4->first);
			result.push_back(it4->second);
			it4--;
			it4--;
			it4--;
			it4++;
			result.push_back(it4->first);
			result.push_back(it4->second);
			return result;
		}

		//######################################################################
		//######################## CAPACITY ####################################
		//######################################################################
		static std::vector<int>test_empty_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			result.push_back(map.empty());
			map.insert(std::make_pair(42, 42));
			result.push_back(map.empty());
			map.clear();
			result.push_back(map.empty());
			return result;
		}

		static std::vector<int>test_empty_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			result.push_back(map.empty());
			map.insert(ft::make_pair(42, 42));
			result.push_back(map.empty());
			map.clear();
			result.push_back(map.empty());
			return result;
		}

		static std::vector<int>test_size_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			result.push_back(map.size());
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			result.push_back(map.size());
			std::map<int, int> map2;
			result.push_back(map2.size());
			map.clear();
			result.push_back(map.size());
			return result;
		}

		static std::vector<int>test_size_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			result.push_back(map.size());
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			result.push_back(map.size());
			ft::map<int, int> map2;
			result.push_back(map2.size());
			map.clear();
			result.push_back(map.size());
			return result;
		}


		static std::vector<int>test_max_size_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			result.push_back(map.max_size());
			return result;
		}

		static std::vector<int>test_max_size_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			result.push_back(map.max_size());
			return result;
		}

		//######################################################################
		//######################## ELEMENT ACCESS ##############################
		//######################################################################
		static std::vector<int>test_operator_square_brackets_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -100; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			result.push_back(map[0]);
			result.push_back(map[limit - 1]);
			result.push_back(map[limit / 2]);
			return result;
		}

		static std::vector<int>test_operator_square_brackets_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -100; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			result.push_back(map[0]);
			result.push_back(map[limit - 1]);
			result.push_back(map[limit / 2]);
			return result;
		}

		static std::vector<int>test_at_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -42; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			try
			{
				result.push_back(map.at(limit));
				result.push_back(map.at(limit + 1));
			}
			catch (std::exception &err)
			{
				result.push_back(-42);
			}
			return result;
		}

		static std::vector<int>test_at_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -42; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			try
			{
				result.push_back(map.at(limit));
				result.push_back(map.at(limit + 1));
			}
			catch (std::exception &err)
			{
				result.push_back(-42);
			}
			return result;
		}

		//######################################################################
		//######################## MODIFIERS ###################################
		//######################################################################
		static std::vector<int>test_insert_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			std::map<int, int>::iterator it = map.begin();
			result.push_back(it->second);
			result.push_back(map.size());
			std::map<int, int> map2;
			map2.insert(map.find(42), map.end());
			result.push_back(map2.begin()->second);
			result.push_back(map2.size());
			return result;
		}

		static std::vector<int>test_insert_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			ft::map<int, int>::iterator it = map.begin();
			result.push_back(it->second);
			result.push_back(map.size());
			ft::map<int, int> map2;
			map2.insert(map.find(42), map.end());
			result.push_back(map2.begin()->second);
			result.push_back(map2.size());
			return result;
		}

		static std::vector<int>test_erase_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			map.erase(map.begin()++->first);
			result.push_back(map.size());
			std::map<int, int>::iterator it1 = map.begin();
			std::map<int, int>::iterator it2 = map.find(10);
			map.erase(it1, it2);
			result.push_back(map.size());
			result.push_back(map.begin()->second);
			map.erase(map.begin()->first);
			result.push_back(map.size());
			result.push_back(map.begin()->second);
			map.erase(map.begin(), map.end()--);
			result.push_back(map.size());
			return result;
		}

		static std::vector<int>test_erase_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			map.erase(map.begin()++->first);
			result.push_back(map.size());
			ft::map<int, int>::iterator it1 = map.begin();
			ft::map<int, int>::iterator it2 = map.find(10);
			map.erase(it1, it2);
			result.push_back(map.size());
			result.push_back(map.begin()->second);
			map.erase(map.begin()->first);
			result.push_back(map.size());
			result.push_back(map.begin()->second);
			map.erase(map.begin(), map.end()--);
			result.push_back(map.size());
			return result;
		}

		static std::vector<int>test_swap_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			std::map<int, int> map2;
			map2.insert(std::make_pair(24,42));
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			map.swap(map2);
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			return result;
		}

		static std::vector<int>test_swap_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			ft::map<int, int> map2;
			map2.insert(ft::make_pair(24,42));
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			map.swap(map2);
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			result.push_back(map.size());
			result.push_back(map.begin()->first);
			result.push_back(map.begin()->second);
			return result;
		}

		static std::vector<int>test_clear_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			result.push_back(map.size());
			map.clear();
			result.push_back(map.size());
			return result;
		}

		static std::vector<int>test_clear_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			result.push_back(map.size());
			map.clear();
			result.push_back(map.size());
			return result;
		}

		//######################################################################
		//######################## OBSERVERS ###################################
		//######################################################################

		static std::vector<int>test_key_comp_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			std::map<int,int>::key_compare compare = map.key_comp();
			int target = map.find(limit / 3)->first;
			std::map<int, int>::iterator it = map.begin();
			result.push_back(compare(it->first, target));
			while (compare(it++->first, target))
				;
			result.push_back(compare(it->first, target));
			result.push_back(it->first);
			result.push_back(it->second);
			return result;
		}

		static std::vector<int>test_key_comp_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			ft::map<int,int>::key_compare compare = map.key_comp();
			int target = map.find(limit / 3)->first;
			ft::map<int, int>::iterator it = map.begin();
			result.push_back(compare(it->first, target));
			while (compare(it++->first, target))
				;
			result.push_back(compare(it->first, target));
			result.push_back(it->first);
			result.push_back(it->second);
			return result;
		}

		static std::vector<int>test_find_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			result.push_back(map.find(42)->second);
			result.push_back(map.find(0)->second);
			return result;
		}

		static std::vector<int>test_find_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			result.push_back(map.find(42)->second);
			result.push_back(map.find(0)->second);
			return result;
		}

		static std::vector<int>test_count_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			result.push_back(map.count(42));
			for (int i = 0; i < limit; ++i)
				map.insert(std::make_pair(i, i % 2 ? 42 : i));
			result.push_back(map.count(42));
			return result;
		}

		static std::vector<int>test_count_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			result.push_back(map.count(42));
			for (int i = 0; i < limit; ++i)
				map.insert(ft::make_pair(i, i % 2 ? 42 : i));
			result.push_back(map.count(42));
			return result;
		}

		static std::vector<int>test_lower_bound_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			std::map<int, int>::iterator lower = map.lower_bound(limit / 2);
			result.push_back(lower->first);
			result.push_back(lower->second);
			return result;
		}

		static std::vector<int>test_lower_bound_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			ft::map<int, int>::iterator lower = map.lower_bound(limit / 2);
			result.push_back(lower->first);
			result.push_back(lower->second);
			return result;
		}

		static std::vector<int>test_upper_bound_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(std::make_pair(i, j));
			std::map<int, int>::iterator upper = map.upper_bound(limit / 2);
			result.push_back(upper->first);
			result.push_back(upper->second);
			return result;
		}

		static std::vector<int>test_upper_bound_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			int limit = LIMIT;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map.insert(ft::make_pair(i, j));
			ft::map<int, int>::iterator upper = map.upper_bound(limit / 2);
			result.push_back(upper->first);
			result.push_back(upper->second);
			return result;
		}

		static std::vector<int>test_equal_range_std()
		{
			std::vector<int> result;
			std::map<int, int> map;
			map.insert(std::make_pair(10, 10));
			map.insert(std::make_pair(20, 20));
			map.insert(std::make_pair(30, 30));
			map.insert(std::make_pair(40, 40));
			map.insert(std::make_pair(50, 50));
			const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator> &range1 = map.equal_range(10);
			const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator> &range2 = map.equal_range(11);
			const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator> &range3 = map.equal_range(2);
			result.push_back(range1.first->first);
			result.push_back(range1.first->second);
			result.push_back(range1.second->first);
			result.push_back(range1.second->second);
			result.push_back(range2.first->first);
			result.push_back(range2.first->second);
			result.push_back(range2.second->first);
			result.push_back(range2.second->second);
			result.push_back(range3.first->first);
			result.push_back(range3.first->second);
			result.push_back(range3.second->first);
			result.push_back(range3.second->second);
			return result;
		}

		static std::vector<int>test_equal_range_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map;
			map.insert(ft::make_pair(10, 10));
			map.insert(ft::make_pair(20, 20));
			map.insert(ft::make_pair(30, 30));
			map.insert(ft::make_pair(40, 40));
			map.insert(ft::make_pair(50, 50));
			const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator> &range1 = map.equal_range(10);
			const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator> &range2 = map.equal_range(11);
			const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator> &range3 = map.equal_range(2);
			result.push_back(range1.first->first);
			result.push_back(range1.first->second);
			result.push_back(range1.second->first);
			result.push_back(range1.second->second);
			result.push_back(range2.first->first);
			result.push_back(range2.first->second);
			result.push_back(range2.second->first);
			result.push_back(range2.second->second);
			result.push_back(range3.first->first);
			result.push_back(range3.first->second);
			result.push_back(range3.second->first);
			result.push_back(range3.second->second);
			return result;
		}

		//######################################################################
		//######################## COMPARISON OPERATORS ########################
		//######################################################################
		static std::vector<int>test_operator_equal_std()
		{
			std::vector<int> result;
			std::map<int, int> map1;
			std::map<int, int> map2;
			std::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(std::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(std::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(std::make_pair(i, j));
			result.push_back(map1 == map2);
			result.push_back(map1 == map3);
			return result;
		}

		static std::vector<int>test_operator_equal_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map1;
			ft::map<int, int> map2;
			ft::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(ft::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(ft::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(ft::make_pair(i, j));
			result.push_back(map1 == map2);
			result.push_back(map1 == map3);
			return result;
		}

		static std::vector<int>test_operator_not_equal_std()
		{
			std::vector<int> result;
			std::map<int, int> map1;
			std::map<int, int> map2;
			std::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(std::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(std::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(std::make_pair(i, j));
			result.push_back(map1 != map2);
			result.push_back(map1 != map3);
			return result;
		}

		static std::vector<int>test_operator_not_equal_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map1;
			ft::map<int, int> map2;
			ft::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(ft::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(ft::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(ft::make_pair(i, j));
			result.push_back(map1 != map2);
			result.push_back(map1 != map3);
			return result;
		}

		static std::vector<int>test_operator_less_std()
		{
			std::vector<int> result;
			std::map<int, int> map1;
			std::map<int, int> map2;
			std::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(std::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(std::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(std::make_pair(i, j));
			result.push_back(map1 < map2);
			result.push_back(map1 < map3);
			return result;
		}

		static std::vector<int>test_operator_less_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map1;
			ft::map<int, int> map2;
			ft::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(ft::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(ft::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(ft::make_pair(i, j));
			result.push_back(map1 < map2);
			result.push_back(map1 < map3);
			return result;
		}

		static std::vector<int>test_operator_less_or_equal_std()
		{
			std::vector<int> result;
			std::map<int, int> map1;
			std::map<int, int> map2;
			std::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(std::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(std::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(std::make_pair(i, j));
			result.push_back(map1 <= map2);
			result.push_back(map1 <= map3);
			return result;
		}

		static std::vector<int>test_operator_less_or_equal_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map1;
			ft::map<int, int> map2;
			ft::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(ft::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(ft::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(ft::make_pair(i, j));
			result.push_back(map1 <= map2);
			result.push_back(map1 <= map3);
			return result;
		}

		static std::vector<int>test_operator_more_std()
		{
			std::vector<int> result;
			std::map<int, int> map1;
			std::map<int, int> map2;
			std::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(std::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(std::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(std::make_pair(i, j));
			result.push_back(map1 > map2);
			result.push_back(map1 > map3);
			return result;
		}

		static std::vector<int>test_operator_more_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map1;
			ft::map<int, int> map2;
			ft::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(ft::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(ft::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(ft::make_pair(i, j));
			result.push_back(map1 > map2);
			result.push_back(map1 > map3);
			return result;
		}

		static std::vector<int>test_operator_more_or_equal_std()
		{
			std::vector<int> result;
			std::map<int, int> map1;
			std::map<int, int> map2;
			std::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(std::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(std::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(std::make_pair(i, j));
			result.push_back(map1 >= map2);
			result.push_back(map1 >= map3);
			return result;
		}

		static std::vector<int>test_operator_more_or_equal_ft()
		{
			std::vector<int> result;
			ft::map<int, int> map1;
			ft::map<int, int> map2;
			ft::map<int, int> map3;
			int limit = LIMIT;
			int half_of_limit = limit / 2;
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map1.insert(ft::make_pair(i, j));
			for (int i = 0, j = -42; i < half_of_limit; ++i, --j)
				map2.insert(ft::make_pair(i, j));
			for (int i = 0, j = -limit; i < limit; ++i, --j)
				map3.insert(ft::make_pair(i, j));
			result.push_back(map1 >= map2);
			result.push_back(map1 >= map3);
			return result;
		}

	public :
		void launch_all_tests()
		{
			launch_test(test_constructor_ft, test_constructor_std, "CONSTRUCTOR()");
			launch_test(test_iterators_ft, test_iterators_std, "ITERATORS()");
			launch_test(test_empty_ft, test_empty_std, "EMPTY()");
			launch_test(test_size_ft, test_size_std, "SIZE()");
			launch_test(test_operator_square_brackets_ft, test_operator_square_brackets_std, "OPERATOR[]");
			launch_test(test_at_ft, test_at_std, "AT()");
			launch_test(test_insert_ft, test_insert_std, "INSERT()");
			launch_test(test_erase_ft, test_erase_std, "ERASE()");
			launch_test(test_swap_ft, test_swap_std, "SWAP()");
			launch_test(test_clear_ft, test_clear_std, "CLEAR()");
			launch_test(test_key_comp_ft, test_key_comp_std, "KEY_COMPARE()");
			launch_test(test_find_ft, test_find_std, "FIND()");
			launch_test(test_count_ft, test_count_std, "COUNT()");
			launch_test(test_lower_bound_ft, test_lower_bound_std, "LOWER_BOUND()");
			launch_test(test_upper_bound_ft, test_upper_bound_std, "UPPER_BOUND()");
			launch_test(test_equal_range_ft, test_equal_range_std, "EQUAL_RANGE()");
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
			launch_values_test(test_iterators_ft, test_iterators_std, "ITERATORS()");
			launch_values_test(test_empty_ft, test_empty_std, "EMPTY()");
			launch_values_test(test_size_ft, test_size_std, "SIZE()");
			launch_values_test(test_operator_square_brackets_ft, test_operator_square_brackets_std, "OPERATOR[]");
			launch_values_test(test_at_ft, test_at_std, "AT()");
			launch_values_test(test_insert_ft, test_insert_std, "INSERT()");
			launch_values_test(test_erase_ft, test_erase_std, "ERASE()");
			launch_values_test(test_swap_ft, test_swap_std, "SWAP()");
			launch_values_test(test_clear_ft, test_clear_std, "CLEAR()");
			launch_values_test(test_key_comp_ft, test_key_comp_std, "KEY_COMPARE()");
			launch_values_test(test_find_ft, test_find_std, "FIND()");
			launch_values_test(test_count_ft, test_count_std, "COUNT()");
			launch_values_test(test_lower_bound_ft, test_lower_bound_std, "LOWER_BOUND()");
			launch_values_test(test_upper_bound_ft, test_upper_bound_std, "UPPER_BOUND()");
			launch_values_test(test_equal_range_ft, test_equal_range_std, "EQUAL_RANGE()");
			launch_values_test(test_operator_equal_ft, test_operator_equal_std, "OPERATOR==()");
			launch_values_test(test_operator_not_equal_ft, test_operator_not_equal_std, "OPERATOR!=()");
			launch_values_test(test_operator_less_ft, test_operator_less_std, "OPERATOR<()");
			launch_values_test(test_operator_less_or_equal_ft, test_operator_less_or_equal_std, "OPERATOR<=()");
			launch_values_test(test_operator_more_ft, test_operator_more_std, "OPERATOR>()");
			launch_values_test(test_operator_more_or_equal_ft, test_operator_more_or_equal_std, "OPERATOR>=()");
		}
};







#endif