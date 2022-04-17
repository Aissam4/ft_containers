/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:48:20 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/17 23:13:55 by abarchil         ###   ########.fr       */
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
			Iterator(Iterator_Type element)
			{
				this->_it = element;
			}
			template<class Iter>
			Iterator(const Iterator<Iter>	&obj)
			{
				this->_it = obj.base();
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
			Iterator&	operator++( void )
			{
				++this->_it;
				return (*this);
			}
			Iterator&	operator--( void )
			{
				--this->_it;
				return (*this);
			}
			Iterator	operator++( int )
			{
				Iterator_Type	obj(*this);
				++(*this);
				return (obj);
			}
			Iterator	operator--( int )
			{
				Iterator_Type	obj(*this);
				--(*this);
				return (obj);
			}
			reference	operator*() const
			{
				return (*this->_it);
			}
			pointer		operator->()
			{
				return (&(operator*()));
			}
			reference	operator[](difference_type n)
			{
				return (*(this->_it + n));
			}
	};
	template <class F_Iterator, class S_Iterator>
		bool	operator==(const Iterator<F_Iterator> &F, const Iterator<S_Iterator> &S)
		{
			return (F.base() == S.base());
		}
	template <class F_Iterator, class S_Iterator>
		bool	operator>(const Iterator<F_Iterator> &F, const Iterator<S_Iterator> &S)
		{
			return (F.base() > S.base());
		}
	template <class F_Iterator, class S_Iterator>
		bool	operator<(const Iterator<F_Iterator> &F, const Iterator<S_Iterator> &S)
		{
			return (F.base() < S.base());
		}
	template <class F_Iterator, class S_Iterator>
		bool	operator<=(const Iterator<F_Iterator> &F, const Iterator<S_Iterator> &S)
		{
			return (F.base() <= S.base());
		}
	template <class F_Iterator, class S_Iterator>
		bool	operator>=(const Iterator<F_Iterator> &F, const Iterator<S_Iterator> &S)
		{
			return (F.base() >= S.base());
		}
	template <class F_Iterator, class S_Iterator>
		bool	operator!=(const Iterator<F_Iterator> &F, const Iterator<S_Iterator> &S)
		{
			return (F.base() != S.base());
		}	
}
