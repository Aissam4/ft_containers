#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

#define RED 1
#define BLACK 0
#define NULL (void *)0

namespace ft
{
	template<class T>
		struct Node{
			T	_data;
			Node<T>	*right, left, parent;
			bool color;
			Node(T data) : _data(data), right(NULL), left(NULL), parent(NULL), color(RED){};
		};

	template<class T, class  Compare, class Allocator>
	class RBTree
	{
		typedef ft::Node<T> 	Node;
		typedef	T			value_type;
		typedef	Allocator	Allocator_type;
		typedef typename	Allocator_type::template rebind<Node>::other Node_Allocator;
		typedef Compare		key_compare;
	

	};
	
};
#endif