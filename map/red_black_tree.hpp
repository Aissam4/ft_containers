#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

#define RED 1
#define BLACK 0
#define NULL (void *)0
#include <iostream>

namespace ft
{
	template<class T>
		struct Node{
			T	_data;
			Node<T>	*right, *left, *parent;
			bool color;
			Node(T data) : _data(data), right(NULL), left(NULL), parent(NULL), color(RED){};
		};

	template<class T, class  Compare, class Allocator = std::allocator<T> >
	class RBTree
	{
		public:
			typedef struct Node<T> 	Node;
			typedef	T			value_type;
			typedef	Allocator	Allocator_type;
			typedef typename	Allocator_type::template rebind<Node>::other Node_Allocator;
			typedef Compare		key_compare;
		private:
			Node 			*_Root;
			Allocator_type	_alloc;
			Node_Allocator	_Node_alloc;
			key_compare		_key_comapre;
			int				_count;
		public:
			//Copy Constructor
			RBTree(const RBTree &obj)
			{
				*this = obj;
			};
			//Default Constructor
			RBTree( void ){
				this->_Root = NULL;
				this->_alloc = Allocator_type();
				this->_Node_alloc = Node_Allocator();
				this->_key_comapre = key_compare();
				this->_count = 0;
			}

			Node	*getTree( void ){
				return this->_Root;
			}

			Node	*NewNode(const T data){
				this->_Root = this->_Node_alloc.allocate(1);
				this->_Root->_data = data;
				this->_Root->left = this->_Root->right = this->_Root->parent = NULL;
				this->_Root->color = RED;
				this->_count++;
				std::cout << "data => " << this->_Root->_data << std::endl;
				return (this->_Root);
			}
			T&	getData(void){
				return (this->_Root->_data);
			}
	

	};
	
};
#endif