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
			ft::pair<KEY, T>	_data;
			Node	*right, *left, *parent;
			bool color;
			Node(ft::pair<KEY, T> data) : _data(data), right(NULL), left(NULL), parent(NULL), color(RED){};
			Node() : right(NULL), left(NULL), parent(NULL), color(RED){};
		};

	template < class key, class T, class Compare = std::less<key>, class Allocator = std::allocator<std::pair<key,T> > >
	class RBTree
	{
		public:
			typedef	key															key_type;
			typedef	T															mapp_type;
			typedef	Allocator													Allocator_type;
			typedef typename ft::pair<key_type, mapp_type>						value_type;
			typedef Compare 													key_compare;
			typedef	typename Allocator::pointer									pointer;
			typedef	typename Allocator::const_pointer							const_pointer;
			typedef typename Allocator::reference								reference;
			typedef typename Allocator::const_reference							const_reference;
			typedef	typename Allocator::template rebind< Node<key, T> >::other 	node_alloc;
			typedef	size_t														size_type;
		private:
			typedef	Node<key, T>												node_type;
			node_type		*_data;
			Allocator_type	_alloc;
			size_type		_size;
			key_compare		_comp;
		public:
			RBTree(const key_compare &comp = key_compare(), const Allocator_type &alloc = Allocator_type()): _data(NULL){
				this->_size = 0;
				this->_alloc = alloc;
				this->_comp = comp;
			}
	};
	
};
#endif