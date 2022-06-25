/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeIterSet.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:53 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/19 01:33:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __RBTREEITERATORS_SET_HPP__
#define __RBTREEITERATORS_SET_HPP__
#include <cstddef>
namespace ft
{
	template < class T, class M >
	class RBTreeIterSet
	{
		public :
			typedef M map_type;
			typedef map_type* map_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;
			map_pointer _current;
			~RBTreeIterSet() {}
			RBTreeIterSet() : _current(NULL) {}
			RBTreeIterSet(RBTreeIterSet const &rhs) : _current(rhs._current) {}
			RBTreeIterSet(map_pointer current) : _current(current) {}

			RBTreeIterSet &operator=(RBTreeIterSet const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~RBTreeIterSet();
        		return *new(this) RBTreeIterSet(rhs);
			}

			map_pointer		base() const {
				return (this->_current);
			}
			bool operator==(const RBTreeIterSet & rhs) { return (_current == rhs._current); }
			bool operator!=(const RBTreeIterSet & rhs) { return (_current != rhs._current); }
			T *operator*() { return(&(_current->_data)); }
			T *operator->() { return(&(_current->_data)); }
			T	getVal( void ){
				return (this->_current->_data);
			}
			RBTreeIterSet &operator++()
			{
				if (_current->right)
				{
					_current = _current->right;
					while (_current->left)
						_current = _current->left;
				}
				else
				{
					while (_current->parent && _current == _current->parent->right)
						_current = _current->parent;
					_current = _current->parent;
				}
				return (*this);
			}

			RBTreeIterSet &operator--()
			{
				if (_current->left) 
				{
					_current = _current->left;
					while (_current->right)
						_current = _current->right;
				}
				else
				{ 
					while (_current->parent && _current == _current->parent->left)
						_current = _current->parent;
					_current = _current->parent;
				}
				return (*this);
			}

			RBTreeIterSet operator++(int)
			{
				RBTreeIterSet tmp(*this);
				++(*this);
				return (tmp);
			}

			RBTreeIterSet operator--(int)
			{
				RBTreeIterSet tmp(*this);
				--(*this);
				return (*this);
			}
	};
}
#endif