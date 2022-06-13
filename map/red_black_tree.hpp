#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__
#include <iostream>
#include <algorithm>
namespace ft
{
	template<class T>
		struct Node{
			T	_data;
			Node<T>	*right, left, parent;
			bool color;
			Node(T data) : _data(data), right(NULL), left(NULL), parent(NULL){};
		}

	template<class T, class  Compare, class Allocator = std::allocator<T> >
	class RBTree
	{
		typedef Node<T> Node;
		public:
			Node T;

	};
	
};
#endif