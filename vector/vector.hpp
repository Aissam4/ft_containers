/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:55:10 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/13 15:34:40 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP
#define __VECTOR_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <limits>

namespace ft
{
    template <typename T>
    class vector
    {
        private:
            T	*_vector;
            int	_capacity;
			int	_elementNumber;
		public:
			vector()
			{
				this->_vector = new T[1];
				//TODO: use allocator instead of new
				this->_capacity = 1;
				this->_elementNumber = 0;
			}
			vector(int capacity)
			{
				this->_vector = new T[capacity];
				//TODO: use allocator instead of new
				this->_capacity = capacity;
				this->_elementNumber = 0;
			}
			vector(const vector<T> &obj)
			{
				*this = obj;
			}
			~vector();
			T	get(int index) const
			{
				if (index < this->_elementNumber)
					return (this->_vector[index]);
				//TODO: throw an expetion or error
			}
			int	size( void ) const
			{
				return (this->_elementNumber);
			}
			unsigned int capacity() const
			{
				return (this->_capacity);
			}
			vector<T> & operator=(const vector<T> &);
    };
    
}
#endif