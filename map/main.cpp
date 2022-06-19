#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	// ft::map<int, int> myMap;
	ft::RBTree<int, int> tree;
	for(int i = 0; i < 10; i++){
		tree.insert(ft::pair<int, int>(rand() %12, rand() % 100));}
	tree.begin();
	// std::map<int, int> m;
	// m.insert(std::pair<int, int> (10, 20));
	// m.insert(std::pair<int, int> (100, 200));
	// m.insert(std::pair<int, int> (1, 2));

	// std::cout << *(m.begin()) << std::endl;
	// (void)myMap;
}