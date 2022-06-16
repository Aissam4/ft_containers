#include "red_black_tree.hpp"
#include <iostream>

int main(void)
{
	ft::RBTree<int ,int > root;
	const int x = 10;
	const int y = 20;
	ft::pair<int, int> p(x, y);
	root.insert(p);
	root.insert(p);
	root.insert(p);
	root.insert(p);
	std::cout << root.getSize() << std::endl;
}