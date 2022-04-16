/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:48:20 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/16 20:19:04 by abarchil         ###   ########.fr       */
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
			Iterator( void )
			{
				this->_it = nullptr;
			}
			Iterator(difference_type element)
			{
				this->_it = element;
			}
			Iterator_Type	base( void )
			{
				return (this->_it);
			}
			Iterator	operator+(difference_type _n) const
			{
				return (Iterator(this->_it + _n));
			}
			Iterator	operator-(difference_type _n) const
			{
				return (Iterator(this->_it - _n));
			}
			Iterator&	operator+=(difference_type _n)
			{
				this->_it += _n;
				return (*this);
			}
			Iterator&	operator-=(difference_type _n)
			{
				this->_it -= _n;
				return (*this);
			}
	};
}