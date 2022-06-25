/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:53 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/19 01:33:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __SETITERATOR_HPP__
#define __SETITERATOR_HPP__

#include <cstddef>
namespace ft
{
	template < class T, class M >
	class SetIterator
	{
		public:
			typedef M map_type;
			typedef map_type* map_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;
			map_pointer _current;

			~SetIterator() {}
			SetIterator() : _current(NULL) {}
			SetIterator(SetIterator const &rhs) : _current(rhs._current) {}
			SetIterator(map_pointer current) : _current(current) {}

			SetIterator &operator=(SetIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~SetIterator();
        		return *new(this) SetIterator(rhs);
			}

			bool operator==(const SetIterator & rhs) { return (_current == rhs._current); }
			bool operator!=(const SetIterator & rhs) { return (_current != rhs._current); }
			T *operator*() { return(&(_current->value)); }
			T *operator->() { return(&(_current->value)); }

			SetIterator &operator++()
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

			SetIterator &operator--()
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

			SetIterator operator++(int)
			{
				SetIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			SetIterator operator--(int)
			{
				SetIterator tmp(*this);
				--(*this);
				return (*this);
			}
	};


}
#endif