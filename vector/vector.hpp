/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:55:10 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/17 23:22:28 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP
# define __VECTOR_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <limits>
# include <vector>
# include <iterator>
# include <cstddef>
# include "Iterator.hpp"


namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        private:
            T*				_vector;
            unsigned int	_capacity;
			unsigned int	_elementNumber;
		public:
			typedef Allocator													allocator_type;
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			typedef	typename	ft::Iterator<pointer>								iterator;
			typedef	typename	ft::Iterator<const_pointer>							const_iterator;
			
			vector()
			{
				std::allocator<T> alloc;
				this->_vector = alloc.allocate(1);
				this->_capacity = 1;
				this->_elementNumber = 0;
			}
			vector(int capacity)
			{
				std::allocator<T> alloc;
				this->_vector = alloc.allocate(capacity);
				//for test
				// this->_vector[0] = "Hello";
				// this->_vector[1] = "world";
				this->_capacity = capacity;
				this->_elementNumber = 0;
			}
			vector(const vector &obj)
			{
				*this = obj;
			}
			~vector()
			{
				delete this->_vector;
				this->_vector = nullptr;
			};
			T	at(unsigned int index) const
			{
				if (index > this->_capacity)
					throw vector::out_of_range();
				else
					return (this->_vector[index]);
			}
			bool	empty( void ) const
			{
				return (!this->_elementNumber);
			}
			
			/**** ITERATORS ****/
			iterator	begin( void )
			{
				return (iterator(this->_vector));
			}
			iterator	end( void )
			{
				return (iterator(this->_vector) + this->_elementNumber);
			}
			T&	back( void )
			{
				return (this->_vector[this->_elementNumber]);
			}
			T&	front( void )
			{
				return (this->_vector[0]);
			}
			int	size( void ) const
			{
				return (this->_elementNumber);
			}
			unsigned int capacity() const
			{
				return (this->_capacity);
			}
			/***** operators *******/
			vector & operator=(const vector &obj)
			{
				if (this != &obj)
				{
					delete[] this->_vector;
					for (unsigned int i = 0; i < this->_elementNumber; i++)
						this->_vector[i] = obj._vector[i];
					this->_capacity = obj._capacity;
					this->_elementNumber = obj._elementNumber;
				}
				return *this;
			}
			vector & operator[](unsigned int n)
			{
				return (this->_vector[n]);
			}
			class out_of_range : public std::exception
			{
				public:
				virtual const char *what( void ) const throw()
				{
					return ("Index out of range");
				}
			};
    };
}
#endif