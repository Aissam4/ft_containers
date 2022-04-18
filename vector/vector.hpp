/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:55:10 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/18 16:38:27 by abarchil         ###   ########.fr       */
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
            T*					_vector;
            unsigned int		_capacity;
			unsigned int		_elementNumber;
			std::allocator<T>	alloc;
		public:
			typedef Allocator													allocator_type;
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			typedef	typename	ft::Iterator<pointer>								iterator;
			typedef	typename	ft::Iterator<const_pointer>							const_iterator;
			
			vector()
			{
				this->_vector = this->alloc.allocate(1);
				this->_capacity = 1;
				this->_elementNumber = 0;
			}
			vector(int capacity)
			{
				this->_vector = this->alloc.allocate(capacity);
				this->_capacity = capacity;
				this->_elementNumber = 0;
			}
			vector(const vector &obj)
			{
				*this = obj;
			}
			~vector()
			{
				for(unsigned int i = 0; i < this->_elementNumber; i++)
					this->alloc.destroy(&this->_vector[i]);
				// this->_elementNumber = 0;
			}
			T	at(unsigned int index) const
			{
				if (index > this->_capacity)
					throw vector::out_of_range();
				else
					return (this->_vector[index]);
			}
			void	push_back(T element)
			{
				if (this->_elementNumber + 1 == this->_capacity)
				{
					unsigned int i = 0;
					T*	_vec2 = this->alloc.allocate(this->_capacity * 2);
					for(; i < this->_capacity; i++)
						_vec2[i] = this->_vector[i];
					_vec2[i] = element;
					this->alloc.deallocate(this->_vector, this->_capacity);
					this->_elementNumber++;
					this->_capacity *= 2;
					this->_vector  = this->alloc.allocate(this->_capacity);
					i = 0;
					for(; i < this->_elementNumber; i++)
						this->_vector[i] = _vec2[i];
					this->alloc.deallocate(_vec2, this->_capacity);
				}
				else{
					this->_vector[this->_elementNumber] = element;
					this->_elementNumber++;
				}
			}
			void	pop_back( void )
			{
				this->alloc.destroy(this->_vector + this->_elementNumber);
				this->_elementNumber--;
			}
			void 	reserve(unsigned int n)
			{
				if (n > this->_capacity)
				{
					T*	_vec2 = this->alloc.allocate(n);
					for(unsigned int i = 0; i < this->_elementNumber; i++)
						_vec2[i] = this->_vector[i];
					this->alloc.deallocate(this->_vector, this->_capacity);
					this->_vector = this->alloc.allocate(n);
					for(unsigned int i = 0; i < this->_elementNumber; i++)
						this->_vector[i] = _vec2[i];
					this->_capacity = n;
					this->alloc.deallocate(_vec2, this->_capacity);
				}
			}
			void	print( void )
			{
				for (unsigned int i = 0; i < this->_elementNumber; i++)
					std::cout << "[" << this->_vector[i] << "]" << std::endl;
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
			const_iterator	begin( void ) const
			{
				return (const_iterator(this->_vector));
			}
			const_iterator	end( void ) const
			{
				return (const_iterator(this->_vector) + this->_elementNumber);
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