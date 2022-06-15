#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

#define RED 1
#define BLACK 0
#define NULL (void *)0
#include <iostream>

#include "../utils/pair.hpp"

namespace ft
{
	template<typename KEY, typename T>
		struct Node
		{
			ft::pair<const KEY, T>	_data;
			Node	*right, *left, *parent;
			bool color;
			Node(ft::pair<const KEY, T> data) : _data(data), right(NULL), left(NULL), parent(NULL), color(RED){};
			Node() : right(NULL), left(NULL), parent(NULL), color(RED){};
		};

	template < class Key, class T, class Compare , class Allocator = std::allocator<ft::pair<const Key,T> > >
	class RBTree
	{
		public:

	};
	
};
#endif