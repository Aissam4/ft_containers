/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseSetIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:29:03 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/25 00:02:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSESetITERATOR_HPP__
#define __REVERSESetITERATOR_HPP__

#include "setIterator.hpp"

namespace ft
{
	template < typename SetIterator >
	class ReverseSetIterator : public SetIterator
	{
		public:
			using typename SetIterator::value_type;
			using typename SetIterator::pointer;
			using typename SetIterator::const_pointer;
			using typename SetIterator::reference;
			using typename SetIterator::const_reference;

			ReverseSetIterator() : SetIterator() {}
			template<class Ts>
			ReverseSetIterator(ReverseSetIterator<Ts> const &rhs) : SetIterator(rhs) {}
			ReverseSetIterator(SetIterator const &rhs) : SetIterator(rhs) {}
			~ReverseSetIterator() {}

			ReverseSetIterator &operator=( ReverseSetIterator const &rhs )
			{
				if (this == &rhs) return(*this);
				this->~ReverseSetIterator();
				return *new(this) ReverseSetIterator(rhs);
			}

			ReverseSetIterator &operator++()
			{
				SetIterator::operator--();
				return(*this);
			}

			ReverseSetIterator operator++(int)
			{
				ReverseSetIterator tmp(*this);
				SetIterator::operator--(0);
				return(tmp);
			}

			virtual ReverseSetIterator &operator--()
			{
				SetIterator::operator++();
				return(*this);
			}
			virtual ReverseSetIterator operator--(int)
			{
				ReverseSetIterator tmp(*this);
				SetIterator::operator++(0);
				return(tmp);
			}
	};		
}
#endif