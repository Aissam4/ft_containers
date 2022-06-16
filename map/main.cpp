#include "red_black_tree.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=================right rotate test================" << std::endl;
	{
		ft::RBTree<int ,int > root;
		root.insert(ft::pair<int, int>(10, 30));
		root.insert(ft::pair<int, int>(6, 40));
		root.insert(ft::pair<int, int>(5, 3));
		root.print();
		root.setData(root.right_rotate(root.getData()));
		std::cout << "-------------------------------------" << std::endl;
		root.print();
	}
	std::cout << "=================left rotate test===================" << std::endl;
	{
		ft::RBTree<int ,int > root;
		root.insert(ft::pair<int, int>(5, 30));
		root.insert(ft::pair<int, int>(6, 40));
		root.insert(ft::pair<int, int>(7, 3));
		root.print();
		root.setData(root.left_rotate(root.getData()));
		std::cout << "-------------------------------------" << std::endl;
		root.print();
	}
}