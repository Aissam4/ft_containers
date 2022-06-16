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

	template < class key, class T, class Compare, class Allocator = std::allocator<std::pair<const key,T> > >
	class RBTree
	{
		public:
			typedef	key															key_type;
			typedef	T															mapp_type;
			typedef	Allocator													Allocator_type;
			typedef typename ft::pair<key_type, mapp_type>						value_type;
			typedef Compare 													key_compar;
			typedef	typename Allocator::pointer									pointer;
			typedef	typename Allocator::const_pointer							const_pointer;
			typedef	typename Allocator::refernce 								refernce;
			typedef	typename Allocator::const_refernce							const_refernce;
			typedef	typename Allocator::template rebind< Node<key, T> >::other 	node_alloc;
			typedef	size_t														size_type;
			
	};
	
};
#endif