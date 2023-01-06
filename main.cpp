#include <iostream>
#include <vector>
#include "containers/vector.hpp"
#include "colors.hpp"
// #include "iterators/ft_random_access_iterator.hpp"




int main () {
	std::cout << COLOR_BOLD_YELLOW << std::string(30, 32) << std::string(60, '-') << END << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << std::string(30, 32) << COLOR_BOLD_YELLOW << "|" << COLOR_ON_CYAN << std::string(59, 32) << END << COLOR_BOLD_YELLOW << "|" << END << std::endl;
		// for (int j = 0; j < 4; j++) {
		// 	std::cout << COLOR_BOLD_YELLOW << "|" << END << std::endl;

		// }
		if (i == 1) {
		// std::cout << COLOR_BOLD_YELLOW << "|" << END << std::endl;
			std::cout << std::string(30, 32) << COLOR_BOLD_YELLOW << "|" << COLOR_ON_CYAN << std::string(20, 32) << "FT_CONTAINERS TEST" << std::string(21, 32) << END << COLOR_BOLD_YELLOW << "|" << END;
			std::cout << std::endl;
		}
	}
	std::cout << std::string(30, 32) << COLOR_BOLD_YELLOW << std::string(60, '-') << END << std::endl;

	delimiter;

	std::cout << std::string(30, 32) << COLOR_BOLD_RED << std::string(25, 32) << "CONSTRUCTORS" << END << std::endl;
	ft::Vector<size_t> vec(10, 4);

}

