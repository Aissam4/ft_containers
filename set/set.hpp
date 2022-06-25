/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:04:41 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/25 23:24:25 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __SET_HPP__
#define __SET_HPP__

#include "reverseSetIterator.hpp"
#include "../vector/reverse_iterator.hpp"
#include "red_black_tree_set.hpp"

#include <iostream>

namespace ft
{
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set
	{
		public:
			typedef	Allocator													Allocator_type;
			typedef T													value_type;
			typedef	typename ft::RBTree<value_type>								set_type;
			typedef Compare 													value_compare;
			typedef	typename Allocator::pointer									pointer;
			typedef	typename Allocator::const_pointer							const_pointer;
			typedef typename Allocator::reference								reference;
			typedef typename Allocator::const_reference							const_reference;
			typedef	typename Allocator::template rebind< Node<T> >::other	 	node_alloc;
			typedef ft::RBTreeIter<value_type, Node<T> >						iterator;
			typedef	std::ptrdiff_t												difference_type;
			typedef	size_t														size_type;
			typedef	typename ft::RBTree<T>::const_iterator						const_iterator;
			typedef	typename ft::RBTree<T>::reverse_iterator					reverse_iterator;		
			typedef	typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		private:
			ft::RBTree<value_type>			_tree;
			size_type						_size;
			Allocator_type					_alloc;
			node_alloc						_node_alloc;
			value_compare					_comp;
		public:
			set( void )
			{
				this->_size = 0;
				this->_alloc = Allocator_type();
				this->_node_alloc = node_alloc();
				this->_comp =	value_compare();
			}

			set(const Compare& comp, const Allocator& alloc = Allocator())
			{
				this->_comp = comp;
				this->_alloc = alloc;
				this->_size = 0;
				this->_node_alloc = node_alloc();
				_tree = nullptr;
			}

			set (const set &obj)
			{
				this->_alloc = obj._alloc;
				this->_comp = obj._comp;
				this->_size = obj._size;
				this->_node_alloc = obj._node_alloc;
				*this = obj;
			}

			set( const set& other, const Allocator& alloc )
			{
				this->_alloc = alloc;
				this->_size = other._size;
				this->_comp = other._comp;
				this->_size = other._size;
				this->_node_alloc = other._node_alloc;
				*this = other;
			}

			~set( void )
			{
				if (this->_tree.getSize() != 0)
					this->clear();
			}

			template< class InputIt >
			set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			{
				this->_comp = comp;
				this->_alloc = alloc;
				for (; first != last; first++)
				{
					this->_tree.insert(first);
					this->_size++;
				}
				this->_tree.insert(first);
			}

			Allocator_type get_allocator() const
			{
				return (this->_alloc);
			}

			void	insert(const value_type &val)
			{
				this->_tree.insert(val);
			}

			void	insert(iterator position, const value_type &val)
			{
				this->_tree.insert_in_position(position, val);
			}

			template<class inputIter>
			void	insert(inputIter first, inputIter last)
			{
				for (; first != last; first++)
					this->_tree.insert(first);
			}
	
			size_t erase(const value_type &key_)
			{
				this->_tree.erase(key_);
				return (this->_tree.getSize());
			}

			template <class inputIter>
			void	erase(inputIter iter)
			{
				this->_tree.erase(iter);
			}

			template <class inputIter>
			void	erase(inputIter first, inputIter last)
			{
				for (; first != last; first++)
					this->_tree.erase(first);
			}

			void	clear( void )
			{
				iterator it2 = this->_tree.end();
				it2++;
				erase(this->_tree.begin(), it2);
				this->_tree.setData(NULL);
			}

			bool empty( void ) const
			{
				return (this->_tree.getSize() == 0);
			}

			size_type size( void )
			{ 
				return (this->_tree.getSize());
			}

			size_type max_size( void ) const
			{
				return(461168601842738790);
			}

			Node<value_type>	&operator[](const value_type &k)
			{
				Node<value_type> *tmp = this->_tree.search(k);
				return (tmp->_data.second);
			}

			Node<value_type> & at (const value_type& k)
			{
				return (operator[](k));
			}

			const Node<value_type> & at (const value_type& k) const
			{
				return (operator[](k));
			}

			void	print( void )
			{
				this->_tree.print();
			}

			iterator begin( void )
			{
				iterator it = this->_tree.begin();
				return (it);
			}

			const_iterator cbegin( void ) const 
			{
				const_iterator it = this->_tree.cbegin();
				return (it);
			}

			iterator end( void ) { return (this->_tree.end());}
			
			const_iterator	cend( void ) const 
			{
				return (this->_tree.cend());
			}
			reverse_iterator rbegin( void )
			{
				reverse_iterator it = this->_tree.rbegin();
				return (it);
			}
			const_reverse_iterator rbegin( void ) const 
			{
				const_reverse_iterator it = this->_tree.rbegin();
				return (it);
			}
			reverse_iterator rend( void )
			{
				iterator it = this->_tree.rend();
				return (it);
			}
			const_reverse_iterator	rend( void ) const 
			{
				const_iterator it = this->_tree.rend();
				return (it);
			}
	};
}
#endif