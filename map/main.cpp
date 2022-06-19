#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	// ft::map<int, int> myMap;
	ft::RBTree<int, int> tree;
	std::map<int, int> map;
	map.insert(std::pair<int, int> (10, 11));
	tree.insert(ft::pair<int, int> (10, 11));
	std::cout << (tree.begin()->second);
	std::cout << (map.begin()->second);
	// std::map<int, int> m;
	// m.insert(std::pair<int, int> (10, 20));
	// m.insert(std::pair<int, int> (100, 200));
	// m.insert(std::pair<int, int> (1, 2));

	// std::cout << *(m.begin()) << std::endl;
	// (void)myMap;
}