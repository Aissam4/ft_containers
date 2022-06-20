#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

#define RED 1
#define BLACK 0
#include <iostream>
#include "../utils/pair.hpp"
#include "RBTreeIterators.hpp"
#include <cstddef>

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
	template < class key, class T, class Compare = std::less<key>, class Allocator = std::allocator<ft::pair<key,T> > >
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
			typedef RBTreeIter<value_type, node_type>							Iterator;
		private:
			node_type		*_data;
			node_type		*_end;
			Allocator_type	_alloc;
			size_type		_size;
			key_compare		_comp;
			int				_flag;
		public:
			RBTree(const key_compare &comp = key_compare(), const Allocator_type &alloc = Allocator_type()): _data(NULL), _end(NULL)
			{
				this->_size = 0;
				this->_alloc = alloc;
				this->_comp = comp;
				this->_flag = 1;
			}
			~RBTree( void )
			{
				this->_size = 0;
				node_alloc(this->_alloc).deallocate(_data, _size);
			}
			node_type *insert_node(node_type *root, node_type	*newnode)
			{
				if(root == NULL)
					return newnode;
				else if (newnode->_data.first < root->_data.first)
				{
					root->left = insert_node(root->left, newnode);
					root->left->parent = root;
				}
				else if (newnode->_data.first > root->_data.first){
					root->right = insert_node(root->right, newnode);
					root->right->parent = root;
				}
				else if (newnode->_data.first == root->_data.first)
				{
					node_alloc(this->_alloc).destroy(newnode);
					node_alloc(this->_alloc).deallocate(newnode, 1);
					this->_flag = 0;
				}

				return (root);
			}
			node_type	*creatNode(value_type data)
			{
				node_type *node = node_alloc(this->_alloc).allocate(1);
				node->_data = data;
				node->left = node->right = node->parent = NULL;
				node->color = RED;
				this->_flag = 1;
				return (node);
			}
			void right_rotate(node_type*& root, node_type*& item)
			{
				node_type* parent_left = item->left;
				item->left = parent_left->right;
				if (item->left != NULL)
					item->left->parent = item;
				parent_left->parent = item->parent;
				if (item->parent == NULL)
					root = parent_left;
				else if (item == item->parent->left)
					item->parent->left = parent_left;
				else
					item->parent->right = parent_left;
				parent_left->right = item;
				item->parent = parent_left;
			}
			void left_rotate(node_type*& root, node_type*& item)
			{
				node_type* parent_right = item->right;
				item->right = parent_right->left;
				if (item->right != NULL)
					item->right->parent = item;
				parent_right->parent = item->parent;
				if (item->parent == NULL)
					root = parent_right;
				else if (item == item->parent->left)
					item->parent->left = parent_right;
				else
					item->parent->right = parent_right;
				parent_right->left = item;
				item->parent = parent_right;
			}
			void balance(node_type*& root, node_type*& item)
			{
				node_type *parent_item = NULL;
				node_type *grandParent_item = NULL;
				while ((item != root) && (item->color != BLACK) && (item->parent->color == RED))
				{
					parent_item = item->parent;
					grandParent_item = item->parent->parent;
					if (parent_item == grandParent_item->left)
					{
						node_type* uncle_item = grandParent_item->right;
						if (uncle_item != NULL && uncle_item->color == RED)
						{
							grandParent_item->color = RED;
							parent_item->color = BLACK;
							uncle_item->color = BLACK;
							item = grandParent_item;
						}
						else
						{
							if (item == parent_item->right)
							{
								left_rotate(root, parent_item);
								item = parent_item;
								parent_item = item->parent;
							}
							right_rotate(root, grandParent_item);
							std::swap(parent_item->color, grandParent_item->color);
							item = parent_item;
						}
					} 
					else {
						node_type* uncle_item = grandParent_item->left;
						if ((uncle_item != NULL) && (uncle_item->color == RED))
						{
							grandParent_item->color = RED;
							parent_item->color = BLACK;
							uncle_item->color = BLACK;
							item = grandParent_item;
						}
						else
						{
							if (item == parent_item->left)
							{
								right_rotate(root, parent_item);
								item = parent_item;
								parent_item = item->parent;
							}
							left_rotate(root, grandParent_item);
							std::swap(parent_item->color, grandParent_item->color);
							item = parent_item;
						}
					}
				}
				root->color = BLACK;
			}
			void insert(value_type data)
			{
				node_type *node = creatNode(data);
				this->_end = node;
				this->_data = insert_node(this->_data, node);
				this->_size++;
				if (this->_flag)
					balance(this->_data, node);
			}
			void insert(Iterator iter)
			{
				node_type *node = creatNode(iter._current->_data);
				this->_end = node;
				this->_data = insert_node(this->_data, node);
				this->_size++;
				if (this->_flag)
					balance(this->_data, node);
			}
			size_type getSize( void )
			{
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
				if (root->color == RED)
					std::cout<< "\033[0;31mfirst -> ( " << p.first << " second -> \033[0m" << p.second << " )" << std::endl;
				else
					std::cout<< "first -> ( " << p.first << "second -> " << p.second << " )" << std::endl;
				DisplayTree(root->left, space);
			}
			void	print( void )
			{
				node_type *tmp = this->_data;
				DisplayTree(tmp, 7);
			}
			node_type	*getData( void )
			{
				return (this->_data);
			}
			void	setData( node_type *data)
			{
				this->_data = data;
			}
			node_type	*search_in_tree(node_type *root, key_type element)
			{
				node_type *tmp;
				if (root == NULL || root->_data.first == element)
					tmp = root;
				else if (root->_data.first < element)
					tmp = search_in_tree(root->right, element);
				else if (root->_data.first > element)
					tmp = search_in_tree(root->left, element);
				return (tmp);
			}
			node_type	*search(key_type element )
			{
				node_type *tmp = search_in_tree(this->_data, element);
				return (tmp);
			}
			node_type *Tree(node_type *temp)
			{
				while (temp->left != NULL)
					temp = temp->left;
				return (temp);
			}
			node_type	*delete_node(node_type *root, key_type key_)
			{
				if (root == NULL) return (NULL);
				else if (key_ < root->_data.first)
					root->left = delete_node(root->left, key_);
				else if (key_ > root->_data.first)
					root->right = delete_node(root->right, key_);
				else
				{
					if (root->left == NULL && root->right == NULL)
					{
						node_alloc(this->_alloc).destroy(root);
						node_alloc(this->_alloc).deallocate(root, 1);
						root = NULL;
						return (root);
					}
					else if (root->left == NULL)
					{
						node_type	*temp = root;
						root = root->right;
						root->parent = temp->parent;
						node_alloc(this->_alloc).destroy(temp);
						node_alloc(this->_alloc).deallocate(temp, 1);
						temp = NULL;
						return (root);
					}
					else if (root->right == NULL)
					{
						node_type	*temp = root;
						root = root->left;
						root->parent = temp->parent;
						node_alloc(this->_alloc).destroy(temp);
						node_alloc(this->_alloc).deallocate(temp, 1);
						temp = NULL;
						return (root);
					}
					else
					{
						node_type	*temp = Tree(root->right);
						root->right = delete_node(root->right , temp->_data.first);
					}
				}
				return (root);
			}
			void	erase(key_type key_)
			{
				delete_node(this->_data, key_);
			}
			Iterator	begin( void )
			{
				return (Iterator(this->_data));
			}
			Iterator end( void){
				return (Iterator(this->_end));
			}
	};
	
};
#endif