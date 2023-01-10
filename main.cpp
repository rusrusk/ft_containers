#include <iostream>
#include <vector>
#include "containers/vector.hpp"
#include "colors.hpp"
#include <iomanip>
#include "tests/vector_test.hpp"
// #include "iterators/ft_random_access_iterator.hpp"


// template<typename T>
// std::ostream &operator<<(std::ostream &os, const ft::Vector<T> &vec)
// {
// 	os.put('[');
// 	char comma[3] = {'\0', ' ', '\0'};
// 	for (unsigned long i = 0; i < vec.size(); i++)
// 	{
// 		os << comma << vec[i];
// 		comma[0] = ',';
// 	}
// 	return os << ']';
// }

// int main () {
// 	std::cout << COLOR_BOLD_YELLOW << std::string(35, 32) << std::string(60, '-') << END << std::endl;
// 	for (int i = 0; i < 4; i++) {
// 		std::cout << std::string(35, 32) << COLOR_BOLD_YELLOW << "|" << COLOR_ON_CYAN << std::string(59, 32) << END << COLOR_BOLD_YELLOW << "|" << END << std::endl;
// 		// for (int j = 0; j < 4; j++) {
// 		// 	std::cout << COLOR_BOLD_YELLOW << "|" << END << std::endl;

// 		// }
// 		if (i == 1) {
// 		// std::cout << COLOR_BOLD_YELLOW << "|" << END << std::endl;
// 			std::cout << std::string(35, 32) << COLOR_BOLD_YELLOW << "|" << COLOR_ON_CYAN << std::string(20, 32) << "FT_CONTAINERS TEST" << std::string(21, 32) << END << COLOR_BOLD_YELLOW << "|" << END;
// 			std::cout << std::endl;
// 		}
// 	}
// 	std::cout << std::string(35, 32) << COLOR_BOLD_YELLOW << std::string(60, '-') << END << std::endl;

// 	delimiter;

// 	std::cout << std::string(30, 32) << COLOR_BOLD_RED << std::string(25, 32) << "FILLED CONSTRUCTORS" << END << std::endl;
// 	std::cout << std::setw(30) << COLOR_GREEN << std::string(80, '-') << END << std::endl;
// 	ft::Vector<std::string>filled_constructor(5, "RUS");
// 	for (unsigned long i = 0; i < filled_constructor.size(); i++) {
// 		std::cout << std::setw(30) << COLOR_GREEN << "|" << std::setw(79) << "|" << END << std::endl;
// 		if (i == 1) {
// 			std::cout << std::setw(30) << COLOR_GREEN << "|" << END << std::setw(30);
// 			std::cout << "filled_constructor: " << filled_constructor << std::setw(28) << COLOR_GREEN << "|" << "\n";
// 		}
// 	}
// 	std::cout << std::setw(30) << COLOR_GREEN << std::string(80, '-') << END << std::endl;

// 	delimiter;

// 	std::cout << std::string(30, 32) << COLOR_BOLD_RED << std::string(25, 32) << "RANGE CONSTRUCTORS" << END << std::endl;
// 	std::cout << std::setw(30) << COLOR_GREEN << std::string(80, '-') << END << std::endl;
// 	ft::Vector<int>range_constructor(10);
// 	ft::Vector<int>iterate_through_range_constr(range_constructor.begin(), range_constructor.end());
// 	for (unsigned long i = 0; i < iterate_through_range_constr.size(); i++) {
// 		std::cout << std::setw(30) << COLOR_GREEN << "|" << std::setw(79) << "|" << END << std::endl;
// 		if (i == 1) {
// 			std::cout << std::setw(30) << COLOR_GREEN << "|" << END << std::setw(30);
// 			std::cout << "range_constructor: " << iterate_through_range_constr << std::setw(28) << COLOR_GREEN << "|" << "\n";
// 		}
// 	}
// 	std::cout << std::setw(30) << COLOR_GREEN << std::string(80, '-') << END << std::endl;

// 	delimiter;
// }

int main () {

	VectorTest Vector;
	Vector.launch_all_tests();
}