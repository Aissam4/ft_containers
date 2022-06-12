/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:48:20 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/12 16:51:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
# include "iterator_traits.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
namespace ft
{
	template<class T>
	class Iterator
	{
		private:
			T	_it;
		public:
			typedef	T														Iterator_Type;
			typedef typename	ft::iterator_traits<T>::value_type			value_type;
			typedef 			std::random_access_iterator_tag		 		iterator_Tag;
			typedef	typename	ft::iterator_traits<T>::difference_type	difference_type;
			typedef	typename	ft::iterator_traits<T>::pointer			pointer;
			typedef	typename	ft::iterator_traits<T>::reference			reference;
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
			Iterator_Type	base( void ) const
			{
				return (this->_it);
			}
			Iterator&	operator+=(difference_type _n)
			{
				this->_it += _n;
				return (*this);
			}
			Iterator	operator-(difference_type _n)
			{
				return (Iterator(this->_it - _n));
			}
			Iterator	operator+(difference_type _n)
			{
				return (Iterator(this->_it + _n));
			}
			 friend difference_type operator-(const Iterator& lhs, const Iterator& rhs) {
   			 	return lhs._it - rhs._it;
 			 }
			 friend difference_type operator+(const Iterator& lhs, const Iterator& rhs) {
   			 	return lhs._it + rhs._it;
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
				Iterator	obj(*this);
				++(*this);
				return (obj);
			}
			Iterator	operator--( int )
			{
				Iterator	obj(*this);
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
