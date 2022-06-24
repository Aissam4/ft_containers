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


#ifndef __MAPITERATOR_HPP__
#define __MAPITERATOR_HPP__

#include <cstddef>
namespace ft
{
	template < class T, class M >
	class MapIterator
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

			~MapIterator() {}
			MapIterator() : _current(NULL) {}
			MapIterator(MapIterator const &rhs) : _current(rhs._current) {}
			MapIterator(map_pointer current) : _current(current) {}

			MapIterator &operator=(MapIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~MapIterator();
        		return *new(this) MapIterator(rhs);
			}

			bool operator==(const MapIterator & rhs) { return (_current == rhs._current); }
			bool operator!=(const MapIterator & rhs) { return (_current != rhs._current); }
			T *operator*() { return(&(_current->value)); }
			T *operator->() { return(&(_current->value)); }

			MapIterator &operator++()
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

			MapIterator &operator--()
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

			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				--(*this);
				return (*this);
			}
	};


}
#endif