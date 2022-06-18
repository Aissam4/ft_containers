/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:04:41 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/19 00:56:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "mapIterator.hpp"
#include "red_black_tree.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/equal.hpp"
#include <iostream>

namespace ft
{
	template < class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			// typedef	key															key_type;
			// typedef	T															map_type;
			typedef	Allocator													Allocator_type;
			// typedef typename ft::pair<key_type, map_type>						value_type;
			// typedef Compare 													key_compare;
			// typedef	typename Allocator::pointer									pointer;
			// typedef	typename Allocator::const_pointer							const_pointer;
			// typedef typename Allocator::reference								reference;
			// typedef typename Allocator::const_reference							const_reference;
			// typedef	typename Allocator::template rebind< Node<key, T> >::other 	node_alloc;
			// typedef	size_t														size_type;
			// ft::RBTree<key, T> *tree;
	};
}
#endif 