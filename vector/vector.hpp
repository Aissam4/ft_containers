/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:55:10 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/13 15:14:49 by abarchil         ###   ########.fr       */
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
            T	_vector;
            int	_capacity;
			int	_elementNumber;
		public:
		vector();
		vector(int capacity);
		vector(const vector &obj);
		~vector();
            
    };
    
}
#endif