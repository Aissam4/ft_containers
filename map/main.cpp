#include "red_black_tree.hpp"
#include <iostream>

int main(void)
{
	ft::RBTree<int ,int > root;
	root.insert(ft::pair<int, int>(10, 30));
	root.insert(ft::pair<int, int>(50, 40));
	root.insert(ft::pair<int, int>(90, 3));
	root.insert(ft::pair<int, int>(100, 0));
	root.insert(ft::pair<int, int>(108, 60));
	// std::cout << root.getSize() << std::endl;
	root.print();
	// std::cout << root << std::endl;
	// std::cout << root->_data << std::endl;

}