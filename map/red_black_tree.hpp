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
			typedef	T															map_type;
			typedef	Allocator													Allocator_type;
			typedef typename ft::pair<key_type, map_type>						value_type;
			typedef Compare 													key_compare;
			typedef	typename Allocator::pointer									pointer;
			typedef	typename Allocator::const_pointer							const_pointer;
			typedef typename Allocator::reference								reference;
			typedef typename Allocator::const_reference							const_reference;
			typedef	typename Allocator::template rebind< Node<key, T> >::other 	node_alloc;
			typedef	size_t														size_type;
			typedef	Node<key, T>												node_type;
		private:
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

			node_type *insert_node(node_type *root, node_type	*newnode)
			{
				if(root == NULL){
					root = newnode;
				}
				else if (newnode->_data < root->_data)
				{
					root->left = insert_node(root->left, newnode);
					root->left->parent = root;
				}
				else if (newnode->_data > root->_data){
					root->right = insert_node(root->right, newnode);
					root->right->parent = root;
				}
				return (root);
			}

			node_type	*creatNode(value_type data){
				node_type *node = node_alloc(this->_alloc).allocate(1);
				node->_data = data;
				node->left = node->right = node->parent = NULL;
				this->_size++;
				node->color = RED;
				return (node);
			}
			void insert(value_type data)
			{
				node_type *node = creatNode(data);
				this->_data = insert_node(this->_data, node);
			}
			size_type getSize( void ){
				return (this->_size);
			}

			void DisplayTree(node_type *root, int space)
			{
				if (root == NULL)
					return;
				space += 5;
				DisplayTree(root->right, space);
				std::cout<< std::endl;
				for (int i = 7; i < space; i++)
					std::cout<<" ";
				value_type p = root->_data;
				std::cout<< "first -> " << p.first << "second -> " << p.second << std::endl;
				DisplayTree(root->left, space);
			}
			void	print(void ){
				node_type *tmp = this->_data;
				DisplayTree(tmp, 7);
			}

	};
	
};
#endif