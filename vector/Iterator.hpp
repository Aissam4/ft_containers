/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:48:20 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/16 20:00:38 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Vector.hpp"

namespace ft
{
	template<class T>
	class Iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T	_it;
		public:
			typedef	T														Iterator_Type;
			typedef typename	std::iterator_traits<T>::value_type			value_type;
			typedef 			std::random_access_iterator_tag		 		iterator_Tag;
			typedef	typename	std::iterator_traits<T>::difference_type	difference_type;
			typedef	typename	std::iterator_traits<T>::pointer			pointer;
			typedef	typename	std::iterator_traits<T>::reference			reference;
			Iterator()
			{
				this->_it = nullptr;
			}
	
	};
}