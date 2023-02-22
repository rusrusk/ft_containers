#ifndef STACK_TEST_HPP
#define STACK_TEST_HPP


#include "test.hpp"
#include "../containers/stack.hpp"

class StackTest : Test
{
	private :
		//######################################################################
		//######################## CONSTRUCTORS ################################
		//######################################################################

		static std::vector<int> test_constructor_std()
		{
			std::vector<int> result;
			int limit = LIMIT;
			std::deque<int> vec1;
			for (int i = 0; i < limit; ++i)
				vec1.push_back(i);
			std::vector<int> vec2;
			for (int i = 0; i < limit; ++i)
				vec2.push_back(i);
			std::stack<int> stack1(vec1);
			std::stack<int> stack2(stack1);
			result.push_back(stack1.size());
			result.push_back(stack1.top());
			stack1.pop();
			result.push_back(stack1.top());
			result.push_back(stack2.size());
			result.push_back(stack2.top());
			stack2.pop();
			result.push_back(stack2.top());
			return result;
		};
		
		static std::vector<int> test_constructor_ft()
		{
			std::vector<int> result;
			int limit = LIMIT;
			ft::vector<int> vec1;
			for (int i = 0; i < limit; ++i)
				vec1.push_back(i);
			ft::vector<int> vec2;
			for (int i = 0; i < limit; ++i)
				vec2.push_back(i);
			ft::stack<int> stack1(vec1);
			ft::stack<int> stack2(stack1);
			result.push_back(stack1.size());
			result.push_back(stack1.top());
			stack1.pop();
			result.push_back(stack1.top());
			result.push_back(stack2.size());
			result.push_back(stack2.top());
			stack2.pop();
			result.push_back(stack2.top());
			return result;
		};

		static std::vector<int> test_empty_std()
		{
			std::vector<int> result;
			std::stack<int> stack;
			result.push_back(stack.empty());
			for (int i = 0; i < 42; ++i)
				stack.push(i);
			result.push_back(stack.empty());
			result.push_back(stack.top());
			while (!stack.empty())
				stack.pop();
			result.push_back(stack.empty());
			return result;
		}

		static std::vector<int> test_empty_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack;
			result.push_back(stack.empty());
			for (int i = 0; i < 42; ++i)
				stack.push(i);
			result.push_back(stack.empty());
			result.push_back(stack.top());
			while (!stack.empty())
				stack.pop();
			result.push_back(stack.empty());
			return result;
		}

		static std::vector<int> test_size_std()
		{
			std::vector<int> result;
			std::stack<int> stack;
			result.push_back(stack.size());
			for (int i = 0; i < 42; ++i)
				stack.push(i);
			result.push_back(stack.size());
			return result;
		}

		static std::vector<int> test_size_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack;
			result.push_back(stack.size());
			for (int i = 0; i < 42; ++i)
				stack.push(i);
			result.push_back(stack.size());
			return result;
		}

		static std::vector<int> test_top_std()
		{
			std::vector<int> result;
			std::stack<int> stack;
			stack.push(stack.size());
			result.push_back(stack.top());
			for (int i = 0; i < 42; ++i)
				stack.push(i);
			result.push_back(stack.top());
			for (int i = 0; i < 42; ++i)
				stack.push(i * -1);
			result.push_back(stack.top());
			return result;
		}

		static std::vector<int> test_top_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack;
			stack.push(stack.size());
			result.push_back(stack.top());
			for (int i = 0; i < 42; ++i)
				stack.push(i);
			result.push_back(stack.top());
			for (int i = 0; i < 42; ++i)
				stack.push(i * -1);
			result.push_back(stack.top());
			return result;
		}

		static std::vector<int> test_push_std()
		{
			std::vector<int> result;
			std::stack<int> stack;
			result.push_back(stack.size());
			for (int i = 0; i < 200; ++i)
				stack.push(i);
			result.push_back(stack.size());
			result.push_back(stack.top());
			return result;
		}

		static std::vector<int> test_push_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack;
			result.push_back(stack.size());
			for (int i = 0; i < 200; ++i)
				stack.push(i);
			result.push_back(stack.size());
			result.push_back(stack.top());
			return result;
		}

		static std::vector<int> test_pop_std()
		{
			std::vector<int> result;
			std::stack<int> stack;
			result.push_back(stack.size());
			for (int i = 0; i < 200; ++i)
				stack.push(i);
			result.push_back(stack.size());
			result.push_back(stack.top());
			for (int i = 0; i < 200 / 2; ++i)
				stack.pop();
			result.push_back(stack.size());
			result.push_back(stack.top());
			while (!stack.empty())
				stack.pop();
			result.push_back(stack.size());
			return result;
		}

		static std::vector<int> test_pop_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack;
			result.push_back(stack.size());
			for (int i = 0; i < 200; ++i)
				stack.push(i);
			result.push_back(stack.size());
			result.push_back(stack.top());
			for (int i = 0; i < 200 / 2; ++i)
				stack.pop();
			result.push_back(stack.size());
			result.push_back(stack.top());
			while (!stack.empty())
				stack.pop();
			result.push_back(stack.size());
			return result;
		}

		//######################################################################
		//######################## COMPARISON OPERATORS ########################
		//######################################################################
		static std::vector<int> test_operator_equal_std()
		{
			std::vector<int> result;
			std::stack<int> stack1;
			std::stack<int> stack2;
			result.push_back(stack1 == stack2);
			stack2.push(42);
			result.push_back(stack1 == stack2);
			stack1.push(42);
			result.push_back(stack1 == stack2);
			return result;
		}

		static std::vector<int> test_operator_equal_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack1;
			ft::stack<int> stack2;
			result.push_back(stack1 == stack2);
			stack2.push(42);
			result.push_back(stack1 == stack2);
			stack1.push(42);
			result.push_back(stack1 == stack2);
			return result;
		}

		static std::vector<int> test_operator_not_equal_std()
		{
			std::vector<int> result;
			std::stack<int> stack1;
			std::stack<int> stack2;
			result.push_back(stack1 != stack2);
			stack2.push(42);
			result.push_back(stack1 != stack2);
			stack1.push(42);
			result.push_back(stack1 != stack2);
			return result;
		}

		static std::vector<int> test_operator_not_equal_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack1;
			ft::stack<int> stack2;
			result.push_back(stack1 != stack2);
			stack2.push(42);
			result.push_back(stack1 != stack2);
			stack1.push(42);
			result.push_back(stack1 != stack2);
			return result;
		}

		static std::vector<int> test_operator_less_std()
		{
			std::vector<int> result;
			std::stack<int> stack1;
			std::stack<int> stack2;
			result.push_back(stack1 < stack2);
			stack2.push(42);
			result.push_back(stack1 < stack2);
			stack1.push(42);
			result.push_back(stack1 < stack2);
			return result;
		}

		static std::vector<int> test_operator_less_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack1;
			ft::stack<int> stack2;
			result.push_back(stack1 < stack2);
			stack2.push(42);
			result.push_back(stack1 < stack2);
			stack1.push(42);
			result.push_back(stack1 < stack2);
			return result;
		}

		static std::vector<int> test_operator_less_or_equal_std()
		{
			std::vector<int> result;
			std::stack<int> stack1;
			std::stack<int> stack2;
			result.push_back(stack1 <= stack2);
			stack2.push(42);
			result.push_back(stack1 <= stack2);
			stack1.push(42);
			result.push_back(stack1 <= stack2);
			return result;
		}

		static std::vector<int> test_operator_less_or_equal_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack1;
			ft::stack<int> stack2;
			result.push_back(stack1 <= stack2);
			stack2.push(42);
			result.push_back(stack1 <= stack2);
			stack1.push(42);
			result.push_back(stack1 <= stack2);
			return result;
		}

		static std::vector<int> test_operator_more_std()
		{
			std::vector<int> result;
			std::stack<int> stack1;
			std::stack<int> stack2;
			result.push_back(stack1 > stack2);
			stack2.push(42);
			result.push_back(stack1 > stack2);
			stack1.push(42);
			result.push_back(stack1 > stack2);
			return result;
		}

		static std::vector<int> test_operator_more_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack1;
			ft::stack<int> stack2;
			result.push_back(stack1 > stack2);
			stack2.push(42);
			result.push_back(stack1 > stack2);
			stack1.push(42);
			result.push_back(stack1 > stack2);
			return result;
		}

		static std::vector<int> test_operator_more_or_equal_std()
		{
			std::vector<int> result;
			std::stack<int> stack1;
			std::stack<int> stack2;
			result.push_back(stack1 >= stack2);
			stack2.push(42);
			result.push_back(stack1 >= stack2);
			stack1.push(42);
			result.push_back(stack1 >= stack2);
			return result;
		}

		static std::vector<int> test_operator_more_or_equal_ft()
		{
			std::vector<int> result;
			ft::stack<int> stack1;
			ft::stack<int> stack2;
			result.push_back(stack1 >= stack2);
			stack2.push(42);
			result.push_back(stack1 >= stack2);
			stack1.push(42);
			result.push_back(stack1 >= stack2);
			return result;
		}

		public :
			void launch_all_tests()
			{
				launch_test(test_constructor_ft, test_constructor_std, "CONSTRUCTOR()");
				launch_test(test_empty_ft, test_empty_std, "EMPTY()");
				launch_test(test_size_ft, test_size_std, "SIZE()");
				launch_test(test_top_ft, test_top_std, "TOP()");
				launch_test(test_push_ft, test_push_std, "PUSH()");
				launch_test(test_pop_ft, test_pop_std, "POP()");
				launch_test(test_operator_equal_ft, test_operator_equal_std, "OPERATOR=()");
				launch_test(test_operator_not_equal_ft, test_operator_not_equal_std, "OPERATOR!=()");
				launch_test(test_operator_less_ft, test_operator_less_std, "OPERATOR<()");
				launch_test(test_operator_less_or_equal_ft, test_operator_less_or_equal_std, "OPERATOR<=()");
				launch_test(test_operator_more_ft, test_operator_more_std, "OPERATOR>()");
				launch_test(test_operator_more_or_equal_ft, test_operator_more_or_equal_std, "OPERATOR>=()");
			}

			void launch_all_values_tests()
			{
				launch_values_test(test_constructor_ft, test_constructor_std, "CONSTRUCTOR()");
				launch_values_test(test_empty_ft, test_empty_std, "EMPTY()");
				launch_values_test(test_size_ft, test_size_std, "SIZE()");
				launch_values_test(test_top_ft, test_top_std, "TOP()");
				launch_values_test(test_push_ft, test_push_std, "PUSH()");
				launch_values_test(test_pop_ft, test_pop_std, "POP()");
				launch_values_test(test_operator_equal_ft, test_operator_equal_std, "OPERATOR=()");
				launch_values_test(test_operator_not_equal_ft, test_operator_not_equal_std, "OPERATOR!=()");
				launch_values_test(test_operator_less_ft, test_operator_less_std, "OPERATOR<()");
				launch_values_test(test_operator_less_or_equal_ft, test_operator_less_or_equal_std, "OPERATOR<=()");
				launch_values_test(test_operator_more_ft, test_operator_more_std, "OPERATOR>()");
				launch_values_test(test_operator_more_or_equal_ft, test_operator_more_or_equal_std, "OPERATOR>=()");
			}
};



#endif