/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseMapIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:29:03 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/19 01:32:07 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSEMAPITERATOR_HPP__
#define __REVERSEMAPITERATOR_HPP__

#include "mapIterator.hpp"

namespace ft
{
	template < typename MapIterator >
	class ReverseMapIterator : public MapIterator
	{
		public:
			using typename MapIterator::value_type;
			using typename MapIterator::pointer;
			using typename MapIterator::const_pointer;
			using typename MapIterator::reference;
			using typename MapIterator::const_reference;

			ReverseMapIterator() : MapIterator() {}
			template<class Ts>
			ReverseMapIterator(ReverseMapIterator<Ts> const &rhs) : MapIterator(rhs) {}
			ReverseMapIterator(MapIterator const &rhs) : MapIterator(rhs) {}
			~ReverseMapIterator() {}

			ReverseMapIterator &operator=( ReverseMapIterator const &rhs )
			{
				if (this == &rhs) return(*this);
				this->~ReverseMapIterator();
				return *new(this) ReverseMapIterator(rhs);
			}

			ReverseMapIterator &operator++()
			{
				MapIterator::operator--();
				return(*this);
			}

			ReverseMapIterator operator++(int)
			{
				ReverseMapIterator tmp(*this);
				MapIterator::operator--(0);
				return(tmp);
			}

			virtual ReverseMapIterator &operator--()
			{
				MapIterator::operator++();
				return(*this);
			}
			virtual ReverseMapIterator operator--(int)
			{
				ReverseMapIterator tmp(*this);
				MapIterator::operator++(0);
				return(tmp);
			}
	};		
}
#endif