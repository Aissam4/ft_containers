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
		root.insert(ft::pair<int, int>(30, 0));
		root.insert(ft::pair<int, int>(30, 0));
		root.print();
		// root.erase(34);
		// std::cout << "=========== erase test ==========" << std::endl;
		// root.print();
		// root.print();
		// root.setData(root.right_rotate(root.getData()));
		// std::cout << "-------------------------------------" << std::endl;
		// root.search(34);
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