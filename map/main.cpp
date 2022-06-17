#include "red_black_tree.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=================right rotate test================" << std::endl;
	{
		ft::RBTree<int ,int > root;
		root.insert(ft::pair<int, int>(34, 0));
		root.insert(ft::pair<int, int>(32, 0));
		root.insert(ft::pair<int, int>(56, 0));
		root.insert(ft::pair<int, int>(30, 0));
		root.insert(ft::pair<int, int>(31, 0));
		// root.insert(ft::pair<int, int>(6, 40));
		// root.insert(ft::pair<int, int>(5, 3));
		// root.insert(ft::pair<int, int>(50, 3));
		// root.insert(ft::pair<int, int>(500, 3));
		// root.insert(ft::pair<int, int>(-5, 3));
		// root.insert(ft::pair<int, int>(99, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(10000, 3));
		// root.insert(ft::pair<int, int>(100090, 3));
		// root.insert(ft::pair<int, int>(1008090, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.insert(ft::pair<int, int>(1, 3));
		// root.print();
		// root.setData(root.right_rotate(root.getData()));
		// std::cout << "-------------------------------------" << std::endl;
		root.print();
	}
	// std::cout << "=================left rotate test===================" << std::endl;
	// {
	// 	ft::RBTree<int ,int > root;
	// 	root.insert(ft::pair<int, int>(5, 30));
	// 	root.insert(ft::pair<int, int>(6, 40));
	// 	root.insert(ft::pair<int, int>(7, 3));
	// 	root.print();
	// 	root.setData(root.left_rotate(root.getData()));
	// 	std::cout << "-------------------------------------" << std::endl;
	// 	root.print();
	// }
}