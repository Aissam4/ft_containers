#include "red_black_tree.hpp"
#include <iostream>

int main(void)
{
	ft::RBTree<int ,int > root;
	const int x = 10;
	const int y = 20;
	root.creatNode(std::pair<int, int>(x, y));
}