#include "red_black_tree.hpp"
// #include <iostream>

using namespace std;
int main(void)
{
	ft::RBTree<std::string , string> root;
	std::string str = "Hello World !";
	root.NewNode(str);
	// cout << root.getData() << endl;
}