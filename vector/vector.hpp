/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:55:10 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/14 13:00:47 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP
# define __VECTOR_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <limits>
# include <vector>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        private:
            T				*_vector;
            unsigned int	_capacity;
			unsigned int	_elementNumber;
		public:
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
			/**** ITERATORS ****/
			T&	back()
			{
				return (this->_vector[this->_elementNumber]);
			}
			T&	front()
			{
				return (this->_vector[0]);
			}
			T*	begin()
			{
				return (this->_vector);
			}
			const T*	cbegin()
			{
				return this->_vector;
			}
			T*	end()
			{
				return this->_vector + this->_elementNumber;
			}
			const T*	cend()
			{
				return this->_vector + this->_elementNumber;
			}
			T*	rbegin()
			{
				return(this->_vector->begin());
			}
			T*	rend()
			{
				return(this->_vector->end() - 1);
			}
			
			unsigned int capacity(void)
			{
				return (this->_capacity);
			}
			int	size( void ) const
			{
				return (this->_elementNumber);
			}
			unsigned int capacity() const
			{
				return (this->_capacity);
			}
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
			/**** Exeption class *****/
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