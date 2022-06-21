/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:04:41 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/21 17:37:52 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "reverseMapIterator.hpp"
#include "red_black_tree.hpp"
#include "RBTreeIterators.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/equal.hpp"
#include <iostream>


namespace ft
{
	template < class key, class T, class Compare = std::less<key>, class Allocator = std::allocator<ft::pair<key,T> > >
	class map
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
			// typedef MapIterator<value_type, Node<key_type, map_type> >			iterator;
			// typedef ReverseMapIterator<iterator>								reverseIterator;
			typedef RBTreeIter<value_type, Node<key, T> >							iterator;
			typedef	std::ptrdiff_t												difference_type;
			typedef	size_t														size_type;
			typedef	typename ft::RBTree<key, T>::const_iterator							const_iterator;
		private:
			ft::RBTree<key_type, map_type>	_tree;
			size_type						_size;
			Allocator_type					_alloc;
			node_alloc						_node_alloc;
			key_compare						_comp;
		public:
			map( void )
			{
				this->_size = 0;
				this->_alloc = Allocator_type();
				this->_node_alloc = node_alloc();
				this->_comp = key_compare();
			}
			map(const Compare& comp, const Allocator& alloc = Allocator())
			{
				this->_comp = comp;
				this->_alloc = alloc;
				this->_size = 0;
				this->_node_alloc = node_alloc();
			}
			map (const map &obj)
			{
				this->_alloc = obj._alloc;
				this->_comp = obj._comp;
				this->_size = obj._size;
				this->_node_alloc = obj._node_alloc;
				*this = obj;
			}
			map( const map& other, const Allocator& alloc )
			{
				this->_alloc = alloc;
				this->_size = other._size;
				this->_comp = other._comp;
				this->_size = other._size;
				this->_node_alloc = other._node_alloc;
				*this = other;
			}
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
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
			void	insert(value_type val)
			{
				this->_tree.insert(val);
			}
			iterator begin( void )
			{
				iterator it = this->_tree.begin();
				it--;
				return (it);
			}
			const_iterator cbegin( void )
			{
				const_iterator it = this->_tree.cbegin();
				it--;
				return (it);
			}
			iterator end( void ) { return (this->_tree.end());}
			
			const_iterator	cend( void )
			{
				return (this->_tree.cend());}
				
			void	print( void )
			{
				this->_tree.print();
			}
	};
}
#endif