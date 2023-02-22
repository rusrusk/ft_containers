#ifndef TEST_HPP
# define TEST_HPP

#include <sys/time.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include "../colors.hpp"

static time_t g_start1;
static time_t g_start2;
static time_t g_end1;
static time_t g_end2;

#define LIMIT 100

class Test {
	protected :
			time_t timer() {
				struct timeval start = {};
				gettimeofday(&start, nullptr);
				time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
				return msecs_time; //returns time in milliseconds
			}

	public :
			time_t start;
			time_t end;

			virtual void launch_all_tests() {}

			static void render_all_results(std::vector<int> &std_result, std::vector<int> &ft_result) {
				std::cout << "std:";
				for (std::vector<int>::iterator it = std_result.begin(); it != std_result.end(); it++) {
					std::cout << *it << '|';
				}
				std::cout << std::endl << "ft :";
				for (std::vector<int>::iterator itr = ft_result.begin(); itr != ft_result.end(); itr++) {
					std::cout << *itr << '|';
				}

			}

			void launch_test(std::vector<int> test_ft(), std::vector<int> test_std(), std::string test_name) {
				time_t time1;
				time_t time2;
				std::cout << COLOR_BOLD_BLUE << std::left << std::setw(20) << test_name << END << "|";
				// set_start();
				g_start1 = timer();
				std::vector<int> ft_result = test_ft();
				// set_end();
				g_end1 = timer();
				get_time_result();
				time1 = g_end1 - g_start1;
				time2 = g_end2 - g_start2;
				std::cout << "<ft> time : " << std::setw(4) << std::to_string(time1) + "ms" << '|';
				// set_start();
				g_start2 = timer();
				std::vector<int> std_result = test_std();
				// set_end();
				g_start2 = timer();
				get_time_result();
				std::cout << " <std> time : " << std::setw(4) << std::to_string(time1) + "ms";
				std::cout << "| result comparisation: " << (ft_result == std_result ? "✅ " : "❌ ") << std::endl;
			}

			void launch_values_test(std::vector<int> test_ft(), std::vector<int> test_std(), std::string test_name)
			{
				std::cout << COLOR_BOLD_BLUE << test_name << END << "\n";
				std::vector<int> ft_result = test_ft();
				std::vector<int> std_result = test_std();
				render_all_results(std_result, ft_result);
				std::cout << std::endl;
			}

	public :
			void set_start() {
				start = timer();
			}

			void set_end() {
				end = timer();
			}

			time_t get_time_result() const {
				return end - start;
			}


};










#endif
