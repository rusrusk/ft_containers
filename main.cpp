#include <iostream>
#include <vector>
#include "containers/vector.hpp"
#include "colors.hpp"
#include <iomanip>
#include "tests/vector_test.hpp"
#include "iterators/ft_bidirectional_iterator.hpp"
#include "containers/binary_search_tree.hpp"
#include <map>
#include "containers/map.hpp"


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

// int main () {

// 	VectorTest Vector;
// 	Vector.launch_all_tests();
// }



// struct BstNode {
// 	int data;
// 	BstNode *left;
// 	BstNode *right;
// };

// BstNode *getNewNode(int data) {

// 	BstNode *newNode = new BstNode();
// 	newNode->data = data;
// 	newNode->left = newNode->right = NULL;
// 	return newNode;
// }

// bool Search(BstNode *root, int data) {
// 	if (!root)
// 		return false;
// 	else if (root->data == data)
// 		return true;
// 	else if (data <= root->data)
// 		return Search(root->left, data);
// 	else
// 		return Search(root->right, data);
	
// }

// BstNode *Insert(BstNode *root, int data) {
// 	if (!root) {
// 		root = getNewNode(data);
// 		return root;
// 	}
// 	else if (data <= root->data) {
// 		root->left = Insert(root->left, data);
// 	}
// 	else
// 		root->right = Insert(root->right, data);
// 	return root;
// }


// int main () {
// 	BstNode *root = NULL;
// 	root = Insert(root, 15);
// 	root = Insert(root, 10);
// 	root = Insert(root, 20);
// 	root = Insert(root, 25);
// 	root = Insert(root, 8);
// 	root = Insert(root, 12);

// 	int nb;

// 	std::cout << "Enter number be searched\n ";
// 	std::cin >> nb;
// 	if (Search(root, nb) == true)
// 		std::cout << "Found\n";
// 	else
// 		std::cout << "Not Found\n";
// }

int main ()
{
	return 0;
}