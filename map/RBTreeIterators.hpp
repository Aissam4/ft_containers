/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeIter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:53 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/19 01:33:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __RBTREEITERATORS_HPP__
#define __RBTREEITERATORS_HPP__

namespace ft
{
	template < class T, class M >
	class RBTreeIter
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
			~RBTreeIter() {}
			RBTreeIter() : _current(nullptr) {}
			RBTreeIter(RBTreeIter const &rhs) : _current(rhs._current) {}
			// RBTreeIter(ConstRBTreeIter<T, M> const &rhs) : _current(rhs._current) {}
			RBTreeIter(map_pointer current) : _current(current) {}

			RBTreeIter &operator=(RBTreeIter const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~RBTreeIter();
        		return *new(this) RBTreeIter(rhs);
			}
			// RBTreeIter &operator=(ConstRBTreeIter<T, M> const &rhs)
			// {
			// 	if (this == &rhs) return(*this);
        	// 	this->~RBTreeIter();
        	// 	return *new(this) RBTreeIter(rhs);
			// }
			map_pointer		base() const {
				return (this->_current);
			}
			bool operator==(const RBTreeIter & rhs) { return (_current == rhs._current); }
			bool operator!=(const RBTreeIter & rhs) { return (_current != rhs._current); }
			// bool operator==(const ConstRBTreeIter<T, M> & rhs) { return (_current == rhs._current); }
			// bool operator!=(const ConstRBTreeIter<T, M> & rhs) { return (_current != rhs._current); }
			T *operator*() { return(&(_current->_data)); }
			T *operator->() { return(&(_current->_data)); }

			RBTreeIter &operator++()
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

			RBTreeIter &operator--()
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

			RBTreeIter operator++(int)
			{
				RBTreeIter tmp(*this);
				++(*this);
				return (tmp);
			}

			RBTreeIter operator--(int)
			{
				RBTreeIter tmp(*this);
				--(*this);
				return (*this);
			}
	};


}
#endif