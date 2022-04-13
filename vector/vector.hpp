/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:55:10 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/13 15:26:24 by abarchil         ###   ########.fr       */
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
				this->_capacity = 1;
				this->_elementNumber = 0;
			}
			vector(int capacity)
			{
				this->_vector = new T[capacity];
				this->_capacity = capacity;
				this->_elementNumber = 0;
			}
			vector(const vector &obj)
			{
				*this = obj;
			}
			~vector();
			T	get(int index)
			{
				if (index < this->_elementNumber)
					return (this->_vector[index]);
				//TODO: throw an expetion or error
			}
			int	size( void )
			{
				return (this->_elementNumber);
			}
    };
    
}
#endif